<?php

ctools_include('mnnshow.common', 'mnnshow', '');
ctools_include('mnnshow.ycschedule', 'mnnshow', '');

/**
 * Publisher Info block for individual show node.
 */
function mnnshow_block_publisher_info(){
  $path = drupal_get_path_alias($_GET['q']);
  $path = explode('/', $path);
  if ($path[0] == 'show-info' && is_numeric($path[1])) {
    $sql = 'SELECT DISTINCT s.project_id, s.public_contact_info AS name, s.public_email_value AS email ';
    $sql .= 'FROM {ac_report_project_cache} s ';
    $sql .= 'WHERE s.project_id = "' . $path[1] . '"';
    // $sql = 'SELECT DISTINCT s.project_id, p.producer_id, p.display_name, p.email, p.phone_primary ';
    // $sql .= 'FROM {ac_report_project_cache} s INNER JOIN {ac_report_producer_cache} p ';
    // $sql .= 'ON s.exec_producer_id = p.producer_id ';
    // $sql .= 'WHERE s.project_id = "' . $path[1] . '"';
    $sql = db_rewrite_sql($sql);

    $result = db_query($sql);
    while ($row = db_fetch_object($result)) {
      if ($row->name)
        $content = '<div class="name"><span>'. t('Produced by') .'</span><br />'. $row->name .'</div>';
      if ($row->website)
        $content .= '<div class="website"><span>'. t('Website') .'</span><br />'. $row->website .'</div>';
      if ($row->email)
        $content .= '<div class="email"><span>'. t('Email by') .'</span><br /><a href="mailto:'. $row->email .'">'. $row->email .'</a></div>';
      if ($row->phone)
        $content .= '<div class="phone"><span>'. t('Phone') .'</span><br />'. $row->phone .'</div>';
    }

    return $content;
  }
  else {
    return t('Producer info not found');
  }
}

/**
 * Show filter block (navigation) for shows page.
 */
function mnnshow_block_shows_filter(){
  $path = drupal_get_path_alias($_GET['q']);
  $path = explode('/', $path);
  if ($path[0] == 'shows' && $path[1] == 'past-shows' && $path[2] == 'category') { // past shows with category
    $is_current_shows = false;
    $is_alphabetical = false;
    if ($path[3])
      $current_category = $path[3];
    else
      $current_category = '';
  }
  elseif ($path[0] == 'shows' && $path[1] == 'past-shows') { // past shows alphabetical
    $is_current_shows = false;
    $is_alphabetical = true;
    if ($path[2])
      $current_category = $path[2];
    else
      $current_category = 'a';
  }
  elseif ($path[0] == 'shows' && $path[1] == 'category') { // current shows with category
    $is_current_shows = true;
    $is_alphabetical = false;
    if ($path[2])
      $current_category = $path[2];
    else
      $current_category = '';
  }
  else { // current shows alphabetical
    $is_current_shows = true;
    $is_alphabetical = true;
    if ($path[1])
      $current_category = $path[1];
    else
      $current_category = 'a';
  }

  // build the 'viewing' section
  $content = '<div class="viewing">Viewing:';
  if ($is_current_shows){
    $content .= '<span class="current">Current Shows</span>';
    if ($is_alphabetical)
      $content .= '<span class="past"><a href="/shows/past-shows">Past Shows</a></span>';
    else
      $content .= '<span class="past"><a href="/shows/past-shows/category/'.$current_category.'">Past Shows</a></span>';
  }
  else{
    if ($is_alphabetical)
      $content .= '<span class="current"><a href="/shows">Current Shows</a></span>';
    else
      $content .= '<span class="current"><a href="/shows/category/'.$current_category.'">Current Shows</a></span>';
    $content .= '<span class="past">Past Shows</span>';
  }
  $content .= '</div>';

  // build the 'sort by' section
  $content .= '<div class="sort-by">Sort By:';
  if ($is_alphabetical){
    $content .= '<span class="alphabetical">Alphabetical</span>';
    if ($is_current_shows)
      $content .= '<span class="category"><a href="/shows/category">Category</a></span>';
    else
      $content .= '<span class="category"><a href="/shows/past-shows/category">Category</a></span>';
  }
  else{
    if ($is_current_shows)
      $content .= '<span class="alphabetical"><a href="/shows">Alphabetical</a></span>';
    else
      $content .= '<span class="alphabetical"><a href="/shows/past-shows">Alphabetical</a></span>';
    $content .= '<span class="category">Category</span>';
    $content .= mnnshow_block_category_dropdown($is_current_shows, $current_category);
  }
  $content .= '</div>';

  // build the alphabet links (if necessary)
  if ($is_alphabetical){
    $content .= mnnshow_block_alphabet_links($is_current_shows, $current_category);
  }

  return $content;
}

