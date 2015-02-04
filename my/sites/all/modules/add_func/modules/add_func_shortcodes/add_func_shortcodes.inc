<?php

/**
* Implementation of hook_shortcode_info().
* Using same formatting as hook_filter_info()
*/

function add_func_shortcodes_init() {
	$inline_script = '<script src="https://maps.googleapis.com/maps/api/js?v=3.exp&amp;sensor=false"></script>';
	$element = array(
		'#type' => 'markup',
		'#markup' => $inline_script,
	);
	drupal_add_html_head($element, 'google-maps');
}

function add_func_shortcodes_shortcode_info() {
	$shortcodes = array();

	$shortcodes['clear'] = array(
		'title' => t( 'Clear' ),
		'description' => t( 'Insert a float-clearing div for a proper layout.' ),
		'process callback' => 'add_func_shortcodes_clear',
		'tips callback' => 'add_func_shortcodes_clear_tips',
	);

	$shortcodes['col'] = array(
		'title' => t( 'Columns' ),
		'description' => t( 'Simple columns in content' ),
		'process callback' => 'add_func_shortcodes_columns',
		'tips callback' => 'add_func_shortcodes_columns_tips',
	);
	
	$shortcodes['counter'] = array(
		'title' => t('Counter'),
		'description' => t('Creates JS numeric counter'),
		'process callback' => 'add_func_shortcodes_counter',
		'tips callback' => 'add_func_shortcodes_counter_tips',
	);
	
	$shortcodes['dropcap'] = array(
		'title' => t( 'Dropcap' ),
		'description' => t( 'Dropcap shortcode' ),
		'process callback' => 'add_func_shortcodes_dropcap',
		'tips callback' => 'add_func_shortcodes_dropcap_tips',
	);
	
	$shortcodes['gmap'] = array(
		'title' => t('Google map'),
		'description' => t('Creates Google map'),
		'process callback' => 'add_func_shortcodes_gmap',
		'tips callback' => 'add_func_shortcodes_gmap_tips',
	);
	
	$shortcodes['container'] = array(
		'title' => t( 'Grid container' ),
		'description' => t( 'Grids wrapper' ),
		'process callback' => 'add_func_shortcodes_container',
		'tips callback' => 'add_func_shortcodes_container_tips',
	);
	
	$shortcodes['grid'] = array(
		'title' => t( 'Grid' ),
		'description' => t( 'Simple columns in content' ),
		'process callback' => 'add_func_shortcodes_grids',
		'tips callback' => 'add_func_shortcodes_grids_tips',
	);
	
	$shortcodes['highlight'] = array(
		'title' => t( 'Highlight' ),
		'description' => t( 'Highlight an inline text' ),
		'process callback' => 'add_func_shortcodes_highlight',
		'tips callback' => 'add_func_shortcodes_highlight_tips',
	);
	
	$shortcodes['icon'] = array(
		'title' => t('Icon'),
		'description' => t('Creates Font Awesome Icon shortcode'),
		'process callback' => 'add_func_shortcodes_icon',
		'tips callback' => 'add_func_shortcodes_icon_tips',
	);
	
	$shortcodes['message'] = array(
		'title' => t( 'Message Box' ),
		'description' => t( 'Creates message boxes' ),
		'process callback' => 'add_func_shortcodes_message',
		'tips callback' => 'add_func_shortcodes_message_tips',
	);
	
	$shortcodes['piegraph'] = array(
		'title' => t('Pie Graph'),
		'description' => t('Draws percer circle use HTML5 canvas'),
		'process callback' => 'add_func_shortcodes_piegraph',
		'tips callback' => 'add_func_shortcodes_piegraph_tips',
	);
	
	$shortcodes['progressbar'] = array(
		'title' => t('Progressbar'),
		'description' => t('Creates progressbar shortcode'),
		'process callback' => 'add_func_shortcodes_progressbar',
		'tips callback' => 'add_func_shortcodes_progressbar_tips',
	);
	
	
	
	

	/*$shortcodes['button'] = array(
		'title' => t( 'Button' ),
		'description' => t( 'creates a fancy button that links to somewhere.' ),
		'process callback' => 'add_func_shortcodes_button',
		'tips callback' => 'add_func_shortcodes_button_tips',
		'default settings' => array(),
		'attributes callback' => 'add_func_shortcodes_button_attributes',
	);

	$shortcodes['box'] = array(
		'title' => t( 'Box' ),
		'description' => t( 'Side-boxes, blockquotes and pullquotes' ),
		'process callback' => 'add_func_shortcodes_box',
		'tips callback' => 'add_func_shortcodes_box_tips',
		'default settings' => array(),
		'attributes callback' => 'add_func_shortcodes_box_attributes',
	);

	$shortcodes['divider'] = array(
		'title' => t( 'divider' ),
		'description' => t( 'divider' ),
		'process callback' => 'add_func_shortcodes_divider',
		'tips callback' => 'add_func_shortcodes_divider_tips',
		'default settings' => array(),
		'attributes callback' => 'add_func_shortcodes_divider_attributes',
	);

	$shortcodes['dropshadow'] = array(
		'title' => t( 'Drop Shadow' ),
		'description' => t( 'Add drop shadow to element' ),
		'process callback' => 'add_func_shortcodes_dropshadow',
		'tips callback' => 'add_func_shortcodes_dropshadow_tips',
		'default settings' => array(),
		'attributes callback' => 'add_func_shortcodes_dropshadow_attributes',
	);

	$shortcodes['social'] = array(
		'title' => t( 'Social links' ),
		'description' => t( 'List of icons and links to social networks' ),
		'process callback' => 'add_func_shortcodes_social',
		'tips callback' => 'add_func_shortcodes_social_tips',
		'default settings' => array(),
		'attributes callback' => 'add_func_shortcodes_social_attributes',
	);

	$shortcodes['contact'] = array(
		'title' => t( 'Contact information' ),
		'description' => t( 'Icon list of contact info' ),
		'process callback' => 'add_func_shortcodes_contact',
		'tips callback' => 'add_func_shortcodes_contact_tips',
		'default settings' => array(),
		'attributes callback' => 'add_func_shortcodes_contact_attributes',
	);

	$shortcodes['teaser'] = array(
		'title' => t( 'Teaser' ),
		'description' => t( 'creates an emphasized teaser paragraph.' ),
		'process callback' => 'add_func_shortcodes_teaser',
		'tips callback' => 'add_func_shortcodes_teaser_tips',
		'default settings' => array(),
	);

	$shortcodes['toggle'] = array(
		'title' => t( 'Toggle' ),
		'description' => t( 'JQuery toggle content' ),
		'process callback' => 'add_func_shortcodes_toggle',
		'tips callback' => 'add_func_shortcodes_toggle_tips',
		'default settings' => array(),
		'attributes callback' => 'add_func_shortcodes_toggle_attributes',
	);

	// $shortcodes['tabs'] = array(
	//	 'title' => t( 'Tabs & Accordeons' ),
	//	 'description' => t( 'JQuery toggle content' ),
	//	 'process callback' => 'add_func_shortcodes_tabs',
	//	 'tips callback' => 'add_func_shortcodes_tabs_tips',
	//	 'default settings' => array(),
	// );

	// $shortcodes['tab-item'] = array(
	//	 'title' => t( 'Tabs pane' ),
	//	 'description' => t( 'converts inner contents to a tab.' ),
	//	 'process callback' => 'add_func_shortcodes_tab_item',
	//	 'tips callback' => 'add_func_shortcodes_tab_item_tips',
	//	 'default settings' => array(),
	// );

	$shortcodes['icon-list'] = array(
		'title' => t( 'Icon list' ),
		'description' => t( 'Lists with icons. Supports ul, ol and dl.' ),
		'process callback' => 'add_func_shortcodes_icon_list',
		'tips callback' => 'add_func_shortcodes_icon_list_tips',
		'default settings' => array(),
	); */

	return $shortcodes;
}

