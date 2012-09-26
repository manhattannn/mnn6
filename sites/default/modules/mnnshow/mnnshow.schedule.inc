<?php

ctools_include('mnnshow.common', 'mnnshow', '');
ctools_include('mnnshow.containers', 'mnnshow', '');

/**
 * Page callback.
 */
function mnnshow_schedule(){
  jquery_ui_add('ui.datepicker');
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
    if (_mnnshow_is_date_in_range($primetime_start, $primetime_end, $start) || _mnnshow_is_date_in_range($primetime_start, $primetime_end, $end->sub(new DateInterval('PT1M'))))
      $primetime = 'true';
    else
      $primetime = 'false';
    $row = array(
      'link' => '/show-info/'.$data->project_id.'/'._mnnshow_url_feiendly_title($data->title),
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
    if (_mnnshow_is_date_in_range($primetime_start, $primetime_end, $time_increment) || _mnnshow_is_date_in_range($primetime_start, $primetime_end, $time_increment))
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
function mnnshow_yc_schedule(){
  jquery_ui_add('ui.datepicker');
  drupal_add_js(drupal_get_path('module', 'mnnshow').'/mnnshow.js');
  $content = '<div id="yc-schedule">';
  $content .= '<header id="schedule-header"> <div class="inner"> <div class="nav clearfix"></div> </div> </header>';
  $content .= '<div id="weekday"> <div class="title">Weekday Schedule</div> <div class="rows"></div> </div>';
  $content .= '<div id="weekend"> <div class="title">Weekend Schedule</div> <div class="rows"></div> </div>';
  $content .= '</div>'; // yc-schedule

  return $content;
}

/**
 * Page callback.
 */
function mnnshow_yc_schedule_get(){
  try {
    $requested_date = new DateTime($_POST['date'], new DateTimeZone('America/New_York'));
  } catch (Exception $e) {
    $requested_date = new DateTime(NULL, new DateTimeZone('America/New_York'));
  }

  //--- date of the first & end of the week (monday & sunday)
  $week =_mnnshow_get_week_range($requested_date->format('d'), $requested_date->format('m'), $requested_date->format('Y'));
  $week_start = new DateTime($week['first'], new DateTimeZone('America/New_York'));
  $week_end = new DateTime($week['last'], new DateTimeZone('America/New_York'));

  //--- create where clause
  $wherea = array();
  $current_day = clone $week_start;
  for ($i = 0; $i < 5; $i++){
    // weekday times are from 3p to 5p
    $w = '((a.start_time >= "'.$current_day->format('Y-m-d').' 15:00:00" AND a.start_time <= "'.$current_day->format('Y-m-d').' 16:59:59") ';
    $w .= 'OR (a.end_time > "'.$current_day->format('Y-m-d').' 15:00:00" AND a.end_time <= "'.$current_day->format('Y-m-d').' 16:59:59")) ';
    $wherea[] = $w;
    $current_day->add(new DateInterval('P1D'));
  }
  for ($i = 0; $i < 2; $i++){
    // weekend times are from 7a to 12p
    $w = '((a.start_time >= "'.$current_day->format('Y-m-d').' 07:00:00" AND a.start_time <= "'.$current_day->format('Y-m-d').' 11:59:59") ';
    $w .= 'OR (a.end_time > "'.$current_day->format('Y-m-d').' 07:00:00" AND a.end_time <= "'.$current_day->format('Y-m-d').' 11:59:59")) ';
    $wherea[] = $w;
    $current_day->add(new DateInterval('P1D'));
  }
  $where = implode(' OR ', $wherea);

  //--- run the query
  $query = 'SELECT s.project_id, s.title, s.topic, a.start_time, a.duration, a.channel ';
  $query .= 'FROM {ac_report_project_cache} s ';
  $query .= 'LEFT JOIN {ac_report_airing_cache} a ON s.project_id = a.project_id ';
  $query .= 'WHERE a.channel = "Channel 4" AND ('. $where .') ';
  $query .= 'ORDER BY a.start_time ASC';
  $result = db_query(db_rewrite_sql($query));

  //--- individual shows
  $shows = array(
    'weekday' => array(),
    'weekend' => array()
  );
  while ($data = db_fetch_object($result)) {
    // watchdog('mnnshow', '1 data: '.var_export($data, true), array(), WATCHDOG_INFO);
    $show = new MnnShow(new DateTime($data->start_time, new DateTimeZone('America/New_York')), $data->duration / 60, true);
    $show->setLink('/show-info/'.$data->project_id.'/'._mnnshow_url_feiendly_title($data->title));
    $show->setTitle($data->title);
    $show->setCategory(isset($data->topic) ? $data->topic : '');
    $show->setChannel($data->channel);
    /*$show = array(
      'link' => '/show-info/'.$data->project_id.'/'._mnnshow_url_feiendly_title($data->title),
      'title' => $data->title,
      'category' => isset($data->topic) ? $data->topic : '',
      'start' => $start->format("H-i"),
      'isCurrent' => $current,
      'duration' => $duration,
      'dateTime' => $start->format('Y/m/d H:i')
    );*/

    // watchdog('mnnshow', '2 show: '.var_export($show, true), array(), WATCHDOG_INFO);
    if ($show->day_of_week < 6) // weekday
      $shows['weekday'][$show->day_of_week][] = $show;
    else
      $shows['weekend'][$show->day_of_week][] = $show;

  }

  //--- day of week column
  $day_col['weekday'] = array(1 => 'Mon', 'Tue', 'Wed', 'Thurs', 'Fri');
  $day_col['weekend'] = array(6 => 'Sat', 'Sun');

  //--- time row
  $time_row['weekday'] = array('3:00 pm', '4:00 pm');
  $time_row['weekend'] = array('7:00 am', '8:00 am', '9:00 am', '10:00 am', '11:00 am');

  // dates
  $prevDate = clone $requested_date;
  $nextDate = clone $requested_date;
  $prevDate->sub(new DateInterval('P7D'));
  $nextDate->add(new DateInterval('P7D'));

  drupal_set_header('Content-Type: application/json');
  drupal_json(array(
                'schedDate' => $requested_date->format('m/d/Y'),
                'prevDate' => $prevDate->format('m/d/Y'),
                'nextDate' => $nextDate->format('m/d/Y'),
                'displayDate' => _mnnshow_format_date_range($week_start, $week_end),
                'shows' => $shows,
                'dayCol' => $day_col,
                'timeRow' => $time_row
              ));
  exit();
}

