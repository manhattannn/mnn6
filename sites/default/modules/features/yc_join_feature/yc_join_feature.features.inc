<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function yc_join_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function yc_join_feature_imagecache_default_presets() {
  $items = array(
    'yc-join-now' => array(
      'presetname' => 'yc-join-now',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '619',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'yc-join-now-thumb' => array(
      'presetname' => 'yc-join-now-thumb',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '124',
            'height' => '105',
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
function yc_join_feature_node_info() {
  $items = array(
    'yc_join' => array(
      'name' => t('Youth Channel - Join'),
      'module' => 'features',
      'description' => t('A section of the Join Youth Channel area.'),
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

/**
 * Implementation of hook_views_api().
 */
function yc_join_feature_views_api() {
  return array(
    'api' => '2',
  );
}