/** @file shortcodes.php
 *
 * Shortcode defenitions
 */


/*============================================================================================*/
/* Clear
/*============================================================================================*/

function add_func_shortcodes_clear( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
		'class' => '',
		'style' => '',
		'id' => '',
		'type' => 'div',
	), $attrs ) );

	switch ( $attrs['type'] ) {
		case 'span':
			$type = 'span';
			break;
		default:
			$type = 'div';
			break;
	}
	
	$classes = 'clearfix';
	if ( $class ) {
		$classes .= ' ' . $class;
	}
	$output = '<' . $type . ' class="' . $classes . '">' . $content . '</' . $type . '>';
	
	return $output;
}

function add_func_shortcodes_clear_tips( $format, $long ) {
	$output = '[clear class="custom-class" type="div | span"]Content[/clear]';
	return $output;
}

/*============================================================================================*/
/* Columns
/*============================================================================================*/
function add_func_shortcodes_columns( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
		'width'			=> '',
		'align'			=> '',
		'last'			=> '',
		'clear'			=> '',
		'class'			=> '',
	), $attrs ) );

	$classes = array();
	if ( $width ) {
		$classes[] = 'col-' . $width;
	}
	if ( $align == 'right' ) {
		$classes[] = 'float-right';
	}
	if ( $align == 'center' ) {
		$classes[] = 'align-center';
	}
	if ( $last ) {
		$classes[] = 'col-last';
	}
	if ( $clear ) {
		$classes[] = 'clear-both';
	}
	if ( $class ) {
		$classes[] = $class;
	}

	$classes = trim( implode( ' ', $classes ) );
	
	$output = '<div class="' . $classes . '">' . $content . '</div>';

	return $output;
}

function add_func_shortcodes_columns_tips( $format, $long ) {
	$output = '[col width="1-2 | 1-3 | 2-3 | 1-4 | 3-4 | 1-5 | 2-5 | 3-5 | 4-5 | 1-6 | 5-6" align="right | center" clear="clear-both | clear-left | clear-right" last="1" class="custom-class"]your content[/col]';
	return $output;
}


/*============================================================================================*/
/* Counters
/*============================================================================================*/

function add_func_shortcodes_counter( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
		'number' => '',
		'timer' => '',
		'class' => '',
	), $attrs ) );

	$element_id = drupal_html_id("add_func_counter" . REQUEST_TIME);
	
	$classes = "counter";
	if ( $class ) {
		$classes = $classes . ' ' . $class;
	}

	$output = '<div id ="' . $element_id . '" class="' . $classes . '">';
		$output .= '<div data-num="' . $timer . '" data-content="' . $number . '" class="num">' . $number . '</div>';
		if ( $content ) {
			$output .= '<div class="title">' . $content . '</div>';
		}
	$output .= '</div>';

	return $output;
}

