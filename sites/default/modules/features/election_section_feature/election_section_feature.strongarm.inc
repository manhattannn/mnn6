<?php

/**
 * Implementation of hook_strongarm().
 */
function election_section_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_election_candidate';
  $strongarm->value = 0;
  $export['comment_anonymous_election_candidate'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_election_district';
  $strongarm->value = 0;
  $export['comment_anonymous_election_district'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_election_video';
  $strongarm->value = 0;
  $export['comment_anonymous_election_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_election_video_feed';
  $strongarm->value = 0;
  $export['comment_anonymous_election_video_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_feedzilla_json_feed';
  $strongarm->value = 0;
  $export['comment_anonymous_feedzilla_json_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_feedzilla_json_feed_item';
  $strongarm->value = 0;
  $export['comment_anonymous_feedzilla_json_feed_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_election_candidate';
  $strongarm->value = '3';
  $export['comment_controls_election_candidate'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_election_district';
  $strongarm->value = '3';
  $export['comment_controls_election_district'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_election_video';
  $strongarm->value = '3';
  $export['comment_controls_election_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_election_video_feed';
  $strongarm->value = '3';
  $export['comment_controls_election_video_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_feedzilla_json_feed';
  $strongarm->value = '3';
  $export['comment_controls_feedzilla_json_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_feedzilla_json_feed_item';
  $strongarm->value = '3';
  $export['comment_controls_feedzilla_json_feed_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_election_candidate';
  $strongarm->value = '4';
  $export['comment_default_mode_election_candidate'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_election_district';
  $strongarm->value = '4';
  $export['comment_default_mode_election_district'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_election_video';
  $strongarm->value = '4';
  $export['comment_default_mode_election_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_election_video_feed';
  $strongarm->value = '4';
  $export['comment_default_mode_election_video_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_feedzilla_json_feed';
  $strongarm->value = '4';
  $export['comment_default_mode_feedzilla_json_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_feedzilla_json_feed_item';
  $strongarm->value = '4';
  $export['comment_default_mode_feedzilla_json_feed_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_election_candidate';
  $strongarm->value = '1';
  $export['comment_default_order_election_candidate'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_election_district';
  $strongarm->value = '1';
  $export['comment_default_order_election_district'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_election_video';
  $strongarm->value = '1';
  $export['comment_default_order_election_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_election_video_feed';
  $strongarm->value = '1';
  $export['comment_default_order_election_video_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_feedzilla_json_feed';
  $strongarm->value = '1';
  $export['comment_default_order_feedzilla_json_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_feedzilla_json_feed_item';
  $strongarm->value = '1';
  $export['comment_default_order_feedzilla_json_feed_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_election_candidate';
  $strongarm->value = '50';
  $export['comment_default_per_page_election_candidate'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_election_district';
  $strongarm->value = '50';
  $export['comment_default_per_page_election_district'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_election_video';
  $strongarm->value = '50';
  $export['comment_default_per_page_election_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_election_video_feed';
  $strongarm->value = '50';
  $export['comment_default_per_page_election_video_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_feedzilla_json_feed';
  $strongarm->value = '50';
  $export['comment_default_per_page_feedzilla_json_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_feedzilla_json_feed_item';
  $strongarm->value = '50';
  $export['comment_default_per_page_feedzilla_json_feed_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_election_candidate';
  $strongarm->value = '0';
  $export['comment_election_candidate'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_election_district';
  $strongarm->value = '0';
  $export['comment_election_district'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_election_video';
  $strongarm->value = '0';
  $export['comment_election_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_election_video_feed';
  $strongarm->value = '0';
  $export['comment_election_video_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_feedzilla_json_feed';
  $strongarm->value = '0';
  $export['comment_feedzilla_json_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_feedzilla_json_feed_item';
  $strongarm->value = '0';
  $export['comment_feedzilla_json_feed_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_election_candidate';
  $strongarm->value = '0';
  $export['comment_form_location_election_candidate'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_election_district';
  $strongarm->value = '0';
  $export['comment_form_location_election_district'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_election_video';
  $strongarm->value = '0';
  $export['comment_form_location_election_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_election_video_feed';
  $strongarm->value = '0';
  $export['comment_form_location_election_video_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_feedzilla_json_feed';
  $strongarm->value = '0';
  $export['comment_form_location_feedzilla_json_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_feedzilla_json_feed_item';
  $strongarm->value = '0';
  $export['comment_form_location_feedzilla_json_feed_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_election_candidate';
  $strongarm->value = '1';
  $export['comment_preview_election_candidate'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_election_district';
  $strongarm->value = '1';
  $export['comment_preview_election_district'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_election_video';
  $strongarm->value = '1';
  $export['comment_preview_election_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_election_video_feed';
  $strongarm->value = '1';
  $export['comment_preview_election_video_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_feedzilla_json_feed';
  $strongarm->value = '1';
  $export['comment_preview_feedzilla_json_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_feedzilla_json_feed_item';
  $strongarm->value = '1';
  $export['comment_preview_feedzilla_json_feed_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_election_candidate';
  $strongarm->value = '1';
  $export['comment_subject_field_election_candidate'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_election_district';
  $strongarm->value = '1';
  $export['comment_subject_field_election_district'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_election_video';
  $strongarm->value = '1';
  $export['comment_subject_field_election_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_election_video_feed';
  $strongarm->value = '1';
  $export['comment_subject_field_election_video_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_feedzilla_json_feed';
  $strongarm->value = '1';
  $export['comment_subject_field_feedzilla_json_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_feedzilla_json_feed_item';
  $strongarm->value = '1';
  $export['comment_subject_field_feedzilla_json_feed_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_election_candidate';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '6',
    'author' => '5',
    'options' => '7',
    'comment_settings' => '10',
    'menu' => '-4',
    'path' => '11',
    'custom_breadcrumbs' => '9',
    'path_redirect' => '8',
    'workflow' => '4',
  );
  $export['content_extra_weights_election_candidate'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_election_district';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '9',
    'author' => '10',
    'options' => '11',
    'comment_settings' => '15',
    'menu' => '7',
    'taxonomy' => '-3',
    'path' => '14',
    'custom_breadcrumbs' => '12',
    'path_redirect' => '13',
    'workflow' => '8',
  );
  $export['content_extra_weights_election_district'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_election_video';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-2',
    'revision_information' => '1',
    'author' => '0',
    'options' => '2',
    'comment_settings' => '5',
    'menu' => '-3',
    'path' => '6',
    'custom_breadcrumbs' => '4',
    'path_redirect' => '3',
    'workflow' => '-1',
  );
  $export['content_extra_weights_election_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_feedzilla_json_feed_item';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-2',
    'revision_information' => '2',
    'author' => '3',
    'options' => '4',
    'comment_settings' => '8',
    'menu' => '-3',
    'taxonomy' => '-4',
    'path' => '7',
    'custom_breadcrumbs' => '6',
    'path_redirect' => '5',
    'workflow' => '1',
  );
  $export['content_extra_weights_feedzilla_json_feed_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_election_candidate';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_election_candidate'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_election_district';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_election_district'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_election_video';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_election_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_election_video_feed';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_election_video_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_feedzilla_json_feed';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_feedzilla_json_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_feedzilla_json_feed_item';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_feedzilla_json_feed_item'] = $strongarm;

  return $export;
}
