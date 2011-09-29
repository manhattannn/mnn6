<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function job_listing_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function job_listing_feature_node_info() {
  $items = array(
    'job_listing' => array(
      'name' => t('Job Listing'),
      'module' => 'features',
      'description' => t('An individual job on the Job Listings page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
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
function job_listing_feature_views_api() {
  return array(
    'api' => '2',
  );
}
