<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function firehouse_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function firehouse_feature_imagecache_default_presets() {
  $items = array(
    'community-studio-dialogue-landing' => array(
      'presetname' => 'community-studio-dialogue-landing',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '176',
            'height' => '104',
          ),
        ),
      ),
    ),
    'firehouse-main' => array(
      'presetname' => 'firehouse-main',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '296',
            'height' => '237',
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
function firehouse_feature_node_info() {
  $items = array(
    'community_studio_dialogue' => array(
      'name' => t('Community Studio Dialogue'),
      'module' => 'features',
      'description' => t('An individual Community Studio Dialogue item.'),
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
function firehouse_feature_views_api() {
  return array(
    'api' => '2',
  );
}
