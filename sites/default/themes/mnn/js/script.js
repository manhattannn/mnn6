/************************************************* site ****************************************************/
var site = (function(){

  function init(){
    imageCaptions();
    setupWatermark();
    inPageScroll();
    setupModal();
    setupSelectAll();
    setContentSidebarHeights();
  }

  function setContentSidebarHeights(){
    if ($('#content-inner').length && $('#sidebar-second').length){
      var extra = Math.abs($('#content-inner').outerHeight(true) - $('#sidebar-second').outerHeight(true));
      if ($('#content-inner').outerHeight(true) > $('#sidebar-second').outerHeight(true)){
        $('#sidebar-second').height($('#sidebar-second').height() + extra);
      }
      else{
        $('#content-inner').height($('#content-inner').height() + extra);
      }
    }
  }

  function imageCaptions(){
    var selectors = '.node img';
    $(selectors).each(function() {
      var caption = $(this).attr('title');
      if (caption){
        var parts = caption.split('|');
        var captions = '';
        for (var i = 0; i < parts.length; i++){
          captions += '<div class="caption">' + parts[i] + '</div>'
        }
        var style = $(this).attr('style');
        $(this).attr('style', '');
        $(this).wrap('<div class="image-wrapper" style="'+ style +'" />').after(captions);
      }
    });
  }

  function setupWatermark(){
    $('#footer #edit-submitted-name').watermark('Your Name');
    $('#footer #edit-submitted-email-address').watermark('Your Email');
    $('#footer #edit-submitted-message').watermark('Your message goes here');
    $('#footer #mce-EMAIL').watermark('Enter your email address');
  }

  function setupModal(){
    $('.modal-trigger').click(function(){
      var el = $(this).attr('data-modal-element');
      $('#' + el).modal();
      return false;
    });
  }

  function setupSelectAll(){
    $('textarea.select-all')
      .click(function(){
        $(this).select();
      })
      .mouseup(function(e){
        e.preventDefault();
      })
    ;
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

  function loadPageFromSelect(list) {
    var link = list.options[list.selectedIndex].value.toLowerCase();
    location.href = link;
  }

  return {
    init: init,
    loadPageFromSelect: loadPageFromSelect
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
    $('<a href="#" class="left"><span></span></a><a href="#" class="right"><span></span></a>').appendTo($('#slideshow-buttons'));
  }

  function setupEvents(){
    $('#slideshow-buttons a.right').click(function(event){
      var outgoing = $('#block-views-homepage-slideshow .views-row.current').removeClass('current');
      var incoming = outgoing.next('#block-views-homepage-slideshow .views-row');
      if (incoming.length <= 0)
        incoming = $('#block-views-homepage-slideshow .views-row-first');
      incoming.addClass('current');
      showItem(outgoing, incoming, 'right');
      shouldRun = false; // stop slideshow from running
      event.preventDefault();
    });
      $('#slideshow-buttons a.left').click(function(event){
      var outgoing = $('#block-views-homepage-slideshow .views-row.current').removeClass('current');
      var incoming = outgoing.prev('#block-views-homepage-slideshow .views-row');
      if (incoming.length <= 0)
        incoming = $('#block-views-homepage-slideshow .views-row-last');
      incoming.addClass('current');
      showItem(outgoing, incoming, 'left');
      shouldRun = false; // stop slideshow from running
      event.preventDefault();
    });
  }

  function showItem(outgoing, incoming, direction){
    outgoing.find('.pinch').fadeOut(fadeSpeed / 2);
    outgoing.fadeOut(fadeSpeed);
    incoming.fadeIn(fadeSpeed / 2, function(){
      incoming.find('.pinch').fadeIn(fadeSpeed / 2);
    });
  }

  // function showItem(outgoing, incoming, direction){
  //  var viewWidth = $('#block-views-homepage-slideshow .view').width();
  //  if (direction == 'left'){
  //    var left = '-' + viewWidth + 'px';
  //    incoming.css('left', viewWidth + 'px');
  //  }
  //  else{
  //    var left = viewWidth + 'px';
  //    incoming.css('left', '-' + viewWidth + 'px');
  //  }

  //  outgoing.animate({
  //    left: left
  //  }, slideSpeed);
  //  incoming.animate({
  //    left: '0'
  //  }, slideSpeed);
  // }

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


/********************************************* sidebarMenu *************************************************/
var sidebarMenu = (function(){

  function init(){
    if ($('.sidebar .block-menu li.expanded').length)
      setupEvents();
  }

  function setupEvents(){
    $('.sidebar .block-menu li.expanded > a').click(function(event){
      $(this).next('ul.menu').slideToggle();
      event.preventDefault();
    });
  }

  return {
    init: init
  }
})();


/************************************************* faq *****************************************************/
var faq = (function(){

  function init(){
    if ($('.view-faq-pages').length)
      setupEvents();
  }

  function setupEvents(){
    $('.view-faq-pages .question').click(function(event){
      $(this).next('.answer').slideToggle();
      event.preventDefault();
    });
  }

  return {
    init: init
  }
})();


/*********************************************** calendar **************************************************/
var calendar = (function(){

  function init(){
    if ($('div.calendar-calendar').length){
      $.ajax({
        url: 'http://'+document.domain+'/sites/default/themes/mnn/js/jquery-ui-1.8.14.custom.min.js',
        dataType: "script",
        success: function(){
          setup();
        }
      });
    }
    if ($('div.calendar-calendar div.day-view').length){
      $('.calendar-calendar > ul.links li.calendar-month a').html('&laquo; Back to Month view')
      $('.calendar-calendar > ul.links li.calendar-month').css('left', 0);
    }
  }

  function setup(){
    $('<input type="text" id="date-picker" name="date-picker">').appendTo($('div.calendar-calendar .date-heading h3'));
    $('#date-picker').datepicker({
      dateFormat: 'yy-mm-dd',
      onClose: function(dateText, inst){
        location.href = '/calendar/' + dateText;
      },
      showOn: 'button',
      buttonImageOnly: true,
      buttonImage: '/sites/default/themes/mnn/images/icon_calendar.png'
    });

  }

  return {
    init: init
  }
})();


/********************************************** openClose **************************************************/
var openClose = (function(){

  function init(){
    if ($('.open-close-container').length){
      generateHtml();
      setupEvents();
    }
  }

  function setupEvents(){
    $('a.opener-closer').click(function(event){
      $(this).parent().next('.open-close-container').slideToggle();
      event.preventDefault();
    });
    $('.open-close-container div.closer a').click(function(event){
      $(this).parent().parent('.open-close-container').slideToggle();
      event.preventDefault();
    });
  }

  function generateHtml(){
    $('.open-close-container').append('<div class="closer"><a href="#">x Hide</a></div>');
  }

  return {
    init: init
  }
})();

/****************************************** electionSlideshow **********************************************/
var electionSlideshow = (function() {
  var slideSpeed = 1500;            // speed of transition from one slide to the next
  var cycleTime = 5000;             // time between transition end and transition begin
  var defaultDirection = 'left';

  /************************* do not change anything below this line *************************/

  var shouldRun = false;
  var id = '';

  function init(){
    if ($('.node.election-district').length) {
      id = '#' + $('.node.election-district').attr('id');
      $(id + ' .item:first-child').addClass('current');
      var count = $(id + ' .item').length;
      if (count > 0) {
        alterHtml(count);
        setupEvents();
        window.setTimeout('electionSlideshow.cycle()', cycleTime + slideSpeed);
      }
    }
  }

  function alterHtml(numItems) {
    $('<div id="slideshow-buttons"/>').appendTo($(id + ' .photo-video'));
    $('<a href="#" class="left"><span></span></a><a href="#" class="right"><span></span></a>').appendTo($('#slideshow-buttons'));
    var indicators = new Array();
    for (var i = 0; i < numItems; i++) {
      indicators.push('<span></span>');
    };
    $(id + ' .photo-video').append('<div id="indicators">' + indicators.join('') + '</div>');
    $('#indicators span:first-child').addClass('current');
  }

  function setupEvents(){
    $('#slideshow-buttons a.right').click(function(event) {
      showItem('left');
      shouldRun = false; // stop slideshow from running
      event.preventDefault();
    });
    $('#slideshow-buttons a.left').click(function(event) {
      showItem('right');
      shouldRun = false; // stop slideshow from running
      event.preventDefault();
    });
    $(id + ' .photo-video').click(function() {
      shouldRun = false;
    });
  }

  function showItem(direction) {
    var outgoing = $(id + ' .item.current').removeClass('current');
    if (direction == 'left') {
      var incoming = outgoing.next(id + ' .item');
      if (incoming.length <= 0) {
        incoming = $(id + ' .item:first');
      }
    }
    else {
      var incoming = outgoing.prev(id + ' .item');
      if (incoming.length <= 0) {
        incoming = $(id + ' .item:last');
      }
    }
    incoming.addClass('current');

    var incomingIndex = $(id + ' .item').index($($(id + ' .item.current')));
    $('#indicators span').removeClass('current');
    $($('#indicators span').get(incomingIndex)).addClass('current');

    var containerWidth = $(id + ' .photo-video').width() + 30; // 30  is a bit of spacing
    if (direction == 'left') {
      var left = '-' + containerWidth + 'px';
      incoming.css('left', containerWidth + 'px');
    }
    else {
      var left = containerWidth + 'px';
      incoming.css('left', '-' + containerWidth + 'px');
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
      showItem(defaultDirection);
      window.setTimeout('electionSlideshow.cycle()', cycleTime + slideSpeed);
    }
  }

  return {
    init: init,
    cycle: cycle
  }
})();

/******************************************* electionVideos ************************************************/
var electionVideos = (function(){

  var wrapper = '';
  var $el = '';
  var itemWidth = 0;
  var elWidth = 0;

  function init(){
    if ($('.view-election-video-thumbnail-grid-carousel').length) {
      wrapper = '.view-election-video-thumbnail-grid-carousel .view-content';
      $el = $(wrapper + ' ul:first');
      elWidth = $(wrapper + ' ul').outerWidth();
      itemWidth = elWidth / $el.children('li').length;
      alterHtml();
      setupEvents();
    }
  }

  function alterHtml(numItems) {
    $('<div id="video-carousel-buttons"/>').appendTo($(wrapper));
    $('<a href="#" class="left"></a><a href="#" class="right"></a>').appendTo($('#video-carousel-buttons'));
  }

  function setupEvents(){
    $('#video-carousel-buttons a.right').click(function(event) {
      event.preventDefault();
      scrollItem('left');
    });
    $('#video-carousel-buttons a.left').click(function(event) {
      event.preventDefault();
      scrollItem('right');
    });
  }

  var lpos = 0;
  function scrollItem(direction) {
    // 4 items show, so get width of the items not showing.
    var widthHiddenItems = elWidth - (itemWidth * 4);
    if (direction == 'left') {
      if (lpos > -(widthHiddenItems - 10)) { // a small buffer
        lpos -= itemWidth;
      }
      else {
        lpos = 0;
      }
    }
    else { // right
      if (lpos < -10) { // a small buffer
        lpos += itemWidth;
      }
      else {
        lpos = -widthHiddenItems;
      }
    }

    $el.animate({
      left: lpos
    }, 500);
  }

  return {
    init: init
  }
})();



$(document).ready(function(){
  homeSlideshow.init();
  site.init();
  sidebarMenu.init();
  faq.init();
  calendar.init();
  openClose.init();
  electionSlideshow.init();
  electionVideos.init();
});
