<?php

ctools_include('mnnshow.common', 'mnnshow', '');

/**
 * Page callback.
 */
function mnnshow_show_list_past_by_category($category) {
  if (!$category) {
    $category = "all";
    $display_category = 'All';
  }
  else {
    $categories = mnnshow_get_categories();
    if (array_key_exists($category, $categories)) {
      $display_category = $categories[$category];
    }
    else {
      $category = "all";
      $display_category = 'All';
    }
  }

  if ($category == 'all'){
    $topic = '';
  }
  else {
    $topic = ' AND s.topic = "'. $display_category .'"';
  }

  $project_status = 's.project_status = "Archival" OR s.project_status = "Completed" OR s.project_status = "Cancelled" OR s.project_status = "Withdrawn"';

  $query = 'SELECT s.project_id, s.title ';
  $query .= 'FROM {ac_report_project_cache} s WHERE ( '.$project_status.' )'.$topic.' ORDER BY s.title ASC';

  $count_query = 'SELECT COUNT(*) FROM ('. $query .') AS count_query';

  return mnnshow_show_past_list($query, $count_query, $display_category);
}

/**
 * Page callback.
 */
function mnnshow_show_list_past_by_alpha($char) {
  if (!$char)
    $char = "a";
  else {
    $char = substr(strtolower($char), 0, 1); // first lowercase character
    if (!ctype_alpha($char))
      $char = 'a';
  }

  $project_status = 's.project_status = "Archival" OR s.project_status = "Completed" OR s.project_status = "Cancelled" OR s.project_status = "Withdrawn"';

  $query = 'SELECT s.project_id, s.title ';
  $query .= 'FROM {ac_report_project_cache} s WHERE ( '.$project_status.' ) ';
  $query .= 'AND s.title LIKE "'.$char.'%" ORDER BY s.title ASC';

  $count_query = 'SELECT COUNT(*) FROM ('. $query .') AS count_query';

  return mnnshow_show_past_list($query, $count_query, strtoupper($char));
}

/**
 * Page callback.
 */
function mnnshow_show_list_current_by_category($category) {
  if (!$category) {
    $category = "all";
    $display_category = 'All';
  }
  else {
    $categories = mnnshow_get_categories();
    if (array_key_exists($category, $categories)) {
      $display_category = $categories[$category];
    }
    else {
      $category = "all";
      $display_category = 'All';
    }
  }


  $query = 'SELECT s.project_id, s.title, s.narrative AS description, s.topic, s.project_status, MIN(a.start_time) AS start_time, a.channel ';
  $query .= 'FROM {ac_report_project_cache} s ';
  $query .= 'JOIN {ac_report_airing_cache} a ON s.project_id = a.project_id ';
  $query .= 'WHERE (s.project_status = "Active" OR s.project_status = "Completed") ';
  $query .= 'AND a.start_time > NOW() ';
  if ($category != 'all'){
    $query .= ' AND s.topic = "'. $display_category .'"';
  }
  $query .= 'GROUP BY s.title ';
  $query .= 'ORDER BY s.title ASC ';

  $count_query = 'SELECT COUNT(*) FROM ('. $query .') AS count_query';

  return mnnshow_show_current_list($query, $count_query, $display_category);
}

/**
 * Page callback.
 */
function mnnshow_show_list_current_by_alpha($char) {
  if (!$char)
    $char = "a";
  else {
    $char = substr(strtolower($char), 0, 1); // first lowercase character
    if (!ctype_alpha($char))
      $char = 'a';
  }

  $query = 'SELECT s.project_id, s.title, s.narrative AS description, s.topic, s.project_status, MIN(a.start_time) AS start_time, a.channel ';
  $query .= 'FROM {ac_report_project_cache} s ';
  $query .= 'JOIN {ac_report_airing_cache} a ON s.project_id = a.project_id ';
  $query .= 'WHERE (s.project_status = "Active" OR s.project_status = "Completed") ';
  $query .= 'AND a.start_time > NOW() ';
  $query .= 'AND s.title LIKE "'.$char.'%" ';
  $query .= 'GROUP BY s.title ';
  $query .= 'ORDER BY s.title ASC ';

  $count_query = 'SELECT COUNT(*) FROM ('. $query .') AS count_query';

  return mnnshow_show_current_list($query, $count_query, NULL);
}

/**
 * Page callback.
 */
function mnnshow_show_info($id) {
  if (!is_numeric($id)) {
    return null;
  }

  $query = 'SELECT s.project_id, s.title, s.narrative AS description, s.topic, s.project_status, s.public_url, ';
  $query .= '( SELECT a.start_time FROM {ac_report_airing_cache} AS a ';
  $query .= 'WHERE s.project_id = a.project_id AND a.start_time > NOW() ORDER BY a.start_time LIMIT 1 ) AS start_time, ';
  $query .= '( SELECT a.channel FROM {ac_report_airing_cache} AS a ';
  $query .= 'WHERE s.project_id = a.project_id AND a.start_time > NOW() ORDER BY a.start_time LIMIT 1 ) AS channel ';
  $query .= 'FROM {ac_report_project_cache} s WHERE s.project_id = "'.$id.'"';

  $result = db_query($query);
  //$count = 0;
  $content = '';
  while ($row = db_fetch_object($result)) {
    $title = $row->title; // ucwords(strtolower($row->title));
    drupal_set_title($title);
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
    if ($row->public_url){
      $content .= '<div class="website"><span class="label">Website: </span><a href="'. $row->public_url .'">'. $row->public_url .'</a></div>';
    }
  }
  return $content;
}

