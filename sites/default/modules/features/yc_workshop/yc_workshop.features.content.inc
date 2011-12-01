<?php

/**
 * Implementation of hook_content_default_fields().
 */
function yc_workshop_content_default_fields() {
  $fields = array();

  // Exported field: field_inline_images
  $fields['yc_workshop-field_inline_images'] = array(
    'field_name' => 'field_inline_images',
    'type_name' => 'yc_workshop',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'image_plain',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'image_plain',
        'exclude' => 1,
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
    'required' => '0',
    'multiple' => '1',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => 'workshop-inline-images',
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
      'insert' => 1,
      'insert_styles' => array(
        'link' => 'link',
        'image' => 'image',
        'imagecache_inline-image-content-width' => 'imagecache_inline-image-content-width',
        'auto' => 0,
        'imagecache_certification-class-instructor' => 0,
        'imagecache_certification-class-tracks' => 0,
        'imagecache_homepage-news' => 0,
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
      'insert_default' => 'imagecache_inline-image-content-width',
      'insert_class' => '',
      'insert_width' => '',
      'label' => 'Inline Images',
      'weight' => '-1',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_weight
  $fields['yc_workshop-field_weight'] = array(
    'field_name' => 'field_weight',
    'type_name' => 'yc_workshop',
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
    'type' => 'number_integer',
    'required' => '1',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => 'for($i=-50;$i<=50;$i++)$options[]=$i;
return $options;',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '50',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Weight',
      'weight' => '-3',
      'description' => 'Weight controls where in the resulting page that this item will show up. Smaller numbers will appear at the top.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Inline Images');
  t('Weight');

  return $fields;
}
