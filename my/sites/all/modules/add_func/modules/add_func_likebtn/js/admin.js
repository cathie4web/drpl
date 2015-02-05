/**
 * Test synchronization.
 */
function testSync( ajaxurl ) {
	jQuery( ".add_func_likebtn_test_sync_container:first img" ).show();
	jQuery( ".add_func_likebtn_test_sync_container:first .add_func_likebtn_test_sync_message" ).hide();

	jQuery.ajax( {
		type: 'POST',
		dataType: "json",
		url: ajaxurl,
		data: {
			add_func_likebtn_account_email: jQuery( "#edit-add-func-likebtn-account-data-email" ).val(),
			add_func_likebtn_account_api_key: jQuery( "#edit-add-func-likebtn-account-data-api-key" ).val()
		},
		success: function( response ) {
			var result_text = '';
			if ( typeof( response.result_text ) != "undefined" ) {
				result_text = response.result_text;
			}
			jQuery( ".add_func_likebtn_test_sync_message:first" ).text( result_text ).show();
			if ( typeof( response.result ) == "undefined" || response.result != "success" ) {
				jQuery( ".add_func_likebtn_test_sync_message" ).css( 'color', 'red' );
				if ( typeof( response.message ) != "undefined" ) {
					var text = jQuery( ".add_func_likebtn_test_sync_message" ).text() + ': ' + response.message;
					jQuery( ".add_func_likebtn_test_sync_message" ).text( text );
				}
			} else {
				jQuery( ".add_func_likebtn_test_sync_message" ).css( 'color', 'green' );
			}
			jQuery( ".add_func_likebtn_test_sync_container:first img" ).hide();
		},
		error: function( response ) {
			jQuery( ".add_func_likebtn_test_sync_message" ).text( 'Error' ).css( 'color', 'red' ).show();
			jQuery( ".add_func_likebtn_test_sync_container:first img" ).hide();
		}
	} );

	return false;
}