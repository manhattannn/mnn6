<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function event_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_section';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events/*' => 'events/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-upcoming_events-block_1' => array(
          'module' => 'views',
          'delta' => 'upcoming_events-block_1',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['events_section'] = $context;

  return $export;
}
