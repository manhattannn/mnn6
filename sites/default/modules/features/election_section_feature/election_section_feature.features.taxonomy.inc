<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function election_section_feature_taxonomy_default_vocabularies() {
  return array(
    'election_distrift' => array(
      'name' => 'Election District',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '0',
      'required' => '0',
      'tags' => '0',
      'module' => 'features_election_distrift',
      'weight' => '0',
      'nodes' => array(
        'feedzilla_json_feed' => 'feedzilla_json_feed',
        'feed_fast' => 'feed_fast',
        'election_video_feed' => 'election_video_feed',
        'election_video' => 'election_video',
        'election_district' => 'election_district',
        'feedzilla_json_feed_item' => 'feedzilla_json_feed_item',
      ),
    ),
  );
}
