// JavaScript Document

$(function(){$('.effext-top')
	.mouseover(function(){$(this).stop().animate({marginTop:'-10px',paddingBottom:'10px'}, 100)})
	.mouseout(function(){$(this).stop().animate({marginTop:'0px',paddingBottom:'0px'}, 100)});
});

$(function(){$('.effect-oppacity')
	.mouseover(function(){$(this).stop().animate({opacity:0.5}, 300)})
	.mouseout(function(){$(this).stop().animate({opacity:1}, 300)});
});