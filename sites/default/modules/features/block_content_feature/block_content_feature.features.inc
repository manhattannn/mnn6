<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function block_content_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function block_content_feature_node_info() {
  $items = array(
    'block_content' => array(
      'name' => t('Block Content'),
      'module' => 'features',
      'description' => t('Content that is only used in a block.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
