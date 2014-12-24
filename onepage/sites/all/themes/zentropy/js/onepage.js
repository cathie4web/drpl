(function($) {
	Drupal.zentropy = Drupal.zentropy || {};

	Drupal.behaviors.onepageAction = {
		attach: function (context) { 
			$(window).load(function() {
				Drupal.zentropy.showMenu();
			});
			$(window).resize(function() {
				Drupal.zentropy.showMenu();
			});
		}
	};

	Drupal.zentropy.showMenu = function() {
		var wrapper = $('#superfish-1');
		if ($(window).scrollTop() > -1) {
			var $page = $('#page');
			$('.front #superfish-1 li a').smoothScroll({
				offset: -($(".stickup").height()),
				speed: 300
			});
		} else {
			$('.front #superfish-1 li a').smoothScroll({
				offset: -($(".stickup").height()),
				speed: 300
			});
		}
	};
})(jQuery);