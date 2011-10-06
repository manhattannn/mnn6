<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function staff_board_members_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function staff_board_members_feature_node_info() {
  $items = array(
    'person' => array(
      'name' => t('Person'),
      'module' => 'features',
      'description' => t('A person to be listed on the site, such as an employee.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '1',
      'body_label' => t('Biography'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function staff_board_members_feature_views_api() {
  return array(
    'api' => '2',
  );
}
