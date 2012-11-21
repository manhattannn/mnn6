<?php

ctools_include('mnnshow.common', 'mnnshow', '');

/**
 * The channels/days/times that YC is on the air.
 */
function mnnshow_yc_on_air() {
  $on_air = array();
  $on_air[] = array(
    'channel' => 1,
    'day' => 0, // monday
    'start_time' => '16:00:00', // 4pm
    'stop_time' => '16:59:59', // 5pm
  );
  $on_air[] = array(
    'channel' => 1,
    'day' => 1, // tuesday
    'start_time' => '16:00:00', // 4pm
    'stop_time' => '16:59:59', // 5pm
  );
  $on_air[] = array(
    'channel' => 1,
    'day' => 2, // wednesday
    'start_time' => '16:00:00', // 4pm
    'stop_time' => '16:59:59', // 5pm
  );
  $on_air[] = array(
    'channel' => 1,
    'day' => 3, // thursday
    'start_time' => '16:00:00', // 4pm
    'stop_time' => '16:59:59', // 5pm
  );
  $on_air[] = array(
    'channel' => 1,
    'day' => 4, // friday
    'start_time' => '16:00:00', // 4pm
    'stop_time' => '16:59:59', // 5pm
  );
  $on_air[] = array(
    'channel' => 4,
    'day' => 0, // monday
    'start_time' => '17:00:00', // 5pm
    'stop_time' => '17:59:59', // 6pm
  );
  $on_air[] = array(
    'channel' => 4,
    'day' => 1, // tuesday
    'start_time' => '17:00:00', // 5pm
    'stop_time' => '17:59:59', // 6pm
  );
  $on_air[] = array(
    'channel' => 4,
    'day' => 2, // wednesday
    'start_time' => '17:00:00', // 5pm
    'stop_time' => '17:59:59', // 6pm
  );
  $on_air[] = array(
    'channel' => 4,
    'day' => 3, // thursday
    'start_time' => '17:00:00', // 5pm
    'stop_time' => '17:59:59', // 6pm
  );
  $on_air[] = array(
    'channel' => 4,
    'day' => 4, // friday
    'start_time' => '17:00:00', // 5pm
    'stop_time' => '17:59:59', // 6pm
  );

  return $on_air;
}

/**
 * Page callback.
 */
function mnnshow_yc_schedule() {
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
  $on_air = mnnshow_yc_on_air();

  try {
    $requested_date = new DateTime($_POST['date'], new DateTimeZone('America/New_York'));
  } catch (Exception $e) {
    $requested_date = new DateTime(NULL, new DateTimeZone('America/New_York'));
  }

  //--- date of the first & end of the week (monday & sunday)
  $week = mnnshow_get_week_range($requested_date->format('d'), $requested_date->format('m'), $requested_date->format('Y'));
  $week_start = new DateTime($week['first'], new DateTimeZone('America/New_York'));
  $week_end = new DateTime($week['last'], new DateTimeZone('America/New_York'));

  //--- create where clause
  $wherea = array();
  foreach ($on_air as $key => $value) {
    // cycle thru each on_air item, building the where clause
    // reset the current_day on each loop
    // then add the on_air 'day' to current_day
    $current_day = clone $week_start;
    $current_day->add(new DateInterval('P' . $value['day'] . 'D'));
    $w = 'a.channel = "Channel ' . $value['channel'] . '" AND (';
    $w .= '(a.start_time >= "'.$current_day->format('Y-m-d').' ' . $value['start_time'] . '" AND a.start_time <= "'.$current_day->format('Y-m-d').' ' . $value['stop_time'] . '") ';
    $w .= 'OR (a.end_time > "'.$current_day->format('Y-m-d').' ' . $value['start_time'] . '" AND a.end_time <= "'.$current_day->format('Y-m-d').' ' . $value['stop_time'] . '")';
    $w .= ') ';
    $wherea[] = $w;
  }

  // $current_day = clone $week_start;
  // for ($i = 0; $i < 5; $i++){
  //   // weekday times are from 3p to 5p
  //   $w = '((a.start_time >= "'.$current_day->format('Y-m-d').' 15:00:00" AND a.start_time <= "'.$current_day->format('Y-m-d').' 16:59:59") ';
  //   $w .= 'OR (a.end_time > "'.$current_day->format('Y-m-d').' 15:00:00" AND a.end_time <= "'.$current_day->format('Y-m-d').' 16:59:59")) ';
  //   $wherea[] = $w;
  //   $current_day->add(new DateInterval('P1D'));
  // }
  // for ($i = 0; $i < 2; $i++){
  //   // weekend times are from 7a to 12p
  //   $w = '((a.start_time >= "'.$current_day->format('Y-m-d').' 07:00:00" AND a.start_time <= "'.$current_day->format('Y-m-d').' 11:59:59") ';
  //   $w .= 'OR (a.end_time > "'.$current_day->format('Y-m-d').' 07:00:00" AND a.end_time <= "'.$current_day->format('Y-m-d').' 11:59:59")) ';
  //   $wherea[] = $w;
  //   $current_day->add(new DateInterval('P1D'));
  // }
  $where = implode(' OR ', $wherea);

  //--- run the query
  $query = 'SELECT s.project_id, s.title, s.topic, a.start_time, a.duration, a.channel ';
  $query .= 'FROM {ac_report_project_cache} s ';
  $query .= 'LEFT JOIN {ac_report_airing_cache} a ON s.project_id = a.project_id ';
  $query .= 'WHERE ('. $where .') ';
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
    $show->setLink('/show-info/'.$data->project_id.'/'.mnnshow_url_feiendly_title($data->title));
    $show->setTitle($data->title);
    $show->setCategory(isset($data->topic) ? $data->topic : '');
    $show->setChannel($data->channel);
    /*$show = array(
      'link' => '/show-info/'.$data->project_id.'/'.mnnshow_url_feiendly_title($data->title),
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
                'displayDate' => mnnshow_format_date_range($week_start, $week_end),
                'shows' => $shows,
                'dayCol' => $day_col,
                'timeRow' => $time_row
              ));
  exit();
}

