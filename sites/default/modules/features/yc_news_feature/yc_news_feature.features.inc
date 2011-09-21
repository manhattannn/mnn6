<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function yc_news_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function yc_news_feature_imagecache_default_presets() {
  $items = array(
    'yc-homepage-news' => array(
      'presetname' => 'yc-homepage-news',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '274',
            'height' => '175',
          ),
        ),
      ),
    ),
    'yc-news' => array(
      'presetname' => 'yc-news',
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
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function yc_news_feature_node_info() {
  $items = array(
    'yc_news' => array(
      'name' => t('Youth Channel - News'),
      'module' => 'features',
      'description' => t('A Youth Channel news article.'),
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
function yc_news_feature_views_api() {
  return array(
    'api' => '2',
  );
}
