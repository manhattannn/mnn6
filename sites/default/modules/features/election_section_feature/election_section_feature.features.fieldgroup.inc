<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function election_section_feature_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_district_stats
  $groups['election_district-group_district_stats'] = array(
    'group_type' => 'standard',
    'type_name' => 'election_district',
    'group_name' => 'group_district_stats',
    'label' => 'District Stats',
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
    'weight' => '2',
    'fields' => array(
      '0' => 'field_election_district_populati',
      '1' => 'field_election_median_income',
      '2' => 'field_election_unemployment_rate',
      '3' => 'field_pie_chart_title',
      '4' => 'field_pie_chart_data',
      '5' => 'field_bar_chart_title',
      '6' => 'field_bar_chart_yaxis_label',
      '7' => 'field_bar_chart_data',
      '8' => 'field_election_race_ethnicity',
      '9' => 'field_election_housing',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('District Stats');

  return $groups;
}
