<?php

/**
 * Implementation of hook_strongarm().
 */
function news_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_pattern';
  $strongarm->value = 'news/[title-raw]';
  $export['pathauto_node_news_pattern'] = $strongarm;

  return $export;
}
