<?php

/**
 * Implementation of hook_strongarm().
 */
function certification_class_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_cert_class';
  $strongarm->value = 0;
  $export['comment_anonymous_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_cert_class';
  $strongarm->value = '0';
  $export['comment_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_cert_class';
  $strongarm->value = '3';
  $export['comment_controls_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_cert_class';
  $strongarm->value = '4';
  $export['comment_default_mode_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_cert_class';
  $strongarm->value = '1';
  $export['comment_default_order_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_cert_class';
  $strongarm->value = '50';
  $export['comment_default_per_page_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_cert_class';
  $strongarm->value = '0';
  $export['comment_form_location_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_cert_class';
  $strongarm->value = '1';
  $export['comment_preview_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_cert_class';
  $strongarm->value = '1';
  $export['comment_subject_field_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_cert_class';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '2',
    'revision_information' => '4',
    'author' => '3',
    'options' => '5',
    'comment_settings' => '8',
    'menu' => '-4',
    'taxonomy' => '-1',
    'path' => '9',
    'custom_breadcrumbs' => '6',
    'path_redirect' => '7',
    'workflow' => '10',
  );
  $export['content_extra_weights_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_show_form_table_cert_class';
  $strongarm->value = 1;
  $export['custom_breadcrumbs_show_form_table_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_attach_cert_class';
  $strongarm->value = '0';
  $export['image_attach_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_attach_maximum_cert_class';
  $strongarm->value = '0';
  $export['image_attach_maximum_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_attach_size_body_cert_class';
  $strongarm->value = 'thumbnail';
  $export['image_attach_size_body_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_attach_size_teaser_cert_class';
  $strongarm->value = 'thumbnail';
  $export['image_attach_size_teaser_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cert_class';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_cert_class';
  $strongarm->value = '';
  $export['page_title_type_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_cert_class_showfield';
  $strongarm->value = 0;
  $export['page_title_type_cert_class_showfield'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_cert_class_pattern';
  $strongarm->value = '[termpath-raw]/classes/[title-raw]';
  $export['pathauto_node_cert_class_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_cert_class';
  $strongarm->value = 0;
  $export['scheduler_publish_enable_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_cert_class';
  $strongarm->value = 0;
  $export['scheduler_publish_required_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_cert_class';
  $strongarm->value = 0;
  $export['scheduler_publish_revision_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_cert_class';
  $strongarm->value = 0;
  $export['scheduler_publish_touch_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_cert_class';
  $strongarm->value = 0;
  $export['scheduler_unpublish_enable_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_cert_class';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_cert_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_cert_class';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_cert_class'] = $strongarm;

  return $export;
}
