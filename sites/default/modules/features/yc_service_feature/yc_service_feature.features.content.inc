<?php

/**
 * Implementation of hook_content_default_fields().
 */
function yc_service_feature_content_default_fields() {
  $fields = array();

  // Exported field: field_weight
  $fields['yc_service-field_weight'] = array(
    'field_name' => 'field_weight',
    'type_name' => 'yc_service',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
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
  t('Weight');

  return $fields;
}
