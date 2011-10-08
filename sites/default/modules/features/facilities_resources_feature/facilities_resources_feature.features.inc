<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function facilities_resources_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function facilities_resources_feature_node_info() {
  $items = array(
    'resources' => array(
      'name' => t('Facilities and Resources'),
      'module' => 'features',
      'description' => t('Production facilities and equipment resources.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function facilities_resources_feature_views_api() {
  return array(
    'api' => '2',
  );
}
