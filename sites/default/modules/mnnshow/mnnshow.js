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
				$('#schedule-header .schedule-date .time').html(data.displayDate);

				var cols = '';

				var colTime = '<div class="col col-time">';
				var current, primetime;
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
						channel[j].isPrimetime == 'true' ? primetime = ' primetime' : primetime = '';
						var cls = 'cell cell-' + j + ' t' + channel[j].duration + ' s' + channel[j].start + current + primetime;
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

var geolocator = (function() {

	var map, community_boards, masks;

	function init(){
		initializeMap();
	}
	
	function setCommunityBoard(i) {
		$("#geolocation .viewcommunity a").attr('href', community_boards[i].url);
		$("#block-mnnshow-schedule-channel-listing .locator").html("We have you located in <span>" + community_boards[i].name + "</span> which is located in Community Board " + community_boards[i].id + ".");
	}

	function guessPosition(position) {
		var location = new google.maps.LatLng(position.coords.latitude, position.coords.longitude);
		var image = 'images/icon_marker.png';
		var beachMarker = new google.maps.Marker({
			position: location,
			map: map,
			icon: image
		});
		for (var i = 0; i < community_boards.length; i++) {
			if (community_boards[i].polygon.containsLatLng(location)) {
				setCommunityBoard(i);
				return;
			}
		}
		$("#block-mnnshow-schedule-channel-listing .locator").html("Uh oh, it looks like you are not located in Manhattan. Select a neighborhood from the list below:");
	}

	function initializeMap() {
		var myLatLng = new google.maps.LatLng(40.78803, -73.97603);
		var myOptions = {
			zoom: 12,
			maxZoom: 16,
			minZoom: 12,
			disableDefaultUI: false,
			draggable: true,
			center: myLatLng,
			mapTypeId: google.maps.MapTypeId.TERRAIN
		};

		map = new google.maps.Map(document.getElementById("map_canvas"),
			myOptions);

		if (navigator.geolocation) {
			$("#block-mnnshow-schedule-channel-listing .locator").html("We are looking for your location. In the meantime, select a neighborhood from the list below:")
			navigator.geolocation.getCurrentPosition(guessPosition);
		} else {
			$("#block-mnnshow-schedule-channel-listing .locator").html("We are having trouble locating you, select a neighborhood from the list below:")
		}

		masks = [
			{ name: 'New Jersey',
				coords: [ new google.maps.LatLng(40.708890000000004, -74.02932000000001),
					new google.maps.LatLng(40.756240000000005, -74.01559),
					new google.maps.LatLng(40.80069, -73.98366),
					new google.maps.LatLng(40.875240000000005, -73.93971),
					new google.maps.LatLng(40.93829, -73.91293),
					new google.maps.LatLng(41.0018, -73.89233),
					new google.maps.LatLng(41.08854, -73.88306),
					new google.maps.LatLng(41.15992000000001, -74.06846),
					new google.maps.LatLng(40.777300000000004, -74.36234),
					new google.maps.LatLng(40.60757, -74.38294),
					new google.maps.LatLng(40.62738, -74.19892) ] },
			{ name: 'Brooklyn',
				coords: [ new google.maps.LatLng(40.780414536257766, -73.93696270751954),
					new google.maps.LatLng(40.77105494627509, -73.93799267578126),
					new google.maps.LatLng(40.74426883634677, -73.96442852783204),
					new google.maps.LatLng(40.722415863664885, -73.96648846435548),
					new google.maps.LatLng(40.70758297322998, -73.97369824218751),
					new google.maps.LatLng(40.70628168483743, -73.9949842529297),
					new google.maps.LatLng(40.694568945107584, -74.00940380859376),
					new google.maps.LatLng(40.686498970792314, -74.0114637451172),
					new google.maps.LatLng(40.67087688935766, -74.03309307861329),
					new google.maps.LatLng(40.61903744846981, -74.05128918457032),
					new google.maps.LatLng(40.573155952262475, -74.0169569091797),
					new google.maps.LatLng(40.565853720399716, -73.93558941650392),
					new google.maps.LatLng(40.62867898459473, -73.86383496093751),
					new google.maps.LatLng(40.691184881319145, -73.88855419921876),
					new google.maps.LatLng(40.77443495032201, -73.83980236816407) ] }
		]

		for (var i = 0; i < masks.length; i++) {
			var polygon = new google.maps.Polygon({
				paths: masks[i].coords,
				strokeColor: '#F0EFE9',
				strokeWeight: 2,
				strokeOpacity: 0,
				fillColor: '#F0EFE9',
				fillOpacity: 0
			});
			polygon.setMap(map);
		}

		community_boards = [
			{ name: 'Manhattan',
				id: 1,
				strokeColor: '#0e75bb',
				fillColor: '#ffffff',
				url:'/communityboard1',
				coords: [ new google.maps.LatLng(40.729444352424565, -73.97206997805176),
					new google.maps.LatLng(40.72163880424218, -73.97318577700196),
					new google.maps.LatLng(40.7108396201733, -73.97730565004883),
					new google.maps.LatLng(40.70979864240353, -73.99224018984376),
					new google.maps.LatLng(40.704170000000005, -74.00605),
					new google.maps.LatLng(40.70804195551534, -73.99910664492188),
					new google.maps.LatLng(40.702055859630036, -74.00992131166993),
					new google.maps.LatLng(40.701665443383625, -74.0155003064209),
					new google.maps.LatLng(40.70888777350549, -74.0180752270752),
					new google.maps.LatLng(40.74661333586301, -74.01009297304688),
					new google.maps.LatLng(40.76052736599142, -74.0027115338379),
					new google.maps.LatLng(40.84213231279408, -73.94717907839356),
					new google.maps.LatLng(40.87764068065133, -73.92718052797852),
					new google.maps.LatLng(40.87309771033151, -73.91104435854493),
					new google.maps.LatLng(40.857779113157264, -73.92108654909669),
					new google.maps.LatLng(40.83485951320739, -73.93524861269532),
					new google.maps.LatLng(40.809333466949845, -73.93473362856446),
					new google.maps.LatLng(40.80127740851298, -73.92924046450196),
					new google.maps.LatLng(40.79445498150456, -73.93087124758301),
					new google.maps.LatLng(40.77391849474478, -73.93928265505372),
					new google.maps.LatLng(40.74817393280889, -73.95945286684571),
					new google.maps.LatLng(40.74817393280889, -73.95945286684571)] }
		]

		for (var i = 0; i < community_boards.length; i++) {
			community_boards[i].polygon = new google.maps.Polygon({
				paths: community_boards[i].coords,
				strokeColor: community_boards[i].strokeColor,
				strokeOpacity: 0.8,
				strokeWeight: 2,
				fillColor: community_boards[i].fillColor,
				fillOpacity: 0.7,
				community_board_index: i
			});
			google.maps.event.addListener(community_boards[i].polygon, 'click', selectPolygon)
			community_boards[i].polygon.setMap(map);
		}

		function selectPolygon(event) {
			resetCommunityBoardColors();
			this.setOptions({ fillColor: '#0e75bb', strokeColor: '#0e75bb' });
			setCommunityBoard(this.community_board_index);
		}

		function resetCommunityBoardColors() {
			for (var i = 0; i < community_boards.length; i++) {
				community_boards[i].polygon.setOptions({ fillColor: community_boards[i].fillColor, strokeColor: community_boards[i].strokeColor })
			}
		}

	}

	return {
		init: init
	}
})();

$(document).ready(function(){
	if ($('#schedule').length){
		schedule.init();
		geolocator.init();
	}
});
