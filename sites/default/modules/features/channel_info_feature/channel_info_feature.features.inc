<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function channel_info_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function channel_info_feature_node_info() {
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
