<?php

/**
 * Implementation of hook_strongarm().
 */
function yc_join_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_yc_join';
  $strongarm->value = 0;
  $export['comment_anonymous_yc_join'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_yc_join';
  $strongarm->value = '3';
  $export['comment_controls_yc_join'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_yc_join';
  $strongarm->value = '4';
  $export['comment_default_mode_yc_join'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_yc_join';
  $strongarm->value = '1';
  $export['comment_default_order_yc_join'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_yc_join';
  $strongarm->value = '50';
  $export['comment_default_per_page_yc_join'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_yc_join';
  $strongarm->value = '0';
  $export['comment_form_location_yc_join'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_yc_join';
  $strongarm->value = '1';
  $export['comment_preview_yc_join'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_yc_join';
  $strongarm->value = '1';
  $export['comment_subject_field_yc_join'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_yc_join';
  $strongarm->value = '0';
  $export['comment_yc_join'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_yc_join';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '1',
    'revision_information' => '3',
    'author' => '2',
    'options' => '4',
    'comment_settings' => '7',
    'menu' => '-4',
    'taxonomy' => '-1',
    'path' => '8',
    'custom_breadcrumbs' => '5',
    'path_redirect' => '6',
  );
  $export['content_extra_weights_yc_join'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_yc_join';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_yc_join'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_yc_join_pattern';
  $strongarm->value = 'youth-channel/join/[title-raw]';
  $export['pathauto_node_yc_join_pattern'] = $strongarm;

  return $export;
}
