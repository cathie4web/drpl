<?php

/**
 * Helper function to build a follow links element.
 *
 * @param array $links
 * An array of follow links.
 * @param array $networks
 * An array of networks.
 * @param string $type
 * The type of follow links, user or site.
 * @param string $alignment
 * The alignment, horizontal or vertical.
 */
function _add_func_follow_links_element( array $links, array $networks, $alignment = NULL ) {
	$element['add-func-follow-links']['#prefix'] = "<div class='add-func-follow-links clearfix'>";

	if ( !isset( $alignment ) ) {
		$alignment = variable_get( "add_func_follow_alignment", 'vertical' );
	}
	
	if ( !isset( $label ) ) {
		$label = variable_get( "add_func_follow_label", FALSE );
	}

	$wrapper = $alignment == 'horizontal' ? 'span' : 'div';

	foreach ( $links as $link ) {
		if ( $label ) {
			$title = !empty( $link->title ) ? $link->title : $networks[ $link->name ]['title'];
			$class = "with-label";
		} else {
			$title = '';
			$class = "without-label";

		}

		$element['add-func-follow-links'][ $link->name ] = array(
			'#prefix' => "<{$wrapper} class='add-func-follow-link-wrapper add-func-follow-link-wrapper-{$link->name} {$class}'>",
			'#theme' => 'add_func_follow_link',
			'#link' => $link,
			'#title' => $title,
			'#suffix' => "</{$wrapper}>",
		);
	}

	$element['add-func-follow-links']['#suffix'] = '</div>';

	return $element;
}

/**
 * Like drupal_http_build_query() but without urlencodings.
 */
function add_func_follow_build_query( array $query, $parent = '' ) {
	$params = array();

	foreach ( $query as $key => $value ) {
		$key = ( $parent ? $parent . '[' . $key . ']' : $key );

		// Recurse into children.
		if ( is_array( $value ) ) {
			$params[] = add_func_follow_build_query( $value, $key );
		}
		// If a query parameter value is NULL, only append its key.
		elseif ( !isset( $value ) ) {
			$params[] = $key;
		}
		else {
			$params[] = $key . '=' . $value;
		}
	}
	return implode( '&', $params );
}

/**
 * Build a url for use in the form.
 */
function add_func_follow_build_url( $path, $options ) {
	$url = $path;
	if ( !empty( $options['query'] ) ) {
		$url .= ( strpos( $path, '?' ) !== FALSE ? '&' : '?' ) . add_func_follow_build_query( $options['query'] );
	}
	if ( !empty( $options['fragment'] ) ) {
		$url .= '#' . $options['fragment'];
	}
	return $url;
}

/**
 * Split a Drupal path or external link into path and options like a menu link.
 */
function add_func_follow_parse_url( $url ) {
	$parsed_url = parse_url( $url );
	$defaults = array(
		'scheme' => '',
		'host' => '',
		'port' => '',
		'path' => '/',
		'query' => '',
		'fragment' => '',
	);
	$parsed_url += $defaults;
	$options = array( 'query' => array(), 'fragment' => $parsed_url['fragment'] );
	// Parse the query string into an array.
	parse_str( $parsed_url['query'], $options['query'] );
	if ( $parsed_url['scheme'] ) {
		$parsed_url['scheme'] .= '://';
	}
	// Throw away port for now.
	$path = $parsed_url['scheme'] . $parsed_url['host'] . $parsed_url['path'];
	return array( 'path' => $path, 'options' => $options );
}

/**
 * Validates the url field to verify it's actually a url.
 */
function add_func_follow_url_validate( $form ) {
	$url = trim( $form['#value'] );
	$networks = add_func_follow_networks_load( $form['#add_func_follow_uid'] );
	$info = $networks[ $form['#add_func_follow_network'] ];
	$regex = add_func_follow_build_url_regex( $info );
	$parsed = add_func_follow_parse_url( $url );
	if( $url && !preg_match( $regex, $parsed['path'] ) ) {
		if ( !empty( $info['domain'] ) ) {
			$message = t( 'The specified url is invalid for the domain %domain. Make sure you use http://.', array( '%domain' => $info['domain'] ) );
		}
		else {
			$message = t( 'The specified path is invalid. Please enter a path on this site (e.g. rss.xml or taxonomy/term/1/feed).' );
		}
		form_error( $form, $message );
	}
}

/**
 * Build a regex to validate the url based on a known service url.
 */
function add_func_follow_build_url_regex( $network_info ) {

	if ( !empty( $network_info['domain'] ) ) {
		// An external link.
		return '@^https?://([a-z0-9\-_.]+\\.|)' . str_replace( '.', '\\.', $network_info['domain'] ) . '/@i';
	}
	// An internal link should not have ':'.
	return '@^[^:]+$@';
}

/**
 * Loader function for individual links.
 *
 * @param $uid
 *	 An int containing the uid of the user. uid 0 pulls the site follow links.
 * @return
 *	 A single link in array format, or FALSE if none matched the incoming ID.
 */
