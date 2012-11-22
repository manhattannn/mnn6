var schedule = (function(){

	var schedDate = '';
	var prevDate = '';
	var nextDate = '';
	var offset, table, headerHeight;

	function init(){
		generateHtml();
		offset = $('#schedule-header').offset().top;
		loadTableHeader();
		//loadSchedule('2011-05-15');
		loadSchedule(schedDate);
	}

	function generateHtml(){
		var nav = '<a href="#" class="prev"><span>Previous</span></a><a href="#" class="next"><span>Next</span></a>';
		nav += '<div class="schedule-date"><span class="time"></span><input type="text" id="date-picker" name="date-picker"></div> ';
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
			if ($(window).scrollTop() > (table - headerHeight)){
				var top = $('#schedule').height() - headerHeight;
				$('#schedule-header .inner').css('position', 'absolute').addClass('floating').css('top', top);
			}
			else if ($(window).scrollTop() >= offset){
				$('#schedule-header .inner').css('position', 'fixed').addClass('floating').css('top', 0);
			}
			else {
				$('#schedule-header .inner').css('position', 'relative').removeClass('floating').css('top', 0);
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
				headerHeight = $('#schedule-header').outerHeight();
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
				$('#schedule-header .schedule-date .time').html(data.displayDate);

				var cols = '';

				var colTime = '<div class="col col-time">';
				var current, primetime;
				for (var i = 0; i < 48; i++){
					data.time[i].isCurrent == 'true' ? current = ' current' : current = '';
					data.time[i].isPrimetime == 'true' ? primetime = ' primetime' : primetime = '';
					colTime += '<div class="cell cell-'+i+' t'+data.time[i].duration+' s'+data.time[i].start+current+primetime+'"><div class="cell-inner">'+ data.time[i].display + '</div></div>';
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
						channel[j].isPrimetime == 'true' ? primetime = ' primetime' : primetime = '';
						var cls = 'cell cell-' + j + ' t' + channel[j].duration + ' s' + channel[j].start + current + primetime;
						col += '<div class="'+ cls +'"><div class="cell-inner">'+link+category+'</div></div>';
					}
					col += '</div>';
					cols += col;
				}
				$('#schedule #cols').html(cols);
				table = $('#schedule').offset().top + $('#schedule').outerHeight();
				setupEvents();
			}
		});
	}

	return {
		init: init
	}
})();


