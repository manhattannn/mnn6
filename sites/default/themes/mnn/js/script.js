/************************************************* site ****************************************************/
var site = (function(){

	function init(){
		setupWatermark();
		inPageScroll();
	}

	function setupWatermark(){
		$('#edit-submitted-name').watermark('Your Name');
		$('#edit-submitted-email-address').watermark('Your Email');
		$('#edit-submitted-message').watermark('Your message goes here');
	}

	function inPageScroll(){
		// contact us link
		$('#main-menu a.contact-us').attr('href', '#').click(function(event){
			$('html, body').stop().animate({
				scrollTop: $('#block-webform-webform-send-us-a-message').offset().top
			}, 1500);
			event.preventDefault();
		});
	}

	return {
		init: init
	}
})();


/******************************************** homeSlideshow ************************************************/
var homeSlideshow = (function(){
	var fadeSpeed = 500;             // speed of transition from one slide to the next
	//var slideSpeed = 1500;            // speed of transition from one slide to the next
	var cycleTime = 5000;             // time between transition end and transition begin
	var defaultDirection = 'left';

	/************************* do not change anything below this line *************************/

	var shouldRun = true;

	function init(){
		if ($('#block-views-homepage-slideshow').length){
			$('#block-views-homepage-slideshow .views-row-first').addClass('current');
			alterHtml();
			setupEvents();
			var count = $('#block-views-homepage-slideshow .views-row').length;
			if (count > 0)
				window.setTimeout('homeSlideshow.cycle()', cycleTime + fadeSpeed);
		}
	}

	function alterHtml(){
		$('<div id="slideshow-buttons"/>').appendTo($('#block-views-homepage-slideshow .view'));
		$('<a href="#" class="left"></a><a href="#" class="right"></a>').appendTo($('#slideshow-buttons'));
	}

	function setupEvents(){
		$('#slideshow-buttons a.right').click(function(){
			var outgoing = $('#block-views-homepage-slideshow .views-row.current').removeClass('current');
			var incoming = outgoing.next('#block-views-homepage-slideshow .views-row');
			if (incoming.length <= 0)
				incoming = $('#block-views-homepage-slideshow .views-row-first');
			incoming.addClass('current');
			showItem(outgoing, incoming, 'right');
			shouldRun = false; // stop slideshow from running
			return false;
		});
			$('#slideshow-buttons a.left').click(function(){
			var outgoing = $('#block-views-homepage-slideshow .views-row.current').removeClass('current');
			var incoming = outgoing.prev('#block-views-homepage-slideshow .views-row');
			if (incoming.length <= 0)
				incoming = $('#block-views-homepage-slideshow .views-row-last');
			incoming.addClass('current');
			showItem(outgoing, incoming, 'left');
			shouldRun = false; // stop slideshow from running
			return false;
		});
	}

	function showItem(outgoing, incoming, direction){
		outgoing.find('.pinch').fadeOut(fadeSpeed / 2);
		outgoing.fadeOut(fadeSpeed);
		incoming.fadeIn(fadeSpeed / 2, function(){
			incoming.find('.pinch').fadeIn(fadeSpeed / 2);
		});
	}
/*
	function showItem(outgoing, incoming, direction){
		var viewWidth = $('#block-views-homepage-slideshow .view').width();
		if (direction == 'left'){
			var left = '-' + viewWidth + 'px';
			incoming.css('left', viewWidth + 'px');
		}
		else{
			var left = viewWidth + 'px';
			incoming.css('left', '-' + viewWidth + 'px');
		}

		outgoing.animate({
			left: left
		}, slideSpeed);
		incoming.animate({
			left: '0'
		}, slideSpeed);
	}
*/

	function cycle(){
		if (shouldRun){
			var outgoing = $('#block-views-homepage-slideshow .views-row.current').removeClass('current');
			var incoming = outgoing.next('#block-views-homepage-slideshow .views-row');
			if (incoming.length <= 0)
				incoming = $('#block-views-homepage-slideshow .views-row-first');
			incoming.addClass('current');
			showItem(outgoing, incoming, defaultDirection);
			window.setTimeout('homeSlideshow.cycle()', cycleTime + fadeSpeed);
		}
	}

	return {
		init: init,
		cycle: cycle
	}
})();

/************************************************* faq *****************************************************/
var faq = (function(){

	function init(){
		if ($('.view-faq-pages').length)
			setupEvents();
	}

	function setupEvents(){
		$('.view-faq-pages .question').click(function(){
			$(this).next('.answer').slideToggle();
		})
	}

	return {
		init: init
	}
})();



$(document).ready(function(){
	homeSlideshow.init();
	site.init();
	faq.init();
});