function add_func_shortcodes_counter_tips( $format, $long ) {
	$output = '[counter number="1 | 2 | .." timer="200" class="custom-class"]Title[/counter]';
	return $output;
}


/*============================================================================================*/
/* Dropcap
/*============================================================================================*/

function add_func_shortcodes_dropcap( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
		'class'				=> ''
	), $attrs ) );

	$classes = !empty( $class ) ? ' ' . $class : '';
	$output = '<span class="dropcap' . $classes . '">' . check_plain( $content ) . '</span>';
	return $output;
}

function add_func_shortcodes_dropcap_tips( $format, $long ) {
	$output = '[dropcap]Y[/dropcap]our content...';
	return $output;
}


/*============================================================================================*/
/* Google map
/*============================================================================================*/

function add_func_shortcodes_gmap( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
		'lat_coord'			=> '55.861263',
		'lng_coord'			=> '-4.251604',
		'zoom_value'		=> '15',
		'zoom_wheel'		=> 'no',
		'hue'				=> '',
		'saturation'		=> 0,
		'gamma'				=> 1,
		'marker'			=> '',
		'class'				=> ''
	), $attrs ) );

	$random_id	= rand();
	$lat_coord	= floatval( $lat_coord );
	$lng_coord	= floatval( $lng_coord );
	$zoom_value	= intval( $zoom_value );
	$zoom_wheel	= $zoom_wheel=='yes' ? 'true' : 'false';

	$output = '<div class="google-map-api ' . $class . '">';
		$output .= '<div id="map-canvas-' . $random_id . '" class="gmap"></div>';
	$output .= '</div>';
	$output .= '<script>
			google_api_map_init_' . $random_id . '();
			function google_api_map_init_' . $random_id . '(){
				var map;
				var coordData = new google.maps.LatLng(parseFloat(' . $lat_coord . '), parseFloat(' . $lng_coord . '));
				var marker;

				function initialize() {
					var mapOptions = {
						center: coordData,
						scrollwheel: ' . $zoom_wheel . ',
						styles: [ { "stylers": [ { "hue": "' . $hue . '" }, { "saturation": ' . $saturation . ' }, { "gamma": ' . $gamma . ' } ] } ],
						zoom: ' . $zoom_value . '
					}
					var map = new google.maps.Map(document.getElementById("map-canvas-' . $random_id . '"), mapOptions);
					marker = new google.maps.Marker({
						map: map,
						draggable: true,
						position: coordData,
						icon: "'. $marker .'"
					});
				}
				google.maps.event.addDomListener(window, "load", initialize);
			}
		</script>';

	return $output;
}

function add_func_shortcodes_gmap_tips( $format, $long ) {
	$output = '[gmap lat_coord="41.850033" lng_coord="-87.6500523" zoom_value="15" zoom_wheel="no" hue="#ffffff" saturation ="-100 | .. | 0 | .. | 100" gamma="0.01 | .. | 1.0 | .. | 10" marker="http://example.com/img.png" class="custom-class"][/gmap]';
	return $output;
}


/*============================================================================================*/
/* Grid Container
/*============================================================================================*/

function add_func_shortcodes_container( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
		'class' => '',
	), $attrs ) );
	
	$classes[] = 'container-12';
	
	if ( $class ) {
		$classes[] = $class;
	}
	
	$classes = trim( implode( ' ', $classes ) );

	$output = '<div class="' . $classes . '">' . $content . '</div>';

	return $output;
}

function add_func_shortcodes_container_tips( $format, $long ) {
	$output = '[container class="custom-class"]Grids[/container]';
	return $output;
}


/*============================================================================================*/
/* Grids
/*============================================================================================*/

function add_func_shortcodes_grids( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
		'width'			=> '',
		'clear'			=> '',
		'class'			=> '',
	), $attrs ) );

	$classes = array();
	if ( $width ) {
		$classes[] = 'grid-' . $width;
	}
	if ( $clear ) {
		$classes[] = $clear;
	}
	if ( $class ) {
		$classes[] = $class;
	}

	$classes = trim( implode( ' ', $classes ) );
	
	$output = '<div class="' . $classes . '">' . $content . '</div>';

	return $output;
}

function add_func_shortcodes_grids_tips( $format, $long ) {
	$output = '[grid width="1 | 2 | ... | 12" clear="clear-both | clear-left | clear-right" class="custom-class"]your content[/grid]';
	return $output;
}


/*============================================================================================*/
/* Highlighted
/*============================================================================================*/

function add_func_shortcodes_highlight( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
		'background'	=> '',
		'color'			=> '',
		'class'			=> '',
	), $attrs ) );

	$style = '';
	if ( $background ) {
		$style .= "background-color: $background;";
	}
	if ( $color ) {
		$style .= "color: $color;";
	}
	if ( $style ) {
		$style = ' style="' . $style . '"';
	}

	$classes = 'highlight';
	$classes .= !empty( $class ) ? ' ' . $class : '';

	return '<span class="' . $classes . '"' . $style . '>' . $content . '</span>';
}

function add_func_shortcodes_highlight_tips( $format, $long ) {
	$output = '[highlight background="yellow" color="black"]your text here[/highlight]';
	return $output;
}


