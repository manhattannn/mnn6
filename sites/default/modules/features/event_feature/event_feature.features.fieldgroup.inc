<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function event_feature_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_submitter_info
  $groups['event-group_submitter_info'] = array(
    'group_type' => 'standard',
    'type_name' => 'event',
    'group_name' => 'group_submitter_info',
    'label' => 'Submitter Information:',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => 'Please enter your contact information so we can contact you with any questions. Your contact information will only be available to site administrators, and will not be visible to the public.',
      ),
      'display' => array(
        'description' => '',
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
        'label' => 'above',
      ),
    ),
    'weight' => '1',
    'fields' => array(
      '0' => 'field_full_name',
      '1' => 'field_phone',
      '2' => 'field_email',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Submitter Information:');

  return $groups;
}
