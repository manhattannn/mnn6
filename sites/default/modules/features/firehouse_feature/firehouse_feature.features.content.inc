<?php

/**
 * Implementation of hook_content_default_fields().
 */
function firehouse_feature_content_default_fields() {
  $fields = array();

  // Exported field: field_landing_description
  $fields['community_studio_dialogue-field_landing_description'] = array(
    'field_name' => 'field_landing_description',
    'type_name' => 'community_studio_dialogue',
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
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '3',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_landing_description][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Landing Page Description',
      'weight' => '-1',
      'description' => 'A short description of this Community Studio Dialogue used on the Community Studio Dialogues landing page.',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_landing_image
  $fields['community_studio_dialogue-field_landing_image'] = array(
    'field_name' => 'field_landing_image',
    'type_name' => 'community_studio_dialogue',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
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
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => 'community-studio-dialog',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'insert' => 0,
      'insert_styles' => array(
        'auto' => 0,
        'link' => 0,
        'image' => 0,
        'imagecache_certification-class-instructor' => 0,
        'imagecache_certification-class-tracks' => 0,
        'imagecache_homepage-news' => 0,
        'imagecache_inline-image-content-width' => 0,
        'imagecache_inline-image-half-content-width' => 0,
        'imagecache_main-feature-slideshow' => 0,
        'imagecache_news' => 0,
        'imagecache_person-board-of-directors' => 0,
        'imagecache_person-management' => 0,
        'imagecache_person-upper-management' => 0,
        'imagecache_video_thumb' => 0,
        'imagecache_yc-homepage-news' => 0,
        'imagecache_yc-join-now' => 0,
        'imagecache_yc-join-now-thumb' => 0,
        'imagecache_yc-news' => 0,
        'imagecache_yc-our-services' => 0,
        'imagecache_yc-video-thumb' => 0,
      ),
      'insert_default' => 'auto',
      'insert_class' => '',
      'insert_width' => '',
      'label' => 'Landing Page Image',
      'weight' => 0,
      'description' => 'The small thumbnail image used on the Community Studio Dialogues landing page.',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_main_image
  $fields['community_studio_dialogue-field_main_image'] = array(
    'field_name' => 'field_main_image',
    'type_name' => 'community_studio_dialogue',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
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
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => 'community-studio-dialog',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 1,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'insert' => 0,
      'insert_styles' => array(
        'auto' => 0,
        'link' => 0,
        'image' => 0,
        'imagecache_certification-class-instructor' => 0,
        'imagecache_certification-class-tracks' => 0,
        'imagecache_homepage-news' => 0,
        'imagecache_inline-image-content-width' => 0,
        'imagecache_inline-image-half-content-width' => 0,
        'imagecache_main-feature-slideshow' => 0,
        'imagecache_news' => 0,
        'imagecache_person-board-of-directors' => 0,
        'imagecache_person-management' => 0,
        'imagecache_person-upper-management' => 0,
        'imagecache_video_thumb' => 0,
        'imagecache_yc-homepage-news' => 0,
        'imagecache_yc-join-now' => 0,
        'imagecache_yc-join-now-thumb' => 0,
        'imagecache_yc-news' => 0,
        'imagecache_yc-our-services' => 0,
        'imagecache_yc-video-thumb' => 0,
      ),
      'insert_default' => 'auto',
      'insert_class' => '',
      'insert_width' => '',
      'label' => 'Main Image',
      'weight' => '-2',
      'description' => 'The main image that gets inset on the content page. Add a caption by using the "title" field to the right.',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Landing Page Description');
  t('Landing Page Image');
  t('Main Image');

  return $fields;
}
