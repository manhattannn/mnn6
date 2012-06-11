<?php

/**
 * Implementation of hook_strongarm().
 */
function firehouse_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_community_studio_dialogue';
  $strongarm->value = 0;
  $export['comment_anonymous_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_community_studio_dialogue';
  $strongarm->value = '0';
  $export['comment_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_community_studio_dialogue';
  $strongarm->value = '3';
  $export['comment_controls_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_community_studio_dialogue';
  $strongarm->value = '4';
  $export['comment_default_mode_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_community_studio_dialogue';
  $strongarm->value = '1';
  $export['comment_default_order_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_community_studio_dialogue';
  $strongarm->value = '50';
  $export['comment_default_per_page_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_community_studio_dialogue';
  $strongarm->value = '0';
  $export['comment_form_location_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_community_studio_dialogue';
  $strongarm->value = '1';
  $export['comment_preview_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_community_studio_dialogue';
  $strongarm->value = '1';
  $export['comment_subject_field_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_community_studio_dialogue';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-3',
    'revision_information' => '3',
    'author' => '2',
    'options' => '4',
    'comment_settings' => '7',
    'menu' => '-4',
    'path' => '8',
    'custom_breadcrumbs' => '6',
    'path_redirect' => '5',
    'workflow' => '1',
  );
  $export['content_extra_weights_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_show_form_table_community_studio_dialogue';
  $strongarm->value = 0;
  $export['custom_breadcrumbs_show_form_table_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enable_revisions_page_community_studio_dialogue';
  $strongarm->value = 1;
  $export['enable_revisions_page_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_attach_community_studio_dialogue';
  $strongarm->value = '0';
  $export['image_attach_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_attach_maximum_community_studio_dialogue';
  $strongarm->value = '0';
  $export['image_attach_maximum_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_attach_size_body_community_studio_dialogue';
  $strongarm->value = 'thumbnail';
  $export['image_attach_size_body_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_attach_size_teaser_community_studio_dialogue';
  $strongarm->value = 'thumbnail';
  $export['image_attach_size_teaser_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_community_studio_dialogue';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_community_studio_dialogue';
  $strongarm->value = '';
  $export['page_title_type_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_community_studio_dialogue_showfield';
  $strongarm->value = 0;
  $export['page_title_type_community_studio_dialogue_showfield'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_community_studio_dialogue_pattern';
  $strongarm->value = 'community-studio-dialogues/[title-raw]';
  $export['pathauto_node_community_studio_dialogue_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_community_studio_dialogue';
  $strongarm->value = 0;
  $export['show_diff_inline_community_studio_dialogue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_community_studio_dialogue';
  $strongarm->value = 1;
  $export['show_preview_changes_community_studio_dialogue'] = $strongarm;

  return $export;
}
