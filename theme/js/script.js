$(document).ready(function() {
	//superfish menu
	$('#header-menu').superfish({
		delay:			800,
		animation:		{opacity:'show', height:'show'},
		cssArrows:		true
	});
	var setClass = function() {
		if ($(window).width() > 797) {
			$('#header-menu').addClass('sf-menu sf-js-enabled sf-arrows').removeClass('mobile-menu');
		} else {
			$('#header-menu').addClass('mobile-menu').removeClass('sf-menu sf-js-enabled sf-arrows');
		}
	}
	setClass();
	$(window).resize(function() {
		setClass();
	});
	
	$('#header-nav').prepend('<div id="menu-icon"></div>');
	if(($('#header-menu li')).hasClass('current')){
		$("#menu-icon").html($("#header-menu li.current > a").html());
	} else {
		$("#menu-icon").html('Navigate to...');
	}
	$('#menu-icon').on('click', function(){
		$('#header-menu').slideToggle();
		$(this).toggleClass('active');
	});
	$('.mobile-menu li.current:has(ul) > a').on('click', function(event){
		event.preventDefault();
		$(this).next('ul').slideToggle();
		$(this).toggleClass('active');
	});
	
	
	//'back to top' button
	$(function () {
		$('#back-top').on('click', function () {
			$('body,html').animate({
				scrollTop: 0
			}, 800);
			return false;
		});
	});
	
	// main slider
	$('.flexslider.slider').flexslider({
		animation: "fade",
		pauseOnHover: true,
		controlNav: true,
		directionNav: true,
		prevText: "<span class='icon-chevron-sign-left'></span>",
		nextText: "<span class='icon-chevron-sign-right'></span>"
	});
	
	// carousel
	$('.flexslider.carousel').flexslider({
		animation: "slide",
		animationLoop: false,
		itemWidth: 370,
		itemMargin: 30
	});
	
	// gallery
	$('.flexslider.gallery-thumbs').flexslider({
		animation: "slide",
		controlNav: false,
		animationLoop: false,
		slideshow: false,
		itemWidth: 210,
		itemMargin: 5,
		asNavFor: '.flexslider.gallery'
	});
	$('.flexslider.gallery').flexslider({
		animation: "slide",
		controlNav: false,
		animationLoop: false,
		slideshow: false,
		sync: ".flexslider.gallery-thumbs"
	});
	
	// tabs
	$('.tabs').each(function(index, element) {
		$(this).find('dt').first().children('a').addClass('active').parent('dt').next().addClass('is-open').show();
	});
	$('.tabs dt > a').on('click', function(e) {
		e.preventDefault();
		if (!$(this).hasClass('active')) {
			$(this).parent().parent().find('.active').removeClass('active');
			$(this).addClass('active');
			$(this).parent().parent().find('.is-open').removeClass('is-open').hide();
			$(this).parent('dt').next().addClass('is-open').show();
		}
	});
});

$(function() {
	$(".progressbar > div").each(function(index) {
		origWidth = $(this).width()/$(this).parent(".progressbar").width()*100 + "%";
		$(this).width(0);
		$(this).animate({width: origWidth},1500);
	});
	
	
	
	$('.toggle .toggle-trigger').on('click', function(){
		$(this).next('.toggle-content').slideToggle();
		$(this).toggleClass('active');
	});
	
	
	
	$('.calendar').pickmeup({
		date: [new Date, '10-02-2014', '05-01-2014'],
		mode: 'multiple',
		flat: true
	});
});

$(window).load(function() {
	$('.kwicks').kwicks({
		maxSize: '75%',
		spacing: 0,
		behavior: 'menu',
	});
});