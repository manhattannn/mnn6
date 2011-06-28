<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function main_feature_slideshow_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function main_feature_slideshow_imagecache_default_presets() {
  $items = array(
    'main-feature-slideshow' => array(
      'presetname' => 'main-feature-slideshow',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '',
            'height' => '516',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function main_feature_slideshow_node_info() {
  $items = array(
    'main_feature_slideshow' => array(
      'name' => t('Main Feature Slideshow'),
      'module' => 'features',
      'description' => t('An individual homepage slideshow slide with text headline.'),
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
function main_feature_slideshow_views_api() {
  return array(
    'api' => '2',
  );
}
