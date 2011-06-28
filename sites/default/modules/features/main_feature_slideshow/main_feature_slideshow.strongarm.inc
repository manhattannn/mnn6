<?php

/**
 * Implementation of hook_strongarm().
 */
function main_feature_slideshow_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_main_feature_slideshow';
  $strongarm->value = 0;

  $export['comment_anonymous_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_main_feature_slideshow';
  $strongarm->value = '3';

  $export['comment_controls_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_main_feature_slideshow';
  $strongarm->value = '4';

  $export['comment_default_mode_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_main_feature_slideshow';
  $strongarm->value = '1';

  $export['comment_default_order_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_main_feature_slideshow';
  $strongarm->value = '50';

  $export['comment_default_per_page_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_main_feature_slideshow';
  $strongarm->value = '0';

  $export['comment_form_location_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_main_feature_slideshow';
  $strongarm->value = '0';

  $export['comment_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_main_feature_slideshow';
  $strongarm->value = '1';

  $export['comment_preview_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_main_feature_slideshow';
  $strongarm->value = '1';

  $export['comment_subject_field_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_attach_main_feature_slideshow';
  $strongarm->value = '0';

  $export['image_attach_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_attach_maximum_main_feature_slideshow';
  $strongarm->value = '0';

  $export['image_attach_maximum_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_attach_size_body_main_feature_slideshow';
  $strongarm->value = 'thumbnail';

  $export['image_attach_size_body_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_attach_size_teaser_main_feature_slideshow';
  $strongarm->value = 'thumbnail';

  $export['image_attach_size_teaser_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_main_feature_slideshow';
  $strongarm->value = array(
    0 => 'revision',
  );

  $export['node_options_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_main_feature_slideshow';
  $strongarm->value = '';

  $export['page_title_type_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_main_feature_slideshow_showfield';
  $strongarm->value = 0;

  $export['page_title_type_main_feature_slideshow_showfield'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_main_feature_slideshow_pattern';
  $strongarm->value = 'main-feature-slideshow/[title-raw]';

  $export['pathauto_node_main_feature_slideshow_pattern'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_main_feature_slideshow';
  $strongarm->value = 0;

  $export['scheduler_publish_enable_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_main_feature_slideshow';
  $strongarm->value = 0;

  $export['scheduler_publish_required_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_main_feature_slideshow';
  $strongarm->value = 0;

  $export['scheduler_publish_revision_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_main_feature_slideshow';
  $strongarm->value = 0;

  $export['scheduler_publish_touch_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_main_feature_slideshow';
  $strongarm->value = 0;

  $export['scheduler_unpublish_enable_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_main_feature_slideshow';
  $strongarm->value = 0;

  $export['scheduler_unpublish_required_main_feature_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_main_feature_slideshow';
  $strongarm->value = 0;

  $export['scheduler_unpublish_revision_main_feature_slideshow'] = $strongarm;
  return $export;
}
