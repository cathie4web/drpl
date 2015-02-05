<?php

/**
 * @file
 * Administration forms for the LikeBtn module.
 */

/**
 * Menu callback; Displays the administration settings for LikeBtn.
 */
function add_func_likebtn_general_settings() {
	$public_url = _add_func_likebtn_public_url();

	drupal_add_js( drupal_get_path( 'module', 'add_func_likebtn' ) . "/js/admin.js", 'file' );

	$form = array();

	// Get all available content types.
	$types = node_type_get_types();
	$options = array();
	foreach ( $types as $type ) {
		$options[ $type->type ] = $type->name;
	}

	// Get all available entities view modes.
	$view_modes = entity_get_info( 'node' );
	foreach ( $view_modes['view modes'] as $view_mode_id => $view_mode_info ) {
		$view_modes_options[$view_mode_id] = $view_mode_info['label'];
	}

	$form['add_func_likebtn_general_display_options'] = array(
		'#type'				=> 'fieldset',
		'#title'			=> t( 'General display options' ),
		'#collapsible'		=> FALSE,
		'#collapsed'		=> FALSE,
	);

	$form['add_func_likebtn_general_display_options']['add_func_likebtn_hint'] = array(
		'#type'				=> 'item',
		'#description'		=> t( 'You can set up the Like Button globally on this page, or per content type as a field in <a href="@link-manage_fields">Structure » Content types » Manage fields</a>.' ),
	);

	$form['add_func_likebtn_general_display_options']['add_func_likebtn_nodetypes'] = array(
		'#type'				=> 'checkboxes',
		'#title'			=> t( 'Enable for the following content types' ),
		'#description'		=> t( 'Select the content types for which you want to activate like button.' ),
		'#default_value'	=> variable_get( 'add_func_likebtn_nodetypes', array(
				'article'	=> 'article',
				'page'		=> 'page',
		) ),
		'#options'			 => $options,
	);

	$form['add_func_likebtn_general_display_options']['add_func_likebtn_comments_nodetypes'] = array(
		'#type'				=> 'checkboxes',
		'#title'			=> t( 'Enable for comments to the following content types' ),
		'#description'		=> t( 'Select the content types for comments to which you want to activate like button.' ),
		'#default_value'	=> variable_get( 'add_func_likebtn_comments_nodetypes', array() ),
		'#options'			=> $options,
		'#disabled'			=> !module_exists( 'comment' ),
	);

	$form['add_func_likebtn_general_display_options']['add_func_likebtn_view_modes'] = array(
		'#type'				=> 'checkboxes',
		'#title'			=> t( 'Entities view modes' ),
		'#description'		=> t( 'When will the like button be displayed?' ),
		'#default_value'	=> variable_get( 'add_func_likebtn_view_modes', array(
				'full'		=> 'full',
				'teaser'	=> 'teaser',
		) ),
		'#options'			=> $view_modes_options,
	);

	$form['add_func_likebtn_general_display_options']['add_func_likebtn_weight'] = array(
		'#type'				=> 'select',
		'#title'			=> t( 'Position' ),
		'#description'		=> t( 'The more the weight, the lower like button position in the entity.' ),
		'#default_value'	=> variable_get( 'add_func_likebtn_weight', 10 ),
		'#options'			=> array(
			-100			=> '-100',
			-50				=> '-50',
			-20				=> '-20',
			-10				=> '-10',
			-5				=> '-5',
			5				=> '5',
			10				=> '10',
			20				=> '20',
			50				=> '50',
			100				=> '100',
		),
	);

	$form['add_func_likebtn_general_display_options']['add_func_likebtn_user_logged_in'] = array(
		'#type'				=> 'select',
		'#title'			=> t( 'User authorization' ),
		'#description'		=> t( 'Show the Like Button when user is logged in, not logged in or show for all.' ),
		'#default_value'	=> variable_get( 'add_func_likebtn_user_logged_in', 'all' ),
		'#options'			=> array(
			'all'			=> t( 'For all' ),
			'logged_in'		=> t( 'Logged in' ),
			'not_logged_in'	=> t( 'Not logged in' ),
		),
	);

	/*$form['add_func_likebtn_domain_subdirectory'] = array(
		'#type'				=> 'fieldset',
		'#title'			=> t('Domain and subdirectory'),
		'#collapsible'		=> TRUE,
		'#collapsed'		=> TRUE,
	);

	$form['add_func_likebtn_domain_subdirectory']['add_func_likebtn_settings_local_domain'] = array(
		'#type'				=> 'textfield',
		'#title'			=> t('Local domain'),
		'#description'		=> t('Example:') . ' localdomain!50f358d30acf358d30ac000001. ' . t('Specify it if your website is located on a local server and is available from your local network only and NOT available from the Internet. You can find the domain on your <a href="http://likebtn.com/en/customer.php/websites" target="_blank">Websites</a> page after adding your local website to the panel. See <a href="http://likebtn.com/en/faq#local_domain" target="_blank">FAQ</a> for more details.'),
		'#default_value'	=> variable_get('add_func_likebtn_settings_local_domain', ''),
	);

	$form['add_func_likebtn_domain_subdirectory']['add_func_likebtn_settings_subdirectory'] = array(
		'#type'				=> 'textfield',
		'#title'			=> t('Website subdirectory'),
		'#description'		=> t('If your website is one of websites located in different subdirectories of one domain and you want to have a statistics separate from other websites on this domain, enter subdirectory (for example /subdirectory/).'),
		'#default_value'	=> variable_get('add_func_likebtn_settings_subdirectory', ''),
	); */

	return system_settings_form( $form );
}

/**
 * Menu callback; Displays the administration settings for LikeBtn.
 */
function add_func_likebtn_settings() {
	return system_settings_form( _add_func_likebtn_settings_form() );
}