<?php

/**
 * Implementation of hook_content_default_fields().
 */
function watch_live_feature_content_default_fields() {
  $fields = array();

  // Exported field: field_channel
  $fields['watch_live-field_channel'] = array(
    'field_name' => 'field_channel',
    'type_name' => 'watch_live',
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
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'channel_info' => 'channel_info',
      'block_content' => 0,
      'cert_class' => 0,
      'faq' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'image' => 0,
      'main_feature_slideshow' => 0,
      'news' => 0,
      'page' => 0,
      'television_channel' => 0,
      'television_station' => 0,
      'video' => 0,
      'watch_live' => 0,
      'webform' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'MNN Channel',
      'weight' => '-2',
      'description' => '',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('MNN Channel');

  return $fields;
}
