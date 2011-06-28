<?php

/**
 * Implementation of hook_node_info().
 */
function channel_info_feature_node_info() {
  $items = array(
    'channel_info' => array(
      'name' => t('Channel Info'),
      'module' => 'features',
      'description' => t('Basic information about a channel.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '1',
      'body_label' => t('Brief Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
