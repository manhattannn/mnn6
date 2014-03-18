<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function election_section_feature_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_bar_chart
  $groups['election_district-group_bar_chart'] = array(
    'group_type' => 'standard',
    'type_name' => 'election_district',
    'group_name' => 'group_bar_chart',
    'label' => 'Bar Chart',
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
    'weight' => '6',
    'fields' => array(),
  );

  // Exported group: group_charts
  $groups['election_district-group_charts'] = array(
    'group_type' => 'standard',
    'type_name' => 'election_district',
    'group_name' => 'group_charts',
    'label' => 'Charts',
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
    'weight' => '4',
    'fields' => array(
      '0' => 'field_show_pie_chart',
      '1' => 'field_pie_chart_title',
      '2' => 'field_pie_chart_data',
      '3' => 'field_show_bar_chart',
      '4' => 'field_bar_chart_title',
      '5' => 'field_bar_chart_yaxis_label',
      '6' => 'field_bar_chart_data',
    ),
  );

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
    'weight' => '3',
    'fields' => array(
      '0' => 'field_show_stat_1',
      '1' => 'field_stat_1_label',
      '2' => 'field_stat_1_data',
      '3' => 'field_show_stat_2',
      '4' => 'field_stat_2_label',
      '5' => 'field_stat_2_data',
      '6' => 'field_show_stat_3',
      '7' => 'field_stat_3_label',
      '8' => 'field_stat_3_data',
      '9' => 'field_election_district_populati',
      '10' => 'field_election_median_income',
      '11' => 'field_election_unemployment_rate',
      '12' => 'field_election_race_ethnicity',
      '13' => 'field_election_housing',
    ),
  );

  // Exported group: group_pie_chart
  $groups['election_district-group_pie_chart'] = array(
    'group_type' => 'standard',
    'type_name' => 'election_district',
    'group_name' => 'group_pie_chart',
    'label' => 'Pie Chart',
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
    'weight' => '5',
    'fields' => array(),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Bar Chart');
  t('Charts');
  t('District Stats');
  t('Pie Chart');

  return $groups;
}
