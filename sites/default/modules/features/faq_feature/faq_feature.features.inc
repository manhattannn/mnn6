<?php

/**
 * Implementation of hook_node_info().
 */
function faq_feature_node_info() {
  $items = array(
    'faq' => array(
      'name' => t('FAQ'),
      'module' => 'features',
      'description' => t('A frequently asked question, with its associated answer.'),
      'has_title' => '1',
      'title_label' => t('Question'),
      'has_body' => '1',
      'body_label' => t('Answer'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function faq_feature_views_api() {
  return array(
    'api' => '2',
  );
}