/*============================================================================================*/
/* Font Awesome Icons
/*============================================================================================*/

function add_func_shortcodes_icon( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
		'link'				=> '',
		'class'				=> '',
	), $attrs ) );

	$classes = "fa " . $class;
	
	if ( $link == "" ) {
		$output = '<i class="' . $classes . '"></i> ' . $content;
	} else {
		$output = '<a href="' . $link . '"><i class="' . $classes . '"></i>' . $content . '</a>';
	}
	
	$output = trim( $output );

	return $output;
}

function add_func_shortcodes_icon_tips( $format, $long ) {
	$output = '[icon class="fa-star" link="http://drupal.org"]Some text here[/icon]';
	return $output;
}


/*============================================================================================*/
/* Message
/*============================================================================================*/

function add_func_shortcodes_message( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
		'type'			 => '',
		'class'			=> '',
	), $attrs ) );

	$classes = "messages";

	switch ( $type ) {
		case 'warning':
			$classes .= " warning";
			break;
		case 'error':
			$classes .= ' error';
			break;
		case 'success':
			$classes .= " status";
			break;
		case 'notice':
			$classes .= " notice";
			break;
		case 'question':
			$classes .= " question";
			break;
		case 'advice':
			$classes .= " advice";
			break;
	};

	$classes .= !empty( $class ) ? ' ' . $class : '';

	$output = '<div class="' . $classes . '">' . $content . "</div>";
	
	return $output;
}

function add_func_shortcodes_message_tips( $format, $long ) {
	$output = '[message type="warning | error | success | notice | question | advice"]your content here[/message]';
	return $output;
}


/*============================================================================================*/
/* Piegraphs
/*============================================================================================*/

function add_func_shortcodes_piegraph( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
		'barcolor'			=> '#119fe1',
		'linewidth' 		=> '3',
		'trackcolor'		=> '#cccccc',
		'percent'			=> '0',
		'width'				=> '200',
		'class'				=> '',
	), $attrs ) );
	
	$element_id = drupal_html_id( "add_func_piegraph" . REQUEST_TIME );
	
	$classes = 'piegraph-wrap';
	
	if ( $class ) {
		$classes = $classes . ' ' . $class;
	}
	
	$output = '<div class="' . $classes . '">';
		$output .= '<div class="piegraph-title">' . $content . '</div>';
		$output .= '<div class="piegraph" data-bar-color="' . $barcolor . '" data-track-color="' . $trackcolor . '" data-percent="' . $percent . '" data-line-width="' . $linewidth . '" data-size="' . $width . '"><span class="piegraph-percent"></span></div>';
	$output .= '</div>';

	return $output;
}

function add_func_shortcodes_piegraph_tips( $format, $long ) {
	$output = '[piegraph percent="0 | 1 | .. | 100" width="1 | ... | 200 | ..." barcolor="#21c2f8" trackcolor="#cccccc" linewidth="3" class="custom-class"]Title[/piegraph]';
	return $output;
}


/*============================================================================================*/
/* Progressbars
/*============================================================================================*/

function add_func_shortcodes_progressbar( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
		'barcolor'			=> '#119fe1',
		'linewidth' 		=> '3',
		'trackcolor'		=> '#cccccc',
		'percent'			=> '',
		'class'				=> '',
	), $attrs ) );

	$element_id = drupal_html_id('progressbar'); 
	
	$classes = 'progressbar';
	
	if ( $class ) {
		$classes = $classes . ' ' . $class;
	}
	
	$output = '<div id="' . $element_id . '" class="' . $classes . '" data-percent="' . $percent . '">';

	if ( $content ) :
		$output .= '<div class="progressbar-title">' . $content . '</div>';
	endif;
	
	$output .= '<div class="progressbar-percent">' . $percent . '%</div>';
	
	if ( $percent ) :
		$output .= '<div class="progressbar-wrap" style="background: ' . $trackcolor . '; height: ' . $linewidth . 'px;"><div class="progressbar-background" style="width: 0; background: ' . $barcolor . '; height: ' . $linewidth . 'px;"></div></div>';
	endif;
	
	$output .= '</div>';
	
	return $output;
}

function add_func_shortcodes_progressbar_tips( $format, $long ) {
	$output = '[progressbar percent="0 | 1 | .. | 100" linewidth="3" barcolor="#21c2f8" trackcolor="#cccccc" class="custom-class"]Title[/progressbar]';
	return $output;
}









 /*============================================================================================*/
/* Contact_info Shortcode
/*============================================================================================*/

/**
 *
 * Display contact information such as Name, Email, ...
 * @param $attrs
 * @param $content
 */

