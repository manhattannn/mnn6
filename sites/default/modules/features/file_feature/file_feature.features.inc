<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function file_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function file_feature_node_info() {
  $items = array(
    'file' => array(
      'name' => t('File'),
      'module' => 'features',
      'description' => t('A file for users to download.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '1',
      'body_label' => t('Description or Instructions'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
