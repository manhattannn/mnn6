var scheduleNowPlaying = (function(){

  function init(){

    actualisePlayingNowList();

    setInterval(function() {
      actualisePlayingNowList();
    }, 30000);
  }

  function actualisePlayingNowList() {
    var d = new Date();
    date = d.mmddyyyyMnn();

    $.ajax({
      type: 'GET',
      url: Drupal.settings.mnnshow.reportingUrl + '/schedule/get' + '?date=' + date,
      dataType: 'json',
      success: function(data){

        var actualDateObj      = new Date(),
            actualTimeMinutes  = actualDateObj.getHours() * 60 + actualDateObj.getMinutes(),
            nowPlayingPrograms = new Array();

        for (var i = 1; i <= 4; i++ ) {
          var channel = data['ch' + i],
              nowPlayingProgramFound = false,
              programCounter = 0;

          while (!nowPlayingProgramFound && programCounter < channel.length) {

            var actualProgramStartTime = channel[programCounter].start.split("-"),
                actualProgramEndTime   = 0;

            actualProgramStartTime = parseInt(actualProgramStartTime[0]) * 60 + parseInt(actualProgramStartTime[1]);
            actualProgramEndTime = actualProgramStartTime + parseInt(channel[programCounter].duration);

            // Check if program being checked is the one
            // that is live on TV.
            if (actualProgramStartTime <= actualTimeMinutes && actualTimeMinutes < actualProgramEndTime) {
              nowPlayingPrograms[i] = channel[programCounter].title;
              nowPlayingProgramFound = true;
            }
            // If currently checked program from schedule has startTime > actual time
            // this means schedule don't have info about actual program so we display '';
            else if (actualProgramStartTime >= actualTimeMinutes) {
              nowPlayingPrograms[i] = '';
              nowPlayingProgramFound = true;
            }

            // Increase conter to move to next program in schedule.
            programCounter++;
          }
        }

        // Update actual time.
        var timeElement = $('div#block-mnnshow-watch-now div.whats-on-now time');
        if (timeElement.length) {
          timeElement.html(actualDateObj.getTimeNowMnnFrontPageFormat());
        }

        // Update html of the frontEnd block.
        for (var i = 1; i <= 4; i++ ) {
          // Get h5 element that holds program title.
          var titleElement = $('div#block-mnnshow-watch-now ul li#channel' + i + ' div.channel-info h5 a');
          if (titleElement.length) {
            titleElement.html(nowPlayingPrograms[i]);
          }
        }
      }
    });
  }

  return {
    init: init
  }
})();

Object.size = function(obj) {
  var size = 0, key;
  for (key in obj) {
    if (obj.hasOwnProperty(key)) size++;
  }
  return size;
};

$(document).ready(function(){
  if ($('#block-mnnshow-watch-now').length){
    scheduleNowPlaying.init();
  }
});

// Enhance Date object's prototype to add
// function to display todays date formatted.
(function ($) {
  Date.prototype.mmddyyyyMnn = function() {
    var yyyy = this.getFullYear().toString();
    var mm = (this.getMonth()+1).toString(); // getMonth() is zero-based
    var dd  = this.getDate().toString();
    return (mm[1]?mm:"0"+mm[0]) + '/' + (dd[1]?dd:"0"+dd[0]) + '/' + yyyy; // padding
  };

  Date.prototype.getTimeNowMnnFrontPageFormat = function() {

    var month_names_short = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'];

    var yyyy  = this.getFullYear().toString(),
        month = month_names_short[this.getMonth()],
        d     = this.getDate().toString(),
        hours = this.getHours(),
        minutes = this.getMinutes(),
        ampm = hours >= 12 ? 'pm' : 'am';

    hours = hours % 12;
    hours = hours ? hours : 12; // the hour '0' should be '12'
    minutes = minutes < 10 ? '0'+minutes : minutes;

    var strTime = hours + ':' + minutes + ' ' + ampm;

    return month + ' ' + d + ', ' + yyyy + ' ' + strTime;
  };

}(jQuery));