/* function add_func_shortcodes_contact( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
		'fullname' => '',
		'address' => '',
		'city' => '',
		'state' => '',
		'zip' => '',
		'country' => '',
		'phone' => '',
		'email' => '',
		), $attrs ) );

	$items = array();
	$full_address = array();
	if ( $fullname ) {
		$full_address[] = $fullname;
	}
	if ( $address ) {
		$full_address[] = $address;
	}
	if ( $city ) {
		$full_address[] = $city;
	}
	if ( $state ) {
		$full_address[] = $state;
	}
	if ( $zip ) {
		$full_address[] = $zip;
	}
	if ( $country ) {
		$full_address[] = $country;
	}
	$items[] = array(
		'data' => implode( ', ', $full_address ),
		'class' => array( 'address' )
	);
	if ( $phone ) {
		$items[] = array(
			'data' => $phone,
			'class' => array( 'phone' )
		);
	}
	if ( $email ) {
		$items[] = array(
			'data' => $email,
			'class' => array( 'email' )
		);
	}

	return theme( 'item_list',
		array(
			'items' => $items,
			'title' => NULL,
			'type' => 'ul',
			'attributes' => array( 'class' => array( 'contact-info' ) )
		)
	);
}

function add_func_shortcodes_contact_tips( $format, $long ) {
	$output = '[contact fullname="John Smith" address="Park lane 5" city="LA" state="California" zip="12345" phone="555-55-555" email="info@example.com"][/contact]';
	return $output;
}

function add_func_shortcodes_contact_attributes( $form, $form_state ) {
	$form['fullname'] = array(
		'#type' => 'textfield',
		'#title' => t( 'Name' ),
		'#size' => 30,
		'#maxlength' => 30,
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'contact' ),
			),
		),
	);
	$form['address'] = array(
		'#type' => 'textfield',
		'#title' => t( 'Address' ),
		'#size' => 30,
		'#maxlength' => 30,
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'contact' ),
			),
		),
	);
	$form['city'] = array(
		'#type' => 'textfield',
		'#title' => t( 'City' ),
		'#size' => 30,
		'#maxlength' => 30,
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'contact' ),
			),
		),
	);
	$form['state'] = array(
		'#type' => 'textfield',
		'#title' => t( 'State / Province' ),
		'#size' => 30,
		'#maxlength' => 30,
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'contact' ),
			),
		),
	);
	$form['zip'] = array(
		'#type' => 'textfield',
		'#title' => t( 'Zip / Postal code' ),
		'#size' => 30,
		'#maxlength' => 30,
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'contact' ),
			),
		),
	);
	$form['phone'] = array(
		'#type' => 'textfield',
		'#title' => t( 'Phone number' ),
		'#size' => 30,
		'#maxlength' => 30,
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'contact' ),
			),
		),
	);
	$form['email'] = array(
		'#type' => 'textfield',
		'#title' => t( 'Email' ),
		'#size' => 30,
		'#maxlength' => 30,
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'contact' ),
			),
		),
	);
	return $form;
}

function add_func_shortcodes_social( $attrs, $content = null ) {
	$attributes = array();
	$icon_path = drupal_get_path( 'module', 'add_func_shortcodes' ) . '/styling/icons/social/mono';
	$files = file_scan_directory( $icon_path, '/\.(jpg|gif|png?)$/' );
	asort( $files );
	foreach ( $files as $file ) {
		$attributes[$file->name] = '';
	}
	shortcode_attrs( $attributes, $attrs );
	if ( isset( $attrs['type'] ) ) {
		$type = 'inline';
		unset( $attrs['type'] );
	}
	$items = array();

	foreach ( $attrs as $name => $content ) {
		if ( strpos( $content, '|' ) ) {
			$content_array = explode( '|', $content );
			$text = $content_array[1];
			$url = $content_array[0];
		}
		else {
			$url = $content;
			$text = FALSE;
		}
		$link = explode( '|', $content );
		$items[] = array( 'data' => l( $text, $url ), 'class' => array( $name ), 'title' => ucfirst( $name ) );
	}

	$classes = array( 'social-links' );
	if ( isset( $type ) ) $classes[] = $type;

	return theme( 'item_list',
		array(
			'items' => $items,
			'title' => NULL,
			'type' => 'ul',
			'attributes' => array( 'class' => $classes )
		)
	);
}

function add_func_shortcodes_social_tips( $format, $long ) {
	$output = '[social type="inline" Skype="http://google.com" Twitter="http://google.com" Facebook="http://google.com" Drupal="http://google.com"][/social]';
	return $output;
}


function add_func_shortcodes_social_attributes( $form, $form_state ) {
	$icon_path = drupal_get_path( 'module', 'add_func_shortcodes' ) . '/styling/icons/social/mono';
	$files = file_scan_directory( $icon_path, '/\.(jpg|gif|png?)$/' );
	asort( $files );
	$form['type'] = array(
		'#type' => 'select',
		'#title' => t( 'Layout' ),
		'#options' => array(
			'' => t( 'Stacked' ),
			'inline' => t( 'Inline' ),
		),
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'social' ),
			),
		),
	);
	foreach ( $files as $file ) {
		$bg_images[$file->uri] = $file->name;
		$form[$file->name] = array(
			'#type' => 'textfield',
			'#title' => $file->name,
			'#size' => 60,
			'#states' => array(
				'visible' => array(
					':input[name="shortcode"]' => array( 'value' => 'social' ),
				),
			),
		);
	}
	return $form;
} */

/**
 * Drop shadows
 */

