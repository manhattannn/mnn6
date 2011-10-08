<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function certification_class_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function certification_class_feature_imagecache_default_presets() {
  $items = array(
    'certification-class-instructor' => array(
      'presetname' => 'certification-class-instructor',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '133',
            'height' => '133',
          ),
        ),
      ),
    ),
    'certification-class-tracks' => array(
      'presetname' => 'certification-class-tracks',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '139',
            'height' => '90',
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
function certification_class_feature_node_info() {
  $items = array(
    'cert_class' => array(
      'name' => t('Certification Class'),
      'module' => 'features',
      'description' => t('A certification class.'),
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
function certification_class_feature_views_api() {
  return array(
    'api' => '2',
  );
}
