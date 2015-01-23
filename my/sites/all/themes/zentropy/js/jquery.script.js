(function($) {
	$(window).load(function() {
		$('.foreground').toggle('slow');
		
		// Back to Top Button
		$().UItoTop({
			easingType: 'easeOutQuart',
			containerID: 'backtotop'
		});
	});
	
	$(function() {
		// Smoothscroll
		if ($('html').hasClass('desktop')) {
			$.srSmoothscroll({
				step: 150,
				speed: 800
			});
		}
		
		// Mobile menu
		$('#superfish-1').mobileMenu();
		
		// Portfolio img hover
		$('.isotope-element .views-field-field-portfolio-image a')
			.mouseover(function() {
					$(this).find('img').stop().animate({opacity:'.4'})
			})
			.mouseout(function() {
				$(this).find('img').stop().animate({opacity:'1'})
			});
	});

	$(document).ready(function($) {
		// Portfolio
		$("#isotope-options .option-set li a[data-option-value='.all']").addClass("selected");
		
		if ($(".isotope-masonry").length) {
			var $container = $('#isotope-container');

			$container.imagesLoaded( function() {
				$container.isotope({
					itemSelector		: '.isotope-element',
					resizable			: false,
					transformsEnabled	: true,
					layoutMode			: 'masonry',
				});
			});

		}
		
		if ($(".isotope-grid").length) {
			var $container = $('#isotope-container');

			$container.imagesLoaded( function() {
				setColumnWidth();
				$container.isotope({
					itemSelector		: '.isotope-element',
					resizable			: false,
					transformsEnabled	: true,
					layoutMode			: 'fitRows',
				});
			});

			function getNumColumns() {
				var $folioWrapper = $('.isotope-grid'),
					containerWidth = $("#isotope-container").width(),
					column = 3;

				if ($folioWrapper.hasClass('1-col')) {
					column = 1;
					return column;
				}
				else if ($folioWrapper.hasClass('2-col')) {
					column = 2;
					if (containerWidth < 380) {
						column = 1;
					}
					return column;
				}
				else if ($folioWrapper.hasClass('3-col')) {
					column = 3;
					if (containerWidth < 380) {
						column = 1;
					}
					else if ((containerWidth >= 380) && (containerWidth < 788)) {
						column = 2;
					}
					else if (containerWidth >= 788) {
						column = 3;
					}
					return column;
				}
				else if ($folioWrapper.hasClass('4-col')) {
					column = 4;
					if (containerWidth < 380) {
						column = 1;
					}
					else if ((containerWidth >= 380) && (containerWidth < 788)) {
						column = 2;
					}
					else if ((containerWidth >= 788) && (containerWidth < 940)) {
						column = 3;
					}
					else if (containerWidth >= 940) {
						column = 4;
					}
					return column;
				}
			}

			function setColumnWidth() {
				var columns = getNumColumns(),
					containerWidth = $("#isotope-container").width(),
					postWidth;

				switch (columns) {
					case 1:
						postWidth = containerWidth - 30;
						break;
					case 2:
						postWidth = (containerWidth - 60)/columns;
						break;
					case 3:
						postWidth = (containerWidth - 90)/columns;
						break;
					case 4:
						postWidth = (containerWidth - 120)/columns;
						break;
					default:
						postWidth = (containerWidth - 90)/columns;
						break;
				}

				postWidth = Math.floor(postWidth);

				$(".isotope-element").each(function(index) {
					$(this).css({"width" : postWidth + "px"});
				});
			}

			function arrange() {
				setColumnWidth();
				$container.isotope('reLayout');
			}

			$(window).on("debouncedresize", function(event) {
				arrange();
			});
		};

		if ($.cookie('the_cookie') == 0) {
			styleSwitch(0)
		}

		function styleSwitch(cookie) {
			if (cookie == 0) {
				$('#style-mobile').remove();
				$('#skeleton-mobile').remove();
				$('.switcher').text("Responsive Version");
				$.cookie('the_cookie', 0);
			} else {
				$('head').append('<link rel="stylesheet" href="<?php echo base_path().path_to_theme() ?>/css/style-mobile.css" media="screen" id="style-mobile">');
				$('head').append('<link rel="stylesheet" href="<?php echo base_path().path_to_theme() ?>/css/skeleton-mobile.css" media="screen" id="skeleton-mobile">');
				$('.switcher').text("Desktop Version only");
				$.cookie('the_cookie', 1);
			}
		}

		$('.switcher').click(function() {
			styleSwitch($.cookie('the_cookie') == 0 ? 1 : 0);
			location.reload();
		});
	});
	
	$(document).ready(function () {
		// Sticky menu
		if (($(window).width() > 995) && ($('#header .stickup').length)) {
			$('#header .stickup').tmStickUp({});
		}
		
		// Contact form validation
		var my_form_id = new tFormer('contact-site-form', {
			fields: {
				name: {
					rules: "*"
				},
				mail: {
					rules: "* @"
				},
				subject: {
					rules: "*"
				},
				message: {
					rules: "*"
				}
			}
		});
		
		// Contact form tooltips
		$(".contact-form label[for='edit-name']").attr('data-title', 'Enter your name here');
		$(".contact-form label[for='edit-mail']").attr('data-title', 'Enter your contact Email here');
		$(".contact-form label[for='edit-subject']").attr('data-title', 'Enter the subject of your message here');
		$(".contact-form label[for='edit-message']").attr('data-title', 'Enter your message here');
		$(".contact-form label[for='edit-copy']").attr('data-title', 'Check to send coty to yourself');
		$(".contact-form .form-item-name").append('<div class="messages error">This field is required!</div>');
		$(".contact-form .form-item-mail").append('<div class="messages error">This field is required!<br>Please enter a valid email address!</div>');
		$(".contact-form .form-item-subject").append('<div class="messages error">This field is required!</div>');
		$(".contact-form .form-item-message .form-textarea-wrapper").append('<div class="messages error">This field is required!</div>');
		
		// Bg video
		$(".video_bg").mb_YTPlayer();
	});
})(jQuery);