var ycSchedule = (function(){

	var schedDate = '';
	var prevDate = '';
	var nextDate = '';
	var offset, table, headerHeight;
	var isEventsSetup = false;

	function init(){
		generateHtml();
		offset = $('#schedule-header').offset().top;
		// loadTableHeader(); // Is this needed?
		//loadSchedule('2011-05-15');
		loadSchedule(schedDate);
	}

	function generateHtml(){
		var nav = '<a href="#" class="prev"><span>Previous</span></a><a href="#" class="next"><span>Next</span></a>';
		nav += '<div class="schedule-date"><span class="time"></span><input type="text" id="date-picker" name="date-picker"></div> ';
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
			if ($(window).scrollTop() > (table - headerHeight)){
				var top = $('#schedule').height() - headerHeight;
				$('#schedule-header .inner').css('position', 'absolute').addClass('floating').css('top', top);
			}
			else if ($(window).scrollTop() >= offset){
				$('#schedule-header .inner').css('position', 'fixed').addClass('floating').css('top', 0);
			}
			else {
				$('#schedule-header .inner').css('position', 'relative').removeClass('floating').css('top', 0);
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

		isEventsSetup = true;
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
				headerHeight = $('#schedule-header').outerHeight();
			}
		});
	}

	function loadSchedule(date){
		$.ajax({
			type: 'POST',
			url: '/youth-channel/schedule/get',
			dataType: 'json',
			data: 'date=' + date,
			success: function(data){
				schedDate = data.schedDate;
				prevDate = data.prevDate;
				nextDate = data.nextDate;
				$('#schedule-header .schedule-date .time').html(data.displayDate);

				//--- weekday row html
				(function(){
					var wdRows = '';
					// time row
					var wdRowTime = '<div class="row row-time"><div class="cell day empty"><div class="inner" /></div>';
					for (var i = 0; i < data.timeRow.weekday.length; i++){
						wdRowTime += '<div class="cell cell-'+i+' t60"><div class="inner">'+ data.timeRow.weekday[i] + '</div></div>';
					}
					wdRowTime += '</div>';
					wdRows += wdRowTime;

					// show rows
					for (var i = 1; i <= 5; i++){
						var wdShowRow = '<div class="row row-shows" id="row-'+i+'">';
						wdShowRow += '<div class="cell day"><div class="inner">'+data.dayCol.weekday[i]+'</div></div>';
						wdShowRow += '</div> ';
						wdRows += wdShowRow;
					}

					// insert html
					$('#yc-schedule #weekday .rows').html(wdRows);
				})();

				//--- weekend rows html
				(function(){
					var weRows = '';
					// time row
					var weRowTime = '<div class="row row-time"><div class="cell day empty"><div class="inner" /></div>';
					for (var i = 0; i < data.timeRow.weekend.length; i++){
						weRowTime += '<div class="cell cell-'+i+' t60"><div class="inner">'+ data.timeRow.weekend[i] + '</div></div>';
					}
					weRowTime += '</div>';
					weRows += weRowTime;

					// show rows
					for (i = 6; i <= 7; i++){
						var weShowRow = '<div class="row row-shows" id="row-'+i+'">';
						weShowRow += '<div class="cell day"><div class="inner">'+data.dayCol.weekend[i]+'</div></div>';
						weShowRow += '</div> ';
						weRows += weShowRow;
					}

					// insert html
					$('#yc-schedule #weekend .rows').html(weRows);
				})();

				var current;

				function cell(day, idx){
					var content = day[idx].title;
					var link = '<div class="link-wrapper"><a href="'+day[idx].link+'">'+content+'</a></div>';
					var category = '<div class="category">'+day[idx].category+'</div>';
					current = day[idx].is_today == 'true' ? ' current' : '';
					var cls = 'cell cell-' + idx + ' t' + day[idx].duration + ' s' + day[idx].start + current;
					return '<div class="'+ cls +'"><div class="inner">'+link+category+'</div></div>';
				}

				// weekday show cells
				(function(){
					for (var i in data.shows.weekday) {
						var shows = '';
						if (Object.keys(data.shows.weekday).length > 0) {
							var numShows = data.shows.weekday[i].length;
							for (var j = 0; j < numShows; j++) {
								var day = data.shows.weekday[i];
								shows += cell(day, j);
							}
						}

						// insert html
						$('#row-' + i).append(shows);
					}
				})();

				// weekend show cells
				(function(){
					for (var i in data.shows.weekend) {
						var shows = '';
						if (Object.keys(data.shows.weekend).length > 0) {
							var numShows = data.shows.weekend[i].length;
							for (var j = 0; j < numShows; j++) {
								var day = data.shows.weekend[i];
								shows += cell(day, j);

								// var content = day[j].title;
								// var link = '<div class="link-wrapper"><a href="'+day[j].link+'">'+content+'</a></div>';
								// var category = '<div class="category">'+day[j].category+'</div>';
								// day[j].is_today == 'true' ? current = ' current' : current = '';
								// var cls = 'cell cell-' + j + ' t' + day[j].duration + ' s' + day[j].start + current;
								// shows += '<div class="'+ cls +'"><div class="inner">'+link+category+'</div></div>';

							}
						}
						// insert html
						$('#row-' + i).append(shows);
					}
				})();



				table = $('#yc-schedule').offset().top + $('#yc-schedule').outerHeight();
				if (!isEventsSetup)
					setupEvents();
			}
		});
	}

	return {
		init: init
	}
})();


Object.keys = Object.keys || (function () {
    var hasOwnProperty = Object.prototype.hasOwnProperty,
        hasDontEnumBug = !{toString:null}.propertyIsEnumerable("toString"),
        DontEnums = [
            'toString',
            'toLocaleString',
            'valueOf',
            'hasOwnProperty',
            'isPrototypeOf',
            'propertyIsEnumerable',
            'constructor'
        ],
        DontEnumsLength = DontEnums.length;

    return function (o) {
        if (typeof o != "object" && typeof o != "function" || o === null)
            throw new TypeError("Object.keys called on a non-object");

        var result = [];
        for (var name in o) {
            if (hasOwnProperty.call(o, name))
                result.push(name);
        }

        if (hasDontEnumBug) {
            for (var i = 0; i < DontEnumsLength; i++) {
                if (hasOwnProperty.call(o, DontEnums[i]))
                    result.push(DontEnums[i]);
            }
        }

        return result;
    };
})();


$(document).ready(function(){
	if ($('#schedule').length){
		schedule.init();
	}
	if ($('#yc-schedule').length){
		ycSchedule.init();
	}
});
