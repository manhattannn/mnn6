var scheduleNowPlaying = (function(){

  function init(){
    loadSchedule();
  }

  function loadSchedule(){

    $.ajax({
      type: 'GET',
      url: Drupal.settings.mnnshow.reportingUrl + '/schedule/now_playing',
      dataType: 'json',
      success: function(data){

        var htmlContent = '',
            i = 0,
            actualTime = data.actual_time;
            channel_info = data.channel_info,
            channels = data.channels;

        htmlContent = "<div class='whats-on-now'>" +
                        "<h3>What's on Now</h3>" +
                        "<time>" + actualTime + "</time>" +
                        "<p class='view-sched'><a href='/schedule'>View Schedule</a></p>" +
                      "</div>";

        htmlContent += "<ul>";

        for (i = 1; i <= 4; i++){
          // Not all data are set! We need to provide
          // empty values for the ones that are not
          // to prevent JS from crashing.
          channel_info[i] = channel_info[i] || {name:'', description:'', watchLiveUrl:'', tvChannels:Array()};
          channels[i] = channels[i] || {id:'', title:'', url:''};

          htmlContent += '<li id="channel' + i + '"><div class="channel-info">' +
                           '<h4>' + channel_info[i].name + '</h4>' +
                           '<h5><a href="/' + channel_info[i].watchLiveUrl + '">' + channels[i].title + '</h5>' +
                           '<p class="watch-now-link"><a href="/' + channel_info[i].watchLiveUrl + '">Watch Now</a></p>' +
                           "<div class='channel-about'>" +
                             "<p class='channel-description'>" + channel_info[i].description + "</p>" +
                             "<ul class='cable-channel-list'>";

          $.each(channel_info[i].tvChannels, function(index, tvStation) {
            htmlContent +=    '<li>' + tvStation.tvStationName +
                                '<span class="cable-number"">' + tvStation.tvStationChannel + '</span>' +
                              '</li>';
          });

          htmlContent +=     "</ul>" +
                           "</div>" +
                         "</div>" + "</li>";

        }

        htmlContent += "</ul>";

        $('#block-mnnshow-2-whats-on-now').parent().html(htmlContent);
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
  if ($('#block-mnnshow-2-whats-on-now').length){
    scheduleNowPlaying.init();
  }
});
