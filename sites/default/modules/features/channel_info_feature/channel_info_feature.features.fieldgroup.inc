<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function channel_info_feature_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_provider_a
  $groups['channel_info-group_provider_a'] = array(
    'group_type' => 'standard',
    'type_name' => 'channel_info',
    'group_name' => 'group_provider_a',
    'label' => 'Provider A',
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
    'weight' => '-1',
    'fields' => array(
      '0' => 'field_provider_a_name',
      '1' => 'field_provider_a_number',
    ),
  );

  // Exported group: group_provider_b
  $groups['channel_info-group_provider_b'] = array(
    'group_type' => 'standard',
    'type_name' => 'channel_info',
    'group_name' => 'group_provider_b',
    'label' => 'Provider B',
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
      '0' => 'field_provider_b_name',
      '1' => 'field_provider_b_number',
    ),
  );

  // Exported group: group_provider_c
  $groups['channel_info-group_provider_c'] = array(
    'group_type' => 'standard',
    'type_name' => 'channel_info',
    'group_name' => 'group_provider_c',
    'label' => 'Provider C',
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
    'weight' => '1',
    'fields' => array(
      '0' => 'field_provider_c_name',
      '1' => 'field_provider_c_number',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Provider A');
  t('Provider B');
  t('Provider C');

  return $groups;
}
