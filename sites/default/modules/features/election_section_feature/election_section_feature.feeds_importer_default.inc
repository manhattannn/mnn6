<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function election_section_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'election_video_feed_importer';
  $feeds_importer->config = array(
    'name' => 'Election Video Feed Importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSimplePieParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'election_video',
        'update_existing' => '0',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => TRUE,
          ),
          4 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => TRUE,
          ),
          5 => array(
            'source' => 'enclosures',
            'target' => 'field_video',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'parent:taxonomy:features_election_distrift',
            'target' => 'taxonomy:features_election_distrift',
            'unique' => FALSE,
          ),
        ),
        'input_format' => '2',
        'author' => 0,
        'authorize' => 0,
      ),
    ),
    'content_type' => 'election_video_feed',
    'update' => 0,
    'import_period' => '3600',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );
  $export['election_video_feed_importer'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'feedzilla_json_importer';
  $feeds_importer->config = array(
    'name' => 'Feedzilla JSON Importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsJSONPathParser',
      'config' => array(
        'context' => 'articles.*',
        'sources' => array(
          'jsonpath_parser:0' => 'title',
          'jsonpath_parser:1' => 'summary',
          'jsonpath_parser:2' => 'publish_date',
          'jsonpath_parser:3' => 'url',
        ),
        'debug' => array(
          'options' => array(
            'context' => 0,
            'jsonpath_parser:0' => 0,
            'jsonpath_parser:1' => 0,
            'jsonpath_parser:2' => 0,
            'jsonpath_parser:3' => 0,
          ),
        ),
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'feedzilla_json_feed_item',
        'input_format' => '0',
        'update_existing' => '0',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'parent:taxonomy:features_election_distrift',
            'target' => 'taxonomy:features_election_distrift',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'jsonpath_parser:0',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'jsonpath_parser:1',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'jsonpath_parser:2',
            'target' => 'field_publish_date',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'jsonpath_parser:3',
            'target' => 'url',
            'unique' => FALSE,
          ),
        ),
        'author' => 0,
        'authorize' => 0,
      ),
    ),
    'content_type' => 'feedzilla_json_feed',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );
  $export['feedzilla_json_importer'] = $feeds_importer;

  return $export;
}