/*function add_func_shortcodes_dropshadow( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
	'type'			=> '',
	), $attrs ) );

	$classes = array();
	$classes[] = 'dropshadow';
	if ( $type == '' ) $classes[] = 'raised';
	if ( $type == 2 ) $classes[] = 'perspective';
	if ( $type == 3 ) $classes[] = 'lifted';
	if ( $type > 3 ) $classes[] = 'curved';
	if ( $type == 4 ) $classes[] = 'curved-hz1';
	if ( $type == 5 ) $classes[] = 'curved-hz2';
	if ( $type == 6 ) $classes[] = 'curved-vt2';

	$classes = trim( implode( ' ', $classes ) );

	return '<div class="' . $classes . '">' . $content . '</div>';
}

function add_func_shortcodes_dropshadow_tips( $format, $long ) {
	$output = '[dropshadow]your content[/dropshadow]';
	return $output;
}

function add_func_shortcodes_dropshadow_attributes( $form, $form_state ) {
	$form['type'] = array(
		'#type' => 'select',
		'#title' => t( 'Drop shadow type' ),
		'#options' => array(
			'' => t( 'Regular' ),
			2 => t( 'Perspective' ),
			3 => t( 'Lifted corners' ),
			4 => t( 'Curve' ),
			5 => t( 'Double curve' ),
			6 => t( 'Side shadows' ),
		),
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'dropshadow' ),
			),
		),
	);
	return $form;
} */

/*============================================================================================*/
/* Divider Styles Shortcodes
/*============================================================================================*/
/* function add_func_shortcodes_divider( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
		'type' => '',
		), $attrs ) );

	$class = '';
	if ( $type ) $class = ' class="' . $type . '"';

	$output = '<hr' . $class . '>';
	if ( $type == 'top' ) $output .= '<a class="hr-toplink" href="#top">' . t( 'Back to Top ↑' ) . '</a>';

	return $output;
}

function add_func_shortcodes_divider_tips( $format, $long ) {
	$output = '[divider type="invisible|top"][/divider]';
	return $output;
}

function add_func_shortcodes_divider_attributes( $form, $form_state ) {
	$form['type'] = array(
		'#type' => 'select',
		'#title' => t( 'Divider style' ),
		'#options' => array(
			'' => t( 'Regular' ),
			'invisible' => t( 'Invisible' ),
			'top' => t( 'Add "back to top" link' ),
		),
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'divider' ),
			),
		),
	);
	return $form;
} */

/*============================================================================================*/
/* Teaser Shortcodes
/*============================================================================================*/
/*function add_func_shortcodes_teaser( $attrs, $content = null ) {

	$type = !empty( $type ) && in_array( $type, array( 'normal', 'large' ) ) ? $type : 'normal';
	return '<p class="teaser">' . $content . '</p>';
}

function add_func_shortcodes_teaser_tips( $format, $long ) {
	$output = '[teaser]Your content[/teaser]';
	return $output;
}*/

/*============================================================================================*/
/* Button Shortcode
/*============================================================================================*/
/* function add_func_shortcodes_button( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
	'url'				=> '',
	'size'			 => '',
	'background' => '',
	'text'			 => '',
	'align'			=> '',
	'target'		 => '',
	'class'			=> '',
	'width'			=> '',
	'last'			 => '',
	), $attrs ) );

	$style = '';
	if ( $background ) $style .= "background-color: $background;";
	if ( $text ) $style .= "color: $text;";

	$classes = array();
	if ( $width ) $classes[] = 'col-' . $width;
	if ( $last ) $classes[] = 'col-last';
	$classes[] = 'sc-button';
	$classes[] = 'sc-button-' . $size;
	if ( $align == 'right' ) $classes[] = 'float-right';
	if ( $align == 'center' ) $classes[] = 'align-center';
	// $classes[] = !empty( $class ) ?	explode( ' ', $class ) : null;

	return l( $content, $url, array(
		'attributes' => array(
			'class' => $classes,
			'style' => $style,
			'target' => $target,
		),
		'html' => TRUE,
	)
	);
}

function add_func_shortcodes_button_tips( $format, $long ) {
	$output = '[button url="http://www.sooperthemes.com" background=Crimson text=Gold size="3" align="center" target="_blank" width="2-3"]2/3rds Button, centred[/button]';
	return $output;
}

function add_func_shortcodes_button_attributes( $form, $form_state ) {
	$form['url'] = array(
		'#type' => 'textfield',
		'#title' => t( 'Link url' ),
		'#size' => 30,
		'#maxlength' => 30,
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'button' ),
			),
		),
	);
	$form['size'] = array(
		'#type' => 'select',
		'#title' => t( 'Button size' ),
		'#options' => array(
			1 => t( 'size 1' ),
			2 => t( 'size 2' ),
			3 => t( 'size 3' ),
			4 => t( 'size 4' ),
		),
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'button' ),
			),
		),
	);
	$form['background'] = array(
		'#type' => 'textfield',
		'#title' => t( 'Optionally choose a custom background color' ),
		'#description' => t( 'Must be a valid CSS color. <a href="http://css-tricks.com/snippets/css/named-colors-and-hex-equivalents/">List of named colors</a>.' ),
		'#size' => 30,
		'#maxlength' => 30,
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'button' ),
			),
		),
	);
	$form['text'] = array(
		'#type' => 'textfield',
		'#title' => t( 'Optionally choose a custom text color' ),
		'#description' => t( 'Must be a valid CSS color.' ),
		'#size' => 30,
		'#maxlength' => 30,
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'button' ),
			),
		),
	);
	$form['align'] = array(
		'#type' => 'select',
		'#title' => t( 'Alignment of element' ),
		'#options' => array(
			'' => t( 'Left' ),
			'right' => t( 'Right' ),
			'center' => t( 'Center' ),
		),
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'button' ),
			),
		),
	);
	$form['target'] = array(
		'#type' => 'select',
		'#title' => t( 'Link target' ),
		'#options' => array(
			'' => t( '_self' ),
			'_blank' => t( '_blank' ),
			'_parent' => t( '_parent' ),
			'_top' => t( '_top' ),
		),
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'button' ),
			),
		),
	);
	$form['width'] = array(
		'#type' => 'select',
		'#title' => t( 'Column width' ),
		'#options' => array(
			'' => t( 'Auto' ),
			'1-8' => t( '1/8' ),
			'1-7' => t( '1/7' ),
			'1-6' => t( '1/6' ),
			'1-5' => t( '1/5' ),
			'1-4' => t( '1/4' ),
			'1-3' => t( '1/3' ),
			'1-2' => t( '1/2' ),
			'2-3' => t( '2/3' ),
			'3-4' => t( '3/4' ),
			'2-5' => t( '2/5' ),
			'3-5' => t( '3/5' ),
			'4-5' => t( '4/5' ),
			'5-6' => t( '5/6' ),
			'100' => t( '100' ),
		),
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'button' ),
			),
		),
	);
	return $form;
} */

