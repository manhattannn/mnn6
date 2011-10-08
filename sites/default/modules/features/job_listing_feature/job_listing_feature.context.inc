<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function job_listing_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'job_listings_page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'about-us/job-listings' => 'about-us/job-listings',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-job_listings-block_1' => array(
          'module' => 'views',
          'delta' => 'job_listings-block_1',
          'region' => 'content_bottom',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['job_listings_page'] = $context;

  return $export;
}