function add_func_follow_links_load( $uid = 0 ) {
	$links = array();

	$sql = "SELECT * FROM {add_func_follow_links} WHERE uid = :uid ORDER BY weight ASC";
	$result = db_query( $sql, array( ':uid' => $uid ) );

	foreach ( $result as $link ) {
		$link->options = unserialize( $link->options );
		$link->url = add_func_follow_build_url( $link->path, $link->options );
		$links[ $link->name ] = $link;
	}

	return $links;
}

/**
 * Inserts a new link, or updates an existing one.
 *
 * @param $link
 *	 A link object to be saved.
 */
function add_func_follow_link_save( $link ) {
	$parsed = add_func_follow_parse_url( $link->url );
	$link->path = $parsed['path'];
	$link->options = $parsed['options'];

	if ( isset( $link->lid ) ) {
		drupal_write_record( 'add_func_follow_links', $link, 'lid' );
	}
	else {
		drupal_write_record( 'add_func_follow_links', $link );
	}
	return $link;
}

/**
 * Deletes a link, given its unique ID.
 *
 * @param $lid
 *	 An int containing the ID of a link.
 */
function add_func_follow_link_delete( $lid ) {
	db_delete( 'add_func_follow_links' )
		->condition( 'lid', $lid )
		->execute();
}

/**
 * Loads all follow networks
 *
 * @param $uid
 *	 The uid of the user. uid 0 pulls the site follow links.
 * @param $reset
 *	 Boolean.	If TRUE, flushes the follow networks cache.
 *
 * @return
 *	 An array of network names, keys are machine names, values are visible titles.
 */
function add_func_follow_networks_load( $uid = 0, $reset = FALSE ) {
	$networks = &drupal_static( __FUNCTION__, array() );

	// Clear cache if $reset is TRUE;
	if ( $reset ) {
		$networks = array();
	}
	// Return presets if the array is populated.
	if ( empty( $networks[ $uid ] ) ) {
		// We call hook_add_func_follow_networks_alter() to allow other modules to create
		// or alter networks.
		$networks[ $uid ] = add_func_follow_default_networks( $uid );
		drupal_alter( 'add_func_follow_networks', $networks, $uid );
	}

	return $networks[ $uid ];
}

/**
 * Retrieves the default networks available.
 *
 * @return
 *	 An associative array, keyed by the machine name. The values are an array
 *	 including title of the network, along with the domain to be used for
 *	 input validation of the network.
 */
function add_func_follow_default_networks( $uid ) {
	$networks = array(
		'delicious'	=> array(
			'title' => t( 'Delicious' ),
			'domain' => 'delicious.com',
		),
		'digg'	=> array(
			'title' => t( 'Digg' ),
			'domain' => 'digg.com',
		),
		'dribbble'	=> array(
			'title' => t( 'Dribbble' ),
			'domain' => 'dribbble.com',
		),
		'facebook'	=> array(
			'title' => t( 'Facebook' ),
			'domain' => 'facebook.com',
		),
		'flickr'		=> array(
			'title' => t( 'Flickr' ),
			'domain' => 'flickr.com',
		),
		'github'		=> array(
			'title' => t( 'Github' ),
			'domain' => 'github.com',
		),
		'googleplus'		=> array(
			'title' => t( 'Google+' ),
			'domain' => 'plus.google.com',
		),
		'instagram'		=> array(
			'title' => t( 'Instagram' ),
			'domain' => 'instagram.com',
		),
		'linkedin'	=> array(
			'title' => t( 'LinkedIn' ),
			'domain' => 'linkedin.com',
		),
		'pinterest'	=> array(
			'title' => t( 'Pinterest' ),
			'domain' => 'pinterest.com',
		),
		'reddit'	=> array(
			'title' => t( 'Reddit' ),
			'domain' => 'reddit.com',
		),
		'tumblr'		=> array(
			'title' => t( 'Tumblr' ),
			'domain' => 'tumblr.com',
		),
		'twitter'	 => array(
			'title' => t( 'Twitter' ),
			'domain' => 'twitter.com',
		),
		'vimeo'		 => array(
			'title' => t( 'Vimeo' ),
			'domain' => 'vimeo.com',
		),
		'weibo'		 => array(
			'title' => t( 'Weibo' ),
			'domain' => 'weibo.com',
		),
		'wordpress'	 => array(
			'title' => t( 'Wordpress' ),
			'domain' => 'wordpress.com',
		),
		'youtube'	 => array(
			'title' => t( 'YouTube' ),
			'domain' => 'youtube.com',
		),
		'xing'		=> array(
			'title' => t( 'Xing' ),
			'domain' => 'xing.com',
		),
		'rss'		=> array(
			'title' => t( 'RSS' ),
			'domain' => '',
		),
	);

	return $networks;
}