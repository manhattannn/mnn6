<?php

ctools_include('mnnshow.common', 'mnnshow', '');

/**
 * Page callback.
 */
function mnnshow_show_redirect_to_schedule_page()
{
  drupal_goto('schedule');
}