/**
 * Watch Now block (horizontal bar).
 */
function mnnshow_block_watch_now(){
  // Display loading html, the rest is loaded via ajax
  // from reporting server and pushed to homepage.
  // mnnshow_init has js inclusion.
  return '<div id="block-mnnshow-2-whats-on-now" class="ajaxblocks-wrapper-8"></div>';
}

/**
 * Channel Listing wrapper block for schedule.
 */
function mnnshow_block_geolocator_and_channel_listing(){
  $content = '<div class="col"><div class="locator"></div></div>';
  $content .= '<div class="col">';
  $content .= mnnshow_block_channel_listing();
  $content .= '</div>';
  return $content;
}

/**
 * Channel Listing block for schedule.
 */
function mnnshow_block_channel_listing(){
  $channel_info = mnnshow_get_channels();

  $content = '<table class="channel-grid">';
  // heading row
  $content .= '<tr><th></th>'; // first col is blank
  for ($i = 0; $i < count($channel_info[1]['tvChannels']); $i++){
    $content .= '<th>'.$channel_info[1]['tvChannels'][$i]['tvStationName'].'</th>';
  }
  $content .= '</tr>';
  // channels
  for ($i = 1; $i <= count($channel_info); $i++){
    $content .= '<tr>';
    $content .= '<th>'.$i.' '.$channel_info[$i]['name'].'</th>';
    for ($j = 0; $j < count($channel_info[1]['tvChannels']); $j++){
      $content .= '<td>'.$channel_info[$i]['tvChannels'][$j]['tvStationChannel'].'</td>';
    }
    $content .= '</tr>';
  }

  $content .= '</table>';
  return $content;
}

/**
 * YC Channel Listing block for YC schedule.
 */
function mnnshow_block_yc_channel_listing(){
  $channel_info = mnnshow_get_channels();

  //--- youth channel plays on channel 1 & 4

  $content = '<table class="channel-grid">';
  // heading row
  $content .= '<tr><th></th>'; // first col is blank
  for ($i = 0; $i < count($channel_info[1]['tvChannels']); $i++){
    $content .= '<th>'.$channel_info[1]['tvChannels'][$i]['tvStationName'].'</th>';
  }
  $content .= '</tr>';
  // channels
  for ($i = 1; $i <= count($channel_info); $i=$i+3){
    $content .= '<tr>';
    $content .= '<th>'.$i.' '.$channel_info[$i]['name'].'</th>';
    for ($j = 0; $j < count($channel_info[1]['tvChannels']); $j++){
      $content .= '<td>'.$channel_info[$i]['tvChannels'][$j]['tvStationChannel'].'</td>';
    }
    $content .= '</tr>';
  }

  $content .= '</table>';
  return $content;
}

/**
 * YC Channel Intro block for YC schedule.
 */
