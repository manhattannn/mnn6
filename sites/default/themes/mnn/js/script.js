/************************************************* site ****************************************************/
var site = (function(){

	function init(){
		setupWatermark();
	}

	function setupWatermark(){
		$('#edit-submitted-name').watermark('Your Name');
		$('#edit-submitted-email-address').watermark('Your Email');
		$('#edit-submitted-message').watermark('Your message goes here');
	}

	return {
		init: init
	}
})();


/******************************************** homeSlideshow ************************************************/
var homeSlideshow = (function(){
	var slideSpeed = 1500;            // speed of transition from one slide to the next
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
				window.setTimeout('homeSlideshow.cycle()', cycleTime + slideSpeed);
		}
	}

	function alterHtml(){
		$('<div id="slideshow-buttons"/>').appendTo($('#block-views-homepage-slideshow .view'));
		$('<a href="#" class="left"></a><a href="#" class="right"></a>').appendTo($('#slideshow-buttons'));
	}

	function setupEvents(){
		$('#slideshow-buttons a.left').click(function(){
			var outgoing = $('#block-views-homepage-slideshow .views-row.current').removeClass('current');
			var incoming = outgoing.next('#block-views-homepage-slideshow .views-row');
			if (incoming.length <= 0)
				incoming = $('#block-views-homepage-slideshow .views-row-first');
			incoming.addClass('current');
			showItem(outgoing, incoming, 'left');
			shouldRun = false; // stop slideshow from running
			return false;
		});
		$('#slideshow-buttons a.right').click(function(){
			var outgoing = $('#block-views-homepage-slideshow .views-row.current').removeClass('current');
			var incoming = outgoing.prev('#block-views-homepage-slideshow .views-row');
			if (incoming.length <= 0)
				incoming = $('#block-views-homepage-slideshow .views-row-last');
			incoming.addClass('current');
			showItem(outgoing, incoming, 'right');
			shouldRun = false; // stop slideshow from running
			return false;
		});
	}

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

	function cycle(){
		if (shouldRun){
			var outgoing = $('#block-views-homepage-slideshow .views-row.current').removeClass('current');
			var incoming = outgoing.next('#block-views-homepage-slideshow .views-row');
			if (incoming.length <= 0)
				incoming = $('#block-views-homepage-slideshow .views-row-first');
			incoming.addClass('current');
			showItem(outgoing, incoming, defaultDirection);
			window.setTimeout('homeSlideshow.cycle()', cycleTime + slideSpeed);
		}
	}

	return {
		init: init,
		cycle: cycle
	}
})();




$(document).ready(function(){
	homeSlideshow.init();
	site.init();
});
