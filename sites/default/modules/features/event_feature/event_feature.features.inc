<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function event_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function event_feature_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'module' => 'features',
      'description' => t('A user submitted event.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => t('Please fill out the following fields to submit your event. After you have submitted your event, it will be reviewed by our staff. Once approved, it will be visible on the calendar.'),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function event_feature_views_api() {
  return array(
    'api' => '2',
  );
}