/*============================================================================================*/
/* box Shortcode
/*============================================================================================*/
/* function add_func_shortcodes_box( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
	'type'			 => 1,
	'background' => '',
	'text'			 => '',
	'align'			=> '',
	'width'			=> '',
	'last'			=> '',
	'clear'			=> '',
	'class'			=> '',
	), $attrs ) );

	$style = '';
	if ( $background ) $style .= "background-color: $background;";
	if ( $text ) $style .= "color: $text;";
	if ( $clear ) $style .= "clear: $clear;";

	if ( $style ) $style = ' style="' . $style . '"';

	$classes = array();
	if ( $width ) $classes[] = 'col-' . $width;
	if ( $last ) $classes[] = 'col-last';
	if ( $type == 'quote' ) {
		$tag = 'blockquote';
		if ( !$width ) $classes[] = 'grid-1-2';
	} else {
		$tag = 'aside';
		$classes[] = 'block';
	}

	$classes[] = 'box';
	$classes[] = 'box-' . $type;
	if ( $align == 'right' ) $classes[] = 'float-right';
	if ( $align == 'center' ) $classes[] = 'align-center';
	$classes[] = !empty( $class ) ?	explode( ' ', $class ) : null;
	$classes = trim( implode( ' ', $classes ) );

	return '<' . $tag . ' class="' . $classes . '"' . $style . '>' . $content . "</$tag>";
}

function add_func_shortcodes_box_tips( $format, $long ) {
	$output = '[box background=tomato text=white align=right width="1-4"]your content here[/box]';
	return $output;
}

function add_func_shortcodes_box_attributes( $form, $form_state ) {
	$form['type'] = array(
		'#type' => 'select',
		'#title' => t( 'Type' ),
		'#options' => array(
			1 => t( 'Normal' ),
			'note' => t( 'Note' ),
			'quote' => t( 'Blockquote' ),
		),
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'box' ),
			),
		),
	);
	$form['align'] = array(
		'#type' => 'select',
		'#title' => t( 'Alignment of element' ),
		'#options' => array(
			'' => t( 'Left' ),
			'right' => t( 'Right' ),
			'center' => t( 'Center' ),
		),
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'box' ),
			),
		),
	);
	$form['width'] = array(
		'#type' => 'select',
		'#title' => t( 'Column width' ),
		'#options' => array(
			'' => t( 'Auto' ),
			'1-8' => t( '1/8' ),
			'1-7' => t( '1/7' ),
			'1-6' => t( '1/6' ),
			'1-5' => t( '1/5' ),
			'1-4' => t( '1/4' ),
			'1-3' => t( '1/3' ),
			'1-2' => t( '1/2' ),
			'2-3' => t( '2/3' ),
			'3-4' => t( '3/4' ),
			'2-5' => t( '2/5' ),
			'3-5' => t( '3/5' ),
			'4-5' => t( '4/5' ),
			'5-6' => t( '5/6' ),
		),
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'box' ),
			),
		),
	);
	$form['background'] = array(
		'#type' => 'textfield',
		'#title' => t( 'Optionally choose a custom background color' ),
		'#description' => t( 'Must be a valid CSS color. <a href="http://css-tricks.com/snippets/css/named-colors-and-hex-equivalents/">List of named colors</a>.' ),
		'#size' => 30,
		'#maxlength' => 30,
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'box' ),
			),
		),
	);
	$form['text'] = array(
		'#type' => 'textfield',
		'#title' => t( 'Optionally choose a custom text color' ),
		'#description' => t( 'Must be a valid CSS color.' ),
		'#size' => 30,
		'#maxlength' => 30,
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'box' ),
			),
		),
	);
	return $form;
} */


