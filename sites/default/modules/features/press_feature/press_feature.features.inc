<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function press_feature_ctools_plugin_api() {
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
function press_feature_node_info() {
  $items = array(
    'press_download' => array(
      'name' => t('Press Download'),
      'module' => 'features',
      'description' => t('A file to download, like a PDF or image file. Will be visible on the Press page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'press_link' => array(
      'name' => t('Press Link'),
      'module' => 'features',
      'description' => t('A link to another site, such as a video. Will be visible on the Press page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function press_feature_views_api() {
  return array(
    'api' => '2',
  );
}
