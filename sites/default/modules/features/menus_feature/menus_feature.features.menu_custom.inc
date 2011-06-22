<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function menus_feature_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer-resources
  $menus['menu-footer-resources'] = array(
    'menu_name' => 'menu-footer-resources',
    'title' => 'Footer Resources',
    'description' => 'The Resources menu in the Footer.',
  );
  // Exported menu: menu-main-menu
  $menus['menu-main-menu'] = array(
    'menu_name' => 'menu-main-menu',
    'title' => 'Main Menu',
    'description' => 'The menu at the top of the page (above the header area).',
  );
  // Exported menu: menu-main-menu-right
  $menus['menu-main-menu-right'] = array(
    'menu_name' => 'menu-main-menu-right',
    'title' => 'Main Menu Right',
    'description' => 'The menu at the top <em>right</em> of the page (above the header area).',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer Resources');
  t('Main Menu');
  t('Main Menu Right');
  t('The Resources menu in the Footer.');
  t('The menu at the top <em>right</em> of the page (above the header area).');
  t('The menu at the top of the page (above the header area).');


  return $menus;
}