function mnnshow_block_yc_channel_intro(){
  $schedules = mnnshow_yc_schedules();

  $now = new DateTime(NULL, new DateTimeZone('America/New_York'));
  $day = intval($now->format('N')) - 1; // 0 = Monday, 6 = Sunday
  $content = '';

  foreach ($schedules as $schedule_num => $schedule) {
    foreach ($schedule as $item) {
      if ($item['day'] == $day) {
        $start = new DateTime($now->format('m/d/Y '. $item['start_time']), new DateTimeZone('America/New_York'));
        $end = new DateTime($now->format('m/d/Y '. $item['stop_time']), new DateTimeZone('America/New_York'));

        if (mnnshow_is_date_in_range($start, $end, $now)) {
          switch ($item['channel']) {
            case 1:
              $link = '/live/1-community-channel';
              break;

            case 2:
              $link = '/live/2-lifestyle-channel';
              break;

            case 3:
              $link = '/live/3-spirit-channel';
              break;

            case 4:
              $link = '/live/4-culture-channel';
              break;

            default:
              $link = '';
              break;
          }

          break 2;
        }
      }
    }
  }

  $content = '<p>Youth Channel broadcasts weekdays, from 4-5 PM on MNN1 and 5-6 on MNN4.</p>';
  if ($link != '') {
    $content .= '<p>Youth Channel is streaming right now. <a href="' . $link .'"">Click to watch online</a>.</p>';
  }
  else {
    $content .= '<p>Until Youth Channel broadcasts again, watch <a href="/youth-channel/video">our videos</a>.</p>';
  }

  return $content;
}

/**
 * YC Is Playing Now block for homepage.
 */
function mnnshow_block_yc_channel_is_playing_now(){
  $schedules = mnnshow_yc_schedules();

  $now = new DateTime(NULL, new DateTimeZone('America/New_York'));
  $day = intval($now->format('N')) - 1; // 0 = Monday, 6 = Sunday
  $content = '';

  foreach ($schedules as $schedule_num => $schedule) {
    foreach ($schedule as $item) {
      if ($item['day'] == $day) {
        $start = new DateTime($now->format('m/d/Y '. $item['start_time']), new DateTimeZone('America/New_York'));
        $end = new DateTime($now->format('m/d/Y '. $item['stop_time']), new DateTimeZone('America/New_York'));

        if (mnnshow_is_date_in_range($start, $end, $now)) {
          switch ($item['channel']) {
            case 1:
              $link = '/live/1-community-channel';
              break;

            case 2:
              $link = '/live/2-lifestyle-channel';
              break;

            case 3:
              $link = '/live/3-spirit-channel';
              break;

            case 4:
              $link = '/live/4-culture-channel';
              break;

            default:
              $link = '';
              break;
          }

          $content = '<p>Youth Channel is playing right now on MNN - <a href="' . $link . '">Watch Online Now!</a></p>';

          break 2;
        }
      }
    }
  }

  return $content;
}

/**
 * Alphabet links block for shows page.
 */
function mnnshow_block_alphabet_links($is_current_shows, $current_category) {
  $links = array('a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z');
  $content = '<div class="alphabet">';
  foreach ($links as $link) {
    $content .= '<span>';
    if (strtolower($current_category) == $link){
      $content .= strtoupper($link);
    }
    else {
      if ($is_current_shows)
        $l = '/shows/';
      else
        $l = '/shows/past-shows/';
      $content .= '<a href="'.$l.$link.'">'.strtoupper($link).'</a>';
    }
    $content .= '</span>';
  }
  $content .= '</div>';

  return $content;
}

/**
 * Category dropdown block for shows page.
 */
function mnnshow_block_category_dropdown($is_current_shows, $current_category) {
  global $base_root;
  if (!$is_current_shows)
    $past_url = 'past-shows/';
  $categories = mnnshow_get_categories();
  $js = 'location.href=\''. $base_root .'/shows/'. $past_url . 'category/\' + this.options[this.selectedIndex].value;';
  $select = '<select name="category" size="1" onchange="'.$js.'" onmouseup="this.focus()">';
  $select .= '<option value="">All</option>';
  foreach ($categories as $cat => $cat_value){
    if ($cat == $current_category) { $selected = ' selected="selected"'; } else { $selected = ''; }
    $select .= '<option value="'. $cat .'"'. $selected .'>'. $cat_value .'</option>';
  }
  $select .= '</select>';
  return $select;
}

