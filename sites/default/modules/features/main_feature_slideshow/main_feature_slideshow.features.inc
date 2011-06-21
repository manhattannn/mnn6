<?php

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
