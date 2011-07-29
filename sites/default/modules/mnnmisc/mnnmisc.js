var newsArchive = (function(){

	function init(){
		setupEvents();
	}

	function setupEvents(){
		$('ul.news-archive li.year > a').click(function(event){
			if ($(this).parent('li').hasClass('collapsed')){
				$(this).parent('li').removeClass('collapsed').addClass('expanded');
				$(this).next('ul').slideDown();
			}
			else{
				$(this).parent('li').removeClass('expanded').addClass('collapsed');
				$(this).next('ul').slideUp();
			}
			event.preventDefault();
		});
	}

	return {
		init: init
	}
})();

$(document).ready(function(){
	if ($('ul.news-archive').length)
		newsArchive.init();
});