/*============================================================================================*/
/* Jquery toggle content Shortcode
/*============================================================================================*/
/* function add_func_shortcodes_toggle( $attrs, $content = null ) {
	extract( shortcode_attrs( array(
	'title'			=> '',
	'expanded'			=> FALSE,
	), $attrs ) );

	$classes = array();
	if ( $expanded ) {
		$classes[] = 'expanded';
	}
	else {
		$collapsed = ' default-collapsed';
	}

	$classes = implode( ' ', $classes );

	$out =	'<div class="toggle' . $collapsed . '"><h3 class="' . $classes . '" onclick="$(this).toggleClass(\'expanded\').next().toggle(\'fast\');" ><a href="##">' . $title . '</a></h3>';
	$out .= '<div class="toggle-content clearfix">' . $content . '</div>';
	$out .= '</div>';

	return $out;
} 


function add_func_shortcodes_toggle_tips( $format, $long ) {
	$output = '[toggle title="Show toggle shortcode"]Your content here[/toggle]';
	return $output;
}

function add_func_shortcodes_toggle_attributes( $form, $form_state ) {
	$form['expanded'] = array(
		'#type' => 'select',
		'#title' => t( 'Collapsed / Expanded' ),
		'#options' => array(
			'' => t( 'Collapsed' ),
			1 => t( 'Expanded' ),
		),
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'toggle' ),
			),
		),
	);
	$form['title'] = array(
		'#type' => 'textfield',
		'#title' => t( 'Title' ),
		'#description' => t( 'Must be a valid CSS color.' ),
		'#size' => 60,
		'#maxlength' => 60,
		'#states' => array(
			'visible' => array(
				':input[name="shortcode"]' => array( 'value' => 'toggle' ),
			),
		),
	);
	return $form;
}
*/
// Quicktabs implementation is currently now working well because I don't know how to populate
// Drupal.settings.quicktabs in a way that works well with caching.

// /*============================================================================================*/
// /* Jquery toggle content Shortcode
// /*============================================================================================*/
// function add_func_shortcodes_tabs( $attrs, $content = null ) {
//	 extract( shortcode_attrs( array(
//	 'type'			=> '',
//	 ), $attrs ) );

//	 if ( !function_exists( 'quicktabs_build_quicktabs' ) ) {
//		 drupal_set_message( t( 'You must enable the quicktabs module to use the tabs shortcode' ), 'error' );
//		 return;
//	 }

//	 if ( ( $type == 'accordion' OR $type == 'accordeon' ) ) {
//		 $settings = array(
//			 'renderer' => 'accordion',
//			 'options' => array (
//				 'history' => 0,
//				 'jquery_ui' => array(
//					 'autoHeight' => 0,
//					 'collapsible' => 0,
//				 ),
//			 ),
//		 );
//	 } else {
//		 $settings = array();
//	 }

//	 global $shortcode_tabs_stack;
//	 $output = drupal_render( quicktabs_build_quicktabs( rand(), $settings, $shortcode_tabs_stack ) );
//	 $shortcode_tabs_stack = null;
//	 return $output;
// }


// function add_func_shortcodes_tabs_tips( $format, $long ) {
//	 $output = '[tabs][tab-item title="Your title"]Your content[/tab-item][tab-item title="Next title"]Next content[/tab-item][/tabs]';
//	 return $output;
// }
// function add_func_shortcodes_tab_item( $attrs, $content = null ) {
//	 extract( shortcode_attrs( array(
//	 'title'			=> '',
//	 ), $attrs ) );

//	 // Unfortunately there is currently no other way to pass arguments to the
//	 // tabs function #lame
//	 global $shortcode_tabs_stack;
//	 if ( !is_array( $shortcode_tabs_stack ) ) $shortcode_tabs_stack = array();
//	 $pane = array(
//		 'title' => $title,
//		 'contents' => array(
//			 '#markup' => $content,
//		 ),
//		 'weight' => count( $shortcode_tabs_stack ),
//	 );
//	 $shortcode_tabs_stack[] = $pane;
// }


// function add_func_shortcodes_tabs_item_tips( $format, $long ) {
//	 $output = '[tabs type=accordion][tab-item title="Your title"]Your content[/tab-item][tab-item title="Next title"]Next content[/tab-item][/tabs]';
//	 return $output;
// }


/*============================================================================================*/
/* List style Shortcode
/*============================================================================================*/
/*function add_func_shortcodes_icon_list( $attrs, $content = null ) {

	extract( shortcode_attrs( array(
	'type'		 => '',
	), $attrs ) );


	$types = array( 'sc-arrow', 'sc-buoy', 'sc-calendar', 'sc-clock', 'sc-pin', 'sc-play', 'sc-skip', 'sc-thumb', 'sc-tick', 'sc-tick-grey', 'sc-warning' );


	$type = trim( strtolower( $type ) );
	$classes = array();
	$classes[] = 'sc-icon-list';
	if ( in_array( $type, $types ) ) $classes[] = $type;

	$classes = trim( implode( ' ', $classes ) );
	$output = preg_replace( "/<(ul|ol|dl)[a-z0-9\"'=\s-_]*?>/","<ul class=\"$classes\">", $content );

	return $output;
}

function add_func_shortcodes_icon_list_tips( $format, $long ) {
	$output = '[icon-list type=sc-arrow|sc-buoy||sc-calendar|sc-clock|sc-pin|sc-arrow|sc-play|sc-skip|sc-thumb|sc-tick|sc-tick-grey|sc-warning]your list here[/icon-list]';
	return $output;
}*/



/*
+ Dropcap
+ Highlight
+ Message boxes
Video
Tabs
Accordion
Toggle
Pricing tables
*/