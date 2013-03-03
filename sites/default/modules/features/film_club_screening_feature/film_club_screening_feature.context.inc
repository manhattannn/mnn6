<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function film_club_screening_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'firehouse_film_club';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'about-us/firehouse/film-club' => 'about-us/firehouse/film-club',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-film_club_screenings-block_1' => array(
          'module' => 'views',
          'delta' => 'film_club_screenings-block_1',
          'region' => 'content_bottom',
          'weight' => 0,
        ),
      ),
      'layout' => 'no_sidebars',
    ),
  );
  $context->condition_mode = 0;
  $export['firehouse_film_club'] = $context;

  return $export;
}
