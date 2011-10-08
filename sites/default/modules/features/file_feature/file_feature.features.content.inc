<?php

/**
 * Implementation of hook_content_default_fields().
 */
function file_feature_content_default_fields() {
  $fields = array();

  // Exported field: field_file
  $fields['file-field_file'] = array(
    'field_name' => 'field_file',
    'type_name' => 'file',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'txt doc pdf',
      'file_path' => 'files',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '20M',
      'max_filesize_per_node' => '20M',
      'label' => 'The File',
      'weight' => '-3',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('The File');

  return $fields;
}
