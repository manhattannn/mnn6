<?php

ctools_include('mnnshow.common', 'mnnshow', '');

/**
 * Page callback.
 */
function mnnshow_schedule(){
  jquery_ui_add('ui.datepicker');

  mnnshow_include_tooltip();

  drupal_add_js(drupal_get_path('module', 'mnnshow').'/mnnshow.js');
  $content = '<div id="schedule"><header id="schedule-header"><div class="inner"><div class="nav clearfix"></div><div class="channels"></div></div></header><div id="cols"></div></div> ';
  return $content;
}