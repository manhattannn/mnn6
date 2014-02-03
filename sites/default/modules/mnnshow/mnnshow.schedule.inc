<?php

ctools_include('mnnshow.common', 'mnnshow', '');
ctools_include('mnnshow.containers', 'mnnshow', '');

/**
 * Page callback.
 */
function mnnshow_schedule(){
  jquery_ui_add('ui.datepicker');

  $mnnshow_js_settings = array(
    'reportingUrl' => variable_get('mnnshow_reporting_server_url', ''),
  );
  drupal_add_js(array('mnnshow' => $mnnshow_js_settings), 'setting');

  drupal_add_js(drupal_get_path('module', 'mnnshow').'/mnnshow.js');
  $content = '<div id="schedule"><header id="schedule-header"><div class="inner"><div class="nav clearfix"></div><div class="channels"></div></div></header><div id="cols"></div></div> ';
  return $content;
}

/**
 * Page callback.
 */
function mnnshow_schedule_get(){
  try {
    $requested_date = new DateTime($_POST['date'], new DateTimeZone('America/New_York'));
  } catch (Exception $e) {
    $requested_date = new DateTime(NULL, new DateTimeZone('America/New_York'));
  }

  // primetime is 7pm to midnight
  $primetime_start = new DateTime($requested_date->format('m/d/Y 19:0:0'), new DateTimeZone('America/New_York'));
  $primetime_end = new DateTime($requested_date->format('m/d/Y 23:59:59'), new DateTimeZone('America/New_York'));

  $query = 'SELECT s.project_id, s.title, s.topic, a.start_time, a.duration, a.channel ';
  $query .= 'FROM {ac_report_project_cache} s ';
  $query .= 'LEFT JOIN {ac_report_airing_cache} a ON s.project_id = a.project_id ';
  $query .= 'WHERE (a.start_time >= "'.$requested_date->format('Y-m-d').' 0:00:00" AND a.start_time <= "'.$requested_date->format('Y-m-d').' 23:59:59") ';
  $query .= 'OR (a.end_time >= "'.$requested_date->format('Y-m-d').' 0:00:00" AND a.end_time <= "'.$requested_date->format('Y-m-d').' 23:59:59") ';
  $query .= 'ORDER BY a.channel ASC, a.start_time ASC';

  $result = db_query(db_rewrite_sql($query));
  $ch1 = array();
  $ch2 = array();
  $ch3 = array();
  $ch4 = array();
  while ($data = db_fetch_object($result)) {
    $duration = $data->duration / 60;
    $duration = round($duration / 30) * 30; // round to nearest 30
    $start = new DateTime($data->start_time, new DateTimeZone('America/New_York'));
    $end = new DateTime($data->start_time, new DateTimeZone('America/New_York'));
    $end->add(new DateInterval('PT'.$duration.'M'));
    $now = new DateTime(NULL, new DateTimeZone('America/New_York'));
    $midnight = new DateTime($requested_date->format('m/d/Y 0:0:0'), new DateTimeZone('America/New_York'));
    if ($start < $midnight){
      $interval = $start->diff($midnight);
      $duration -= intval($interval->format('%i'));
    }
    if ($now >= $start && $now <= $end)
      $current = 'true';
    else
      $current = 'false';
    if (mnnshow_is_date_in_range($primetime_start, $primetime_end, $start) || mnnshow_is_date_in_range($primetime_start, $primetime_end, $end->sub(new DateInterval('PT1M'))))
      $primetime = 'true';
    else
      $primetime = 'false';
    $row = array(
      'link' => '/show-info/'.$data->project_id.'/'.mnnshow_url_feiendly_title($data->title),
      'title' => $data->title,
      'category' => isset($data->topic) ? $data->topic : '',
      'start' => $start->format("H-i"),
      'isCurrent' => $current,
      'isPrimetime' => $primetime,
      'duration' => $duration
    );
    switch ($data->channel){
      case 'Channel 1':
        $ch1[] = $row;
        break;
      case 'Channel 2':
        $ch2[] = $row;
        break;
      case 'Channel 3':
        $ch3[] = $row;
        break;
      case 'Channel 4':
        $ch4[] = $row;
        break;
    }
    //print_r($row);
  }

  // time column
  $time_col = array();
  $now = new DateTime(NULL, new DateTimeZone('America/New_York'));
  $hour = $now->format('H');
  $minute = $now->format('i') >= 30 ? '30' : '00';
  $now->setTime($hour, $minute, 0); // round down to nearest half hour

  $time_increment = clone $requested_date;
  $time_increment->setTime(0, 0, 0);
  $duration = 30;
  for ($i = 0; $i < 48; $i++){
    $time_increment == $now ? $current = 'true' : $current = 'false';
    if (mnnshow_is_date_in_range($primetime_start, $primetime_end, $time_increment) || mnnshow_is_date_in_range($primetime_start, $primetime_end, $time_increment))
      $primetime = 'true';
    else
      $primetime = 'false';
    $time_col[] = array(
      'display' => $time_increment->format('g:i A'),
      'start' => $time_increment->format("H-i"),
      'isCurrent' => $current,
      'isPrimetime' => $primetime,
      'duration' => $duration
    );
    $time_increment->add(new DateInterval('PT30M'));
  }

  // dates
  $prevDate = clone $requested_date;
  $nextDate = clone $requested_date;
  $prevDate->sub(new DateInterval('P1D'));
  $nextDate->add(new DateInterval('P1D'));

  drupal_set_header('Content-Type: application/json');
  drupal_json(array(
                'schedDate' => $requested_date->format('m/d/Y'),
                'prevDate' => $prevDate->format('m/d/Y'),
                'nextDate' => $nextDate->format('m/d/Y'),
                'displayDate' => $requested_date->format('l, F j'),
                'time' => $time_col,
                'ch1' => $ch1,
                'ch2' => $ch2,
                'ch3' => $ch3,
                'ch4' => $ch4
              ));
  exit();
}

