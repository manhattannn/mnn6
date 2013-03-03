<?php

ctools_include('cleanstring', 'ctools', 'includes');

/**
 * Get the channels (tv stations).
 */
function mnnshow_get_channels(){
  // check for cached channels
  if ($cached = cache_get('mnnshow:channels', 'cache')) {
    return $cached->data;
  }

  $channels = array();

  $result = db_query("SELECT nid FROM {node} WHERE type = 'channel_info'");
  while($row = db_fetch_object($result)) {
    $channel_info = node_load($row->nid); // drupal content type
    $tv_ch = array();
    foreach ($channel_info->field_television_channel as $tv_ch_nid){
      $television_channel = node_load($tv_ch_nid['nid']); // drupal content type
      $television_station = node_load($television_channel->field_television_station[0]['nid']); // drupal content type
      $tv_ch[] = array(
        'tvStationName' => $television_station->title,
        'tvStationChannel' => $television_channel->field_channel_number[0]['value']
      );
    }
    // sort the tv stations
    foreach ($tv_ch as $key => $value){
      $station_name[$key] = $value['tvStationName'];
    }
    array_multisort($station_name, SORT_DESC, $tv_ch);

    $channels[$channel_info->field_number[0]['value']] = array(
      'name' => $channel_info->title,
      'description' => $channel_info->body,
      'watchLiveUrl' => drupal_get_path_alias('node/'.$channel_info->field_watch_live_link[0]['nid']),
      'tvChannels' => $tv_ch
    );
  }

  // store in cache with a minimum expiration time of 1 day
  cache_set('mnnshow:channels', $channels, 'cache', time() + (60 * 60 * 24));
  return $channels;
}

/**
 * Render current shows in a list.
 */
function mnnshow_show_current_list($query, $count_query, $category) {
  $pager_num = 0;
  $result = pager_query(db_rewrite_sql($query), 15, $pager_num, $count_query);
  $content = '';
  if (!is_null($category))
    $content .= '<h2>'.$category.'</h2>';
  while ($row = db_fetch_object($result)) {
    $title = $row->title; //ucwords(strtolower($row->title));
    $href = mnnshow_get_show_href($title, $row->project_id);

    $content .= '<div class="row">';
    $content .= '<h3 class="title"><a href="/'. $href .'">'. $title .'</a></h3>';
    $content .= '<div class="category">'. $row->topic .'</div>';
    $content .= '<div class="meta"><span class="channel">'. $row->channel .'</span>';
    if ($row->start_time){
      $start_time = new DateTime($row->start_time, new DateTimeZone('America/New_York'));
      $content .= '<span class="next-airing">Next Airing: '. $start_time->format("D, M j, Y \a\\t g:ia T") .'</span></div>';
    }
    else {
      $content .= '<span class="next-airing">Next Airing: There are no scheduled airings for this show.</span></div>';
    }
    $content .= '<div class="content">' . $row->description . '</div>';
    $content .= '</div>';
  }
  return $content . theme('pager', NULL, 15, $pager_num);
}

/**
 * Render past shows in a list.
 */
function mnnshow_show_past_list($query, $count_query, $category) {
  $pager_num = 0;
  $result = pager_query(db_rewrite_sql($query), 45, $pager_num, $count_query);
  $content = '';
  if (!is_null($category))
    $content .= '<h2>'.$category.'</h2>';
  $items = array();
  while ($row = db_fetch_object($result)) {
    $title = $row->title; //ucwords(strtolower($row->title));
    $href = mnnshow_get_show_href($title, $row->project_id);

    $items[] = '<a href="/'. $href .'">'. $title .'</a>';
  }

  $col1 = $col2 = $col3 = floor(count($items) / 3);
  if (count($items) % 3 == 2)
    $col2++;
  if (count($items) % 3 == 1)
    $col1++;
  $content .= '<div class="col1">';
  for ($i = 0; $i < $col1; $i++){
    $content .= '<div class="item-'.$i.'">'.$items[$i].'</div>';
  }
  $content .= '</div>';
  $content .= '<div class="col2">';
  for ($i = $col1; $i < $col1 + $col2; $i++){
    $content .= '<div class="item-'.$i.'">'.$items[$i].'</div>';
  }
  $content .= '</div>';
  $content .= '<div class="col3">';
  for ($i = $col1 + $col2; $i < $col1 + $col2 + $col3; $i++){
    $content .= '<div class="item-'.$i.'">'.$items[$i].'</div>';
  }
  $content .= '</div>';

  return $content . theme('pager', NULL, 45, $pager_num);
}

/**
 * Get show categories.
 */
function mnnshow_get_categories(){
  $sql = 'SELECT DISTINCT s.topic ';
  $sql .= 'FROM {ac_report_project_cache} s ';
  $sql .= 'ORDER BY s.topic ASC ';
  $result = db_query(db_rewrite_sql($sql));
  $ret = array();
  while ($row = db_fetch_object($result)){
    if (!is_null($row->topic)){
      $url_cat = mnnshow_url_feiendly_title($row->topic);
      $ret[$url_cat] = $row->topic;
    }
  }
  return $ret;
}

/**
 * Get show href.
 */
function mnnshow_get_show_href($title, $id) {
  $url_title = mnnshow_url_feiendly_title($title);
  $href = 'show-info/' . $id . '/' . $url_title;
  return $href;
}

/**
 * Generate a url friendly title.
 */
function mnnshow_url_feiendly_title($title){
  // remove all non-alphanumeric characters, then remove leading/trailing spaces
  // $url_title = trim(preg_replace("/[^A-Za-z0-9\/ ]/", '', strtolower($title)));
  // replace spaces with dashes
  // $url_title = preg_replace("/[\/ ]/", '-', $url_title);

  $url_title = ctools_cleanstring($title, array('lower case' => true));
  return $url_title;
}

/**
 * Check if a date is within a range.
 */
function mnnshow_is_date_in_range($start_date, $end_date, $date) {
  // assume DateTime object
  return (($date >= $start_date) && ($date <= $end_date));
}

/**
 * get_week_range accepts numeric $month, $day, and $year values.
 * It will find the first monday and the last sunday of the week for the
 * given day, and return them as YYYY-MM-DD HH:MM:SS timestamps
 *
 * @param string $day   : numeric value of the day (01 - 31)
 * @param string $month : numeric value of the month (01 - 12)
 * @param string $year  : four-digit value of the year (2008)
 * @return array|bool   : array('first' => monday of week, 'last' => sunday of week);
 */
function mnnshow_get_week_range($day = '', $month = '', $year = '') {
  // default empties to current values
  if (empty($day)) $day = date('d');
  if (empty($month)) $month = date('m');
  if (empty($year)) $year = date('Y');
  // do some figurin'
  $weekday = date('w', mktime(0, 0, 0, $month, $day, $year));
  $monday = $day - $weekday;
  $start_week = date('Y-m-d H:i:00', mktime(0, 0, 0, $month, $monday + 1, $year));   // monday
  $end_week = date('Y-m-d H:i:00', mktime(0, 0, 0, $month, $monday + 7, $year)); // sunday
  if (!empty($start_week) && !empty($end_week)) {
    return array('first' => $start_week, 'last' => $end_week);
  }
  // otherwise there was an error :'(
  return false;
}

/**
 * format start/end dates of a range for printing to the screen.
 * ex: "April 11 - 18, 2011" or "December 29, 2011 - January 3, 2012"
 *
 * @param DateTime $start : start of the range
 * @param DateTime $end   : end of the range
 * @return string         : the formatted string
 */
function mnnshow_format_date_range($start, $end){
  if ($start->format('Y') == $end->format('Y') && $start->format('m') == $end->format('m'))
    return $start->format('F j - ').$end->format('j, ').$start->format('Y');
  elseif ($start->format('Y') == $end->format('Y'))
    return $start->format('F j - ').$end->format('F j, ').$start->format('Y');
  else
    return $start->format('F j, Y - ').$end->format('F j, Y');
}
