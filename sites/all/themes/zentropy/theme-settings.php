<?php

/**
 * @file
 * Theme settings for the Zentropy
 */
function zentropy_form_system_theme_settings_alter( &$form, &$form_state ) {
	if ( !isset( $form['zentropy_settings'] ) ) {
		/**
		 * Vertical tabs layout borrowed from Sasson.
		 *
		 * @link http://drupal.org/project/sasson
		 */
		/*drupal_add_css( drupal_get_path( 'theme', 'zentropy' ) . '/css/admin/theme-settings.css', array(
			'group'				=> CSS_THEME,
			'every_page'		=> TRUE,
			'weight'			=> 99
		) );*/

		/* Submit function */
		$form['#submit'][] = 'zentropy_form_system_theme_settings_submit';

		/* Add reset button */
		$form['actions']['reset'] = array(
			'#submit' => array( 'zentropy_form_system_theme_settings_reset' ),
			'#type' => 'submit',
			'#value' => t( 'Reset to defaults' ),
		);

		/* Settings */
		$form['zentropy_settings'] = array(
			'#type'				=> 'vertical_tabs',
			'#weight'			=> -10,
		);
		
		/**
		 * General settings.
		 */
		$form['zentropy_settings']['zentropy_general'] = array(
			'#title'			=> t( 'General Settings' ),
			'#type'				=> 'fieldset',
		);
		
		$form['zentropy_settings']['zentropy_general']['theme_settings'] = $form['theme_settings'];
		unset( $form['theme_settings'] );

		$form['zentropy_settings']['zentropy_general']['logo'] = $form['logo'];
		unset( $form['logo'] );

		$form['zentropy_settings']['zentropy_general']['favicon'] = $form['favicon'];
		unset( $form['favicon'] );
		
		$form['zentropy_settings']['zentropy_general']['zentropy_menu'] = array(
			'#title'			=> t( 'Menu' ),
			'#type'				=> 'fieldset',
		);
		
		$form['zentropy_settings']['zentropy_general']['zentropy_menu']['zentropy_sticky_menu'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_sticky_menu' ),
			'#title'			=> t( 'Stick up menu.' ),
			'#type'				=> 'checkbox',
		);

		$form['zentropy_settings']['zentropy_general']['zentropy_breadcrumb'] = array(
			'#title'			=> t( 'Breadcrumbs' ),
			'#type'				=> 'fieldset',
		);

		$form['zentropy_settings']['zentropy_general']['zentropy_breadcrumb']['zentropy_breadcrumb_show'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_breadcrumb_show' ),
			'#title'			=> t( 'Show the breadcrumb.' ),
			'#type'				=> 'checkbox',
		);

		$form['zentropy_settings']['zentropy_general']['zentropy_breadcrumb']['zentropy_breadcrumb_container'] = array(
			'#states'			=> array(
				'invisible'		=> array(
					'input[name="zentropy_breadcrumb_show"]' => array(
						'checked'	=> FALSE
					),
				),
			),
			'#type'				=> 'container',
		);

		$form['zentropy_settings']['zentropy_general']['zentropy_breadcrumb']['zentropy_breadcrumb_container']['zentropy_breadcrumb_hideonlyfront'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_breadcrumb_hideonlyfront' ),
			'#title'			=> t( 'Hide the breadcrumb if the breadcrumb only contains a link to the front page.' ),
			'#type'				=> 'checkbox',
		);

		$form['zentropy_settings']['zentropy_general']['zentropy_breadcrumb']['zentropy_breadcrumb_container']['zentropy_breadcrumb_showtitle'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_breadcrumb_showtitle' ),
			'#description'		=> t( "Check this option to add the current page's title to the breadcrumb trail." ),
			'#title'			=> t( 'Show page title on breadcrumb.' ),
			'#type'				=> 'checkbox',
		);

		$form['zentropy_settings']['zentropy_general']['zentropy_breadcrumb']['zentropy_breadcrumb_container']['zentropy_breadcrumb_separator'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_breadcrumb_separator' ),
			'#description'		=> t( 'Text only. Dont forget to include spaces.' ),
			'#size'				=> 8,
			'#title'			=> t( 'Breadcrumb separator' ),
			'#type'				=> 'textfield',
		);

		/**
		 * Regions Settings
		 */
		$form['zentropy_settings']['zentropy_regions'] = array(
			'#title'			=> t( 'Regions Settings' ),
			'#type'				=> 'fieldset',
		);
		

		// Header bottom
		$form['zentropy_settings']['zentropy_regions']['zentropy_header_bottom_opt'] = array(
			'#title'			=> t( 'Header bottom' ),
			'#type'				=> 'fieldset',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_header_bottom_opt']['zentropy_header_bottom_bg_type'] = array(
			'#default_value' => theme_get_setting( 'zentropy_header_bottom_bg_type' ),
			'#options' => array(
				'none' => 'None',
				'image' => 'Image',
				'video' => 'Video',
			),
			'#title' => t( 'Background type:' ),
			'#type' => 'select',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_header_bottom_opt']['zentropy_header_bottom_bg_img'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_header_bottom_bg_img' ),
			'#description'		=> t( 'Choose block background image.' ),
			'#media_options' => array(
				'global' => array(
					'types' => array(
						'image' => 'image',
					),
					'schemes' => array(
						'public' => 'public',
					),
					'file_extensions' => 'png gif jpg jpeg',
					'max_filesize' => '1 MB',
					'uri_scheme' => 'public',
				),
			),
			'#states'			=> array(
				'visible'		=> array(
					'select[name="zentropy_header_bottom_bg_type"]' => array(
						'value'	=> 'image'
					),
				),
			),
			'#title'			=> t( 'Background image URL' ),
			'#tree'				=> TRUE,
			'#type'				=> 'media',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_header_bottom_opt']['zentropy_header_bottom_bg_parallax'] = array(
			'#default_value' =>  theme_get_setting( 'zentropy_header_bottom_bg_parallax' ),
			'#description'		=> '',
			'#states'			=> array(
				'visible'		=> array(
					'select[name="zentropy_header_bottom_bg_type"]' => array(
						'value'	=> 'image'
					),
				),
			),
			'#title' => t( 'Use parallax' ),
			'#type' => 'checkbox',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_header_bottom_opt']['zentropy_header_bottom_bg_video'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_header_bottom_bg_video' ),
			'#description'		=> t( 'Enter video URL. Supports youtube video. ' ),
			'#size'				=> 60,
			'#states'			=> array(
				'visible'		=> array(
					'select[name="zentropy_header_bottom_bg_type"]' => array(
						'value'	=> 'video'
					),
				),
			),
			'#title'			=> t( 'Background Video URL' ),
			'#type'				=> 'textfield',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_header_bottom_opt']['zentropy_header_bottom_bg_video_start'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_header_bottom_bg_video_start' ),
			'#description'		=> t( 'Enter time in seconds. ' ),
			'#size'				=> 8,
			'#states'			=> array(
				'visible'		=> array(
					'select[name="zentropy_header_bottom_bg_type"]' => array(
						'value'	=> 'video'
					),
				),
			),
			'#title'			=> t( 'Start video at' ),
			'#type'				=> 'textfield',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_header_bottom_opt']['zentropy_header_bottom_fullwidth'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_header_bottom_fullwidth' ),
			'#description'		=> t( "Check this option to make this region fullwidth (e.g. remove grids)." ),
			'#title'			=> t( 'Fullwidth' ),
			'#type'				=> 'checkbox',
		);

		// Content top
		$form['zentropy_settings']['zentropy_regions']['zentropy_content_top_opt'] = array(
			'#title'			=> t( 'Content top' ),
			'#type'				=> 'fieldset',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_content_top_opt']['zentropy_content_top_bg_type'] = array(
			'#default_value' => theme_get_setting( 'zentropy_content_top_bg_type' ),
			'#options' => array(
				'none' => 'None',
				'image' => 'Image',
				'video' => 'Video',
			),
			'#title' => t( 'Background type:' ),
			'#type' => 'select',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_content_top_opt']['zentropy_content_top_bg_img'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_content_top_bg_img' ),
			'#description'		=> t( 'Choose block background image.' ),
			'#media_options' => array(
				'global' => array(
					'types' => array(
						'image' => 'image',
					),
					'schemes' => array(
						'public' => 'public',
					),
					'file_extensions' => 'png gif jpg jpeg',
					'max_filesize' => '1 MB',
					'uri_scheme' => 'public',
				),
			),
			'#states'			=> array(
				'visible'		=> array(
					'select[name="zentropy_content_top_bg_type"]' => array(
						'value'	=> 'image'
					),
				),
			),
			'#title'			=> t( 'Background image URL' ),
			'#tree'				=> TRUE,
			'#type'				=> 'media',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_content_top_opt']['zentropy_content_top_bg_parallax'] = array(
			'#default_value' =>  theme_get_setting( 'zentropy_content_top_bg_parallax' ),
			'#description'		=> '',
			'#states'			=> array(
				'visible'		=> array(
					'select[name="zentropy_content_top_bg_type"]' => array(
						'value'	=> 'image'
					),
				),
			),
			'#title' => t( 'Use parallax' ),
			'#type' => 'checkbox',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_content_top_opt']['zentropy_content_top_bg_video'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_content_top_bg_video' ),
			'#description'		=> t( 'Enter video URL. Supports youtube video. ' ),
			'#size'				=> 60,
			'#states'			=> array(
				'visible'		=> array(
					'select[name="zentropy_content_top_bg_type"]' => array(
						'value'	=> 'video'
					),
				),
			),
			'#title'			=> t( 'Background Video URL' ),
			'#type'				=> 'textfield',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_content_top_opt']['zentropy_content_top_bg_video_start'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_content_top_bg_video_start' ),
			'#description'		=> t( 'Enter time in seconds. ' ),
			'#size'				=> 8,
			'#states'			=> array(
				'visible'		=> array(
					'select[name="zentropy_content_top_bg_type"]' => array(
						'value'	=> 'video'
					),
				),
			),
			'#title'			=> t( 'Start video at' ),
			'#type'				=> 'textfield',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_content_top_opt']['zentropy_content_top_fullwidth'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_content_top_fullwidth' ),
			'#description'		=> t( "Check this option to make this region fullwidth (e.g. remove grids)." ),
			'#title'			=> t( 'Fullwidth' ),
			'#type'				=> 'checkbox',
		);
		
		
		// Content bottom
		$form['zentropy_settings']['zentropy_regions']['zentropy_content_bottom_opt'] = array(
			'#title'			=> t( 'Content bottom' ),
			'#type'				=> 'fieldset',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_content_bottom_opt']['zentropy_content_bottom_bg_type'] = array(
			'#default_value' => theme_get_setting( 'zentropy_content_bottom_bg_type' ),
			'#options' => array(
				'none' => 'None',
				'image' => 'Image',
				'video' => 'Video',
			),
			'#title' => t( 'Background type:' ),
			'#type' => 'select',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_content_bottom_opt']['zentropy_content_bottom_bg_img'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_content_bottom_bg_img' ),
			'#description'		=> t( 'Choose block background image.' ),
			'#media_options' => array(
				'global' => array(
					'types' => array(
						'image' => 'image',
					),
					'schemes' => array(
						'public' => 'public',
					),
					'file_extensions' => 'png gif jpg jpeg',
					'max_filesize' => '1 MB',
					'uri_scheme' => 'public',
				),
			),
			'#states'			=> array(
				'visible'		=> array(
					'select[name="zentropy_content_bottom_bg_type"]' => array(
						'value'	=> 'image'
					),
				),
			),
			'#title'			=> t( 'Background image URL' ),
			'#tree'				=> TRUE,
			'#type'				=> 'media',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_content_bottom_opt']['zentropy_content_bottom_bg_parallax'] = array(
			'#default_value' =>  theme_get_setting( 'zentropy_content_bottom_bg_parallax' ),
			'#description'		=> '',
			'#states'			=> array(
				'visible'		=> array(
					'select[name="zentropy_content_bottom_bg_type"]' => array(
						'value'	=> 'image'
					),
				),
			),
			'#title' => t( 'Use parallax' ),
			'#type' => 'checkbox',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_content_bottom_opt']['zentropy_content_bottom_bg_video'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_content_bottom_bg_video' ),
			'#description'		=> t( 'Enter video URL. Supports youtube video. ' ),
			'#size'				=> 60,
			'#states'			=> array(
				'visible'		=> array(
					'select[name="zentropy_content_bottom_bg_type"]' => array(
						'value'	=> 'video'
					),
				),
			),
			'#title'			=> t( 'Background Video URL' ),
			'#type'				=> 'textfield',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_content_bottom_opt']['zentropy_content_bottom_bg_video_start'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_content_bottom_bg_video_start' ),
			'#description'		=> t( 'Enter time in seconds. ' ),
			'#size'				=> 8,
			'#states'			=> array(
				'visible'		=> array(
					'select[name="zentropy_content_bottom_bg_type"]' => array(
						'value'	=> 'video'
					),
				),
			),
			'#title'			=> t( 'Start video at' ),
			'#type'				=> 'textfield',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_content_bottom_opt']['zentropy_content_bottom_fullwidth'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_content_bottom_fullwidth' ),
			'#description'		=> t( "Check this option to make this region fullwidth (e.g. remove grids)." ),
			'#title'			=> t( 'Fullwidth' ),
			'#type'				=> 'checkbox',
		);

		// Footer top
		$form['zentropy_settings']['zentropy_regions']['zentropy_footer_top_opt'] = array(
			'#title'			=> t( 'Footer top' ),
			'#type'				=> 'fieldset',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_footer_top_opt']['zentropy_footer_top_bg_type'] = array(
			'#default_value' => theme_get_setting( 'zentropy_footer_top_bg_type' ),
			'#options' => array(
				'none' => 'None',
				'image' => 'Image',
				'video' => 'Video',
			),
			'#title' => t( 'Background type:' ),
			'#type' => 'select',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_footer_top_opt']['zentropy_footer_top_bg_img'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_footer_top_bg_img' ),
			'#description'		=> t( 'Choose block background image.' ),
			'#media_options' => array(
				'global' => array(
					'types' => array(
						'image' => 'image',
					),
					'schemes' => array(
						'public' => 'public',
					),
					'file_extensions' => 'png gif jpg jpeg',
					'max_filesize' => '1 MB',
					'uri_scheme' => 'public',
				),
			),
			'#states'			=> array(
				'visible'		=> array(
					'select[name="zentropy_footer_top_bg_type"]' => array(
						'value'	=> 'image'
					),
				),
			),
			'#title'			=> t( 'Background image URL' ),
			'#tree'				=> TRUE,
			'#type'				=> 'media',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_footer_top_opt']['zentropy_footer_top_bg_parallax'] = array(
			'#default_value' =>  theme_get_setting( 'zentropy_footer_top_bg_parallax' ),
			'#description'		=> '',
			'#states'			=> array(
				'visible'		=> array(
					'select[name="zentropy_footer_top_bg_type"]' => array(
						'value'	=> 'image'
					),
				),
			),
			'#title' => t( 'Use parallax' ),
			'#type' => 'checkbox',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_footer_top_opt']['zentropy_footer_top_bg_video'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_footer_top_bg_video' ),
			'#description'		=> t( 'Enter video URL. Supports youtube video. ' ),
			'#size'				=> 60,
			'#states'			=> array(
				'visible'		=> array(
					'select[name="zentropy_footer_top_bg_type"]' => array(
						'value'	=> 'video'
					),
				),
			),
			'#title'			=> t( 'Background Video URL' ),
			'#type'				=> 'textfield',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_footer_top_opt']['zentropy_footer_top_bg_video_start'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_footer_top_bg_video_start' ),
			'#description'		=> t( 'Enter time in seconds. ' ),
			'#size'				=> 8,
			'#states'			=> array(
				'visible'		=> array(
					'select[name="zentropy_footer_top_bg_type"]' => array(
						'value'	=> 'video'
					),
				),
			),
			'#title'			=> t( 'Start video at' ),
			'#type'				=> 'textfield',
		);
		$form['zentropy_settings']['zentropy_regions']['zentropy_footer_top_opt']['zentropy_footer_top_fullwidth'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_footer_top_fullwidth' ),
			'#description'		=> t( "Check this option to make this region fullwidth (e.g. remove grids)." ),
			'#title'			=> t( 'Fullwidth' ),
			'#type'				=> 'checkbox',
		);

		/**
		 * Custom CSS
		 */
		$form['zentropy_settings']['zentropy_css'] = array(
			'#title'			=> t( 'Custom CSS' ),
			'#type'				=> 'fieldset',
		);
		
		$form['zentropy_settings']['zentropy_css']['css'] = array(
			'#title'			=> t( 'Custom CSS' ),
			'#type'				=> 'fieldset',
		);

		$form['zentropy_settings']['zentropy_css']['css']['zentropy_custom_css'] = array(
			'#default_value'	=> theme_get_setting( 'zentropy_custom_css' ),
			'#title'			=> t( 'Insert your CSS code here:' ),
			'#type'				=> 'textarea',
		);
	}
}


/* Custom CSS */
function zentropy_form_system_theme_settings_submit( $form, &$form_state ) {
	$fp = fopen( drupal_get_path( 'theme', 'zentropy' ) . '/css/custom.css', 'a' );
	ftruncate( $fp, 0 );
	fwrite( $fp, $form_state['values']['zentropy_custom_css'] );
	fclose( $fp );
}

/* Reset options */
function zentropy_form_system_theme_settings_reset( $form, &$form_state ) {
	form_state_values_clean( $form_state );

	variable_del( 'theme_zentropy_settings' );
	
	$fp = fopen( drupal_get_path( 'theme', 'zentropy' ) . '/css/custom.css', 'a' );
	ftruncate( $fp, 0 );
	fclose( $fp );

	drupal_set_message( t( 'The configuration options have been reset to their default values.' ) );
}