/**
 * Page callback.
 */
function mnnshow_schedule_table_header(){
  $channels = mnnshow_get_channels();
  //print_r($channels);

  drupal_set_header('Content-Type: application/json');
  drupal_json(array(
                'channel1' => $channels['1'],
                'channel2' => $channels['2'],
                'channel3' => $channels['3'],
                'channel4' => $channels['4']
              ));
  exit();
}

/**
 * Page callback.
 */
function mnnshow_schedule_now_playing(){
  $channel_info = mnnshow_get_channels();
  $channels = array();

  $now = new DateTime(NULL, new DateTimeZone('America/New_York'));
  //$now = new DateTime('2011-05-15 19:25', new DateTimeZone('America/New_York'));
  $query = 'SELECT s.project_id, s.title, a.channel ';
  $query .= 'FROM {ac_report_project_cache} s ';
  $query .= 'LEFT JOIN {ac_report_airing_cache} a ON s.project_id = a.project_id ';
  $query .= 'WHERE (a.start_time <= "'.$now->format('Y-m-d G:i:s').'" AND DATE_ADD(a.end_time, INTERVAL 2 MINUTE) >= "'.$now->format('Y-m-d G:i:s').'") ';
  $query .= 'ORDER BY a.channel ASC';

  $result = db_query(db_rewrite_sql($query));
  while ($data = db_fetch_object($result)) {
    $show = array(
      'id' => $data->project_id,
      'title' => $data->title,
      'url' => mnnshow_get_show_href($data->title, $data->project_id)
    );
    switch ($data->channel){
      case 'Channel 1':
        if (!isset($channels[1]))
          $channels[1] = $show;
        break;
      case 'Channel 2':
        if (!isset($channels[2]))
          $channels[2] = $show;
        break;
      case 'Channel 3':
        if (!isset($channels[3]))
          $channels[3] = $show;
        break;
      case 'Channel 4':
        if (!isset($channels[4]))
          $channels[4] = $show;
        break;
    }
  }

  drupal_set_header('Content-Type: application/json');
  drupal_json(array(
    'actual_time'  => $now->format('M j, Y g:i a'),
    'channel_info' => $channel_info,
    'channels'     => $channels
  ));
  exit();
}