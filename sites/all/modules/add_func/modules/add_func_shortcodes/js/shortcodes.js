jQuery(document).ready(function(jQuery) {
	jQuery('.progressbar').each(function() {
		percent = jQuery(this).data('percent');

		jQuery(this).find('.progressbar-background').stop().animate({width: percent + '%'}, 600);
	});
	
	jQuery('.piegraph').easyPieChart({
		easing: 'easeOutBounce',
		size: 200,
		animate: 2000,
		lineCap: 'square',
		barColor: false,
		scaleColor: false,
		onStep: function(a,b,c) {
			jQuery(this.el).find('span.piegraph-percent').text(Math.round(a) + '%');
		}
	});
	
	function number(num, content, target, duration) {
		if (duration) {
			var count = 0,
				speed = parseInt(duration / num),
				interval = setInterval(function() {
					if (count - 1 < num) {
						target.html(count);
					} else {
						target.html(content);
						clearInterval(interval);
					}
					count++;
				}, speed);
		} else {
			target.html(content);
		}
	}

	function counter(duration) {
		jQuery('[id^="add-func-counter"] .num').each(function() {
			jQuery(this).appear(function() {
				var container = jQuery(this),
					num = container.data('num'),
					content = container.data('content');
				number(num, content, container, duration);
			});
		});
	}
	counter(100);
});