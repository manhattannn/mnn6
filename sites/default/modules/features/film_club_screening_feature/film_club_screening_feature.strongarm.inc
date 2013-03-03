<?php

/**
 * Implementation of hook_strongarm().
 */
function film_club_screening_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_film_club_screening';
  $strongarm->value = 0;
  $export['comment_anonymous_film_club_screening'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_film_club_screening';
  $strongarm->value = '3';
  $export['comment_controls_film_club_screening'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_film_club_screening';
  $strongarm->value = '4';
  $export['comment_default_mode_film_club_screening'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_film_club_screening';
  $strongarm->value = '1';
  $export['comment_default_order_film_club_screening'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_film_club_screening';
  $strongarm->value = '50';
  $export['comment_default_per_page_film_club_screening'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_film_club_screening';
  $strongarm->value = '0';
  $export['comment_film_club_screening'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_film_club_screening';
  $strongarm->value = '0';
  $export['comment_form_location_film_club_screening'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_film_club_screening';
  $strongarm->value = '1';
  $export['comment_preview_film_club_screening'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_film_club_screening';
  $strongarm->value = '1';
  $export['comment_subject_field_film_club_screening'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_film_club_screening';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-3',
    'revision_information' => '3',
    'author' => '2',
    'options' => '4',
    'comment_settings' => '7',
    'menu' => '-4',
    'path' => '8',
    'custom_breadcrumbs' => '6',
    'path_redirect' => '5',
    'workflow' => '1',
  );
  $export['content_extra_weights_film_club_screening'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_film_club_screening';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_film_club_screening'] = $strongarm;

  return $export;
}
