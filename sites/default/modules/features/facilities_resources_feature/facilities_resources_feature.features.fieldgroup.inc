<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function facilities_resources_feature_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_address
  $groups['resources-group_address'] = array(
    'group_type' => 'standard',
    'type_name' => 'resources',
    'group_name' => 'group_address',
    'label' => 'Address',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '0',
    'fields' => array(
      '0' => 'field_street',
      '1' => 'field_city',
      '2' => 'field_state',
      '3' => 'field_zipcode',
    ),
  );

  // Exported group: group_website
  $groups['resources-group_website'] = array(
    'group_type' => 'standard',
    'type_name' => 'resources',
    'group_name' => 'group_website',
    'label' => 'Website',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '-2',
    'fields' => array(
      '0' => 'field_display_text',
      '1' => 'field_url',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Address');
  t('Website');

  return $groups;
}
