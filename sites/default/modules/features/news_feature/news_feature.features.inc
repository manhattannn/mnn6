<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function news_feature_imagecache_default_presets() {
  $items = array(
    'homepage-news' => array(
      'presetname' => 'homepage-news',
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
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function news_feature_node_info() {
  $items = array(
    'news' => array(
      'name' => t('News'),
      'module' => 'features',
      'description' => t('A news article.'),
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
function news_feature_views_api() {
  return array(
    'api' => '2',
  );
}
