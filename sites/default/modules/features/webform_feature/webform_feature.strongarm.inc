<?php

/**
 * Implementation of hook_strongarm().
 */
function webform_feature_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_webform';
  $strongarm->value = array(
    'webform' => '0',
    'title' => '-5',
    'body_field' => '-1',
    'revision_information' => '2',
    'author' => '1',
    'options' => '3',
    'comment_settings' => '5',
    'menu' => '-3',
    'taxonomy' => '-4',
    'path' => '6',
    'path_redirect' => '4',
  );

  $export['content_extra_weights_webform'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_webform_pattern';
  $strongarm->value = 'forms/[title-raw]';

  $export['pathauto_node_webform_pattern'] = $strongarm;
  return $export;
}
