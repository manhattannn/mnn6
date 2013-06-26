<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function election_section_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function election_section_feature_imagecache_default_presets() {
  $items = array(
    'election-main-photo' => array(
      'presetname' => 'election-main-photo',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '640',
            'height' => '390',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function election_section_feature_node_info() {
  $items = array(
    'election_candidate' => array(
      'name' => t('Election Candidate'),
      'module' => 'features',
      'description' => t('An individual candidate running for election.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'election_district' => array(
      'name' => t('Election District'),
      'module' => 'features',
      'description' => t('An individual district in Manhattan.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'election_video' => array(
      'name' => t('Election Video'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'election_video_feed' => array(
      'name' => t('Election Video Feed'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'feedzilla_json_feed' => array(
      'name' => t('Feedzilla JSON Feed'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'feedzilla_json_feed_item' => array(
      'name' => t('Feedzilla JSON Feed Item'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function election_section_feature_views_api() {
  return array(
    'api' => '2',
  );
}
