<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function watch_live_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function watch_live_feature_node_info() {
  $items = array(
    'watch_live' => array(
      'name' => t('Watch Live'),
      'module' => 'features',
      'description' => t('One of the watch live channels.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('JW Player Video Tag'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
