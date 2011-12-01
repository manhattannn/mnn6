<?php

/**
 * Implementation of hook_strongarm().
 */
function yc_workshop_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_yc_workshop';
  $strongarm->value = 0;
  $export['comment_anonymous_yc_workshop'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_yc_workshop';
  $strongarm->value = '3';
  $export['comment_controls_yc_workshop'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_yc_workshop';
  $strongarm->value = '4';
  $export['comment_default_mode_yc_workshop'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_yc_workshop';
  $strongarm->value = '1';
  $export['comment_default_order_yc_workshop'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_yc_workshop';
  $strongarm->value = '50';
  $export['comment_default_per_page_yc_workshop'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_yc_workshop';
  $strongarm->value = '0';
  $export['comment_form_location_yc_workshop'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_yc_workshop';
  $strongarm->value = '1';
  $export['comment_preview_yc_workshop'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_yc_workshop';
  $strongarm->value = '1';
  $export['comment_subject_field_yc_workshop'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_yc_workshop';
  $strongarm->value = '0';
  $export['comment_yc_workshop'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_yc_workshop';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-2',
    'revision_information' => '2',
    'author' => '1',
    'options' => '3',
    'comment_settings' => '6',
    'menu' => '-4',
    'path' => '7',
    'custom_breadcrumbs' => '5',
    'path_redirect' => '4',
    'workflow' => '0',
  );
  $export['content_extra_weights_yc_workshop'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enable_revisions_page_yc_workshop';
  $strongarm->value = 1;
  $export['enable_revisions_page_yc_workshop'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_yc_workshop';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_yc_workshop'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_yc_workshop';
  $strongarm->value = '';
  $export['page_title_type_yc_workshop'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_yc_workshop_showfield';
  $strongarm->value = 0;
  $export['page_title_type_yc_workshop_showfield'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_yc_workshop_pattern';
  $strongarm->value = 'youth-channel/our-services/workshops/[title-raw]';
  $export['pathauto_node_yc_workshop_pattern'] = $strongarm;

  return $export;
}
