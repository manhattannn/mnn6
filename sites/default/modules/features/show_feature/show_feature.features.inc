<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function show_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function show_feature_node_info() {
  $items = array(
    'channel_info' => array(
      'name' => t('Channel Info'),
      'module' => 'features',
      'description' => t('Basic information about a channel.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '1',
      'body_label' => t('Brief Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'producer' => array(
      'name' => t('Producer'),
      'module' => 'features',
      'description' => t('A producer of a show.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'show' => array(
      'name' => t('Show'),
      'module' => 'features',
      'description' => t('Show information.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'show_time' => array(
      'name' => t('Show Time'),
      'module' => 'features',
      'description' => t('A scheduled time that a show is aired.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'television_channel' => array(
      'name' => t('Television Channel'),
      'module' => 'features',
      'description' => t('A channel on television from a television station.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'television_station' => array(
      'name' => t('Television Station'),
      'module' => 'features',
      'description' => t('A show provider to the end user. Cable, satellite, etc.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
