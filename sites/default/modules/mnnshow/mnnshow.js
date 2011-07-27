var schedule = (function(){

	var schedDate = '';
	var prevDate = '';
	var nextDate = '';
	var offset;

	function init(){
		generateHtml();
		offset = $('#schedule-header').offset().top;
		setupEvents();
		loadTableHeader()
		//loadSchedule('2011-05-15');
		loadSchedule(schedDate);
	}

	function generateHtml(){
		var nav = '<a href="#" class="prev"><span>Previous</span></a><a href="#" class="next"><span>Next</span></a>';
		nav += '<div class="schedule-date"><time></time><input type="text" id="date-picker" name="date-picker"></div> ';
		$('#schedule-header .nav').html(nav);
	}

	function setupEvents(){
		$('#schedule-header .nav a.prev').click(function(){
			loadSchedule(prevDate);
			return false;
		});
		$('#schedule-header .nav a.next').click(function(){
			loadSchedule(nextDate);
			return false;
		});

		$(window).scroll(function(){
		/*	var cols = $('#cols').offset().top + $('#cols').outerHeight();
			var header = $('#schedule-header .inner').offset().top + $('#schedule-header .inner').outerHeight();
			console.log('cols: '+cols);
			console.log('header: '+header);
			if (cols < header) {
				$('#schedule-header .inner').css('position', 'relative').removeClass('floating');
			}
			else */
			if ($(window).scrollTop() >= offset){
				$('#schedule-header .inner').css('position', 'fixed').addClass('floating');
			}
			else {
				$('#schedule-header .inner').css('position', 'relative').removeClass('floating');
			}
		});
		$('#date-picker').datepicker({
			onClose: function(dateText, inst){
				if (dateText != schedDate){
					loadSchedule(dateText);
				}
			},
			showOn: 'button',
			buttonImageOnly: true,
			buttonImage: '/sites/default/themes/mnn/images/icon_calendar.png'
		});
	}

	function loadTableHeader(){
		$.ajax({
			type: 'POST',
			url: '/schedule/header',
			dataType: 'json',
			success: function(data){
				var cols = '';

				var col = '<div class="col col-time">';
				col += '<div class="cell heading time"></div>';
				col += '</div>';
				cols += col;

				for (var i = 1; i <= 4; i++ ){
					col = '<div class="col col-' + i + '">';
					col += '<div class="cell heading ch'+i+'">'+data['channel'+i].name+'</div>';
					col += '</div>';
					cols += col;
				}

				$('#schedule-header .channels').html(cols);
				$('#schedule-header').height($('#schedule-header .nav').outerHeight() + $('#schedule-header .channels').outerHeight()); // fix the height
			}
		});
	}

	function loadSchedule(date){
		$.ajax({
			type: 'POST',
			url: '/schedule/get',
			dataType: 'json',
			data: 'date=' + date,
			success: function(data){
				schedDate = data.schedDate;
				prevDate = data.prevDate;
				nextDate = data.nextDate;
				$('#schedule-header .schedule-date time').html(data.displayDate);

				var cols = '';

				var colTime = '<div class="col col-time">';
				var current;
				for (var i = 0; i < 48; i++){
					data.time[i].isCurrent == 'true' ? current = ' current' : current = '';
					colTime += '<div class="cell cell-'+i+' t30'+current+'">'+ data.time[i].display + '</div>';
				}
				colTime += '</div>';
				cols += colTime;

				for (var i = 1; i <= 4; i++ ){
					var col = '<div class="col col-' + i + '">';
					var channel = data['ch' + i];
					for (var j = 0; j < channel.length; j++){
						var content = channel[j].title;
						var link = '<a href="'+channel[j].link+'">'+content+'</a>';
						var category = '<div class="category">'+channel[j].category+'</div>';
						channel[j].isCurrent == 'true' ? current = ' current' : current = '';
						var cls = 'cell cell-' + j + ' t' + channel[j].duration + ' s' + channel[j].start + current;
						col += '<div class="'+ cls +'">'+link+category+'</div>';
					}
					col += '</div>';
					cols += col;
				}
				$('#schedule #cols').html(cols);
			}
		});
	}

	return {
		init: init
	}
})();

$(document).ready(function(){
	if ($('#schedule').length)
		schedule.init();
});
