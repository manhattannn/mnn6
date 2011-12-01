<?php

/**
 * @file
 *
 * This file contains the theme functions for the module.
 */

/**
 * Theme function for getting the URL for a file attached on the node.  Can use
 * the description or its index.
 * @param $fid
 * @param $node
 * @param bool $use_ID
 * @return bool|string
 */
function theme_jwplayermodule_get_attachment_url($fid, $node, $use_ID = FALSE) {
  $count = 0;
  if (isset($node) && isset($node->files)) {
    foreach ($node->files as $file) {
      if ($fid == $file->description || ($fid == $count && $use_ID)) {
        $path_array = explode("/", $file->filepath);
        $path_array[count($path_array) - 1] = $file->filename;
        return $GLOBALS["base_url"] . "/" . implode("/", $path_array);
      }
      $count++;
    }
  }
  return FALSE;
}

/**
 * Theme function for generating the SWFObject embed code for a player.
 */
function theme_jwplayermodule_render_player($config, $flash_vars) {
  static $done = FALSE;
  LongTailFramework::setConfig($config);
  $useEmbedder = file_exists(LongTailFramework::getEmbedderPath());
  $swf = LongTailFramework::generateSWFObject($flash_vars, $useEmbedder);
  if (!$done) {
    if ($useEmbedder) {
      drupal_add_js(LongTailFramework::getEmbedderPath(), "module");
      drupal_add_js(drupal_get_path("module", "jwplayermodule") . "/jwplayermodule_jwembedder.js", "module", "footer");
    } else {
      $external_js = "http://ajax.googleapis.com/ajax/libs/swfobject/2.2/swfobject.js";
      //Drupal 6.x cannot add external javascript normally.  This hack circumvents that.
      drupal_add_js('document.write(unescape("%3Cscript src=\''. $external_js . '\' type=\'text/javascript\'%3E%3C/script%3E"));', 'inline');
      drupal_add_js(drupal_get_path("module", "jwplayermodule") . "/jwplayermodule_swfobject.js", "module", "footer");
    }
    $done = TRUE;
  }
  drupal_add_js($swf->getConfig(), "setting", "footer", FALSE, TRUE, FALSE);
  return $swf->generateDiv();
}

function theme_jwplayermodule_admin($form) {
  $rows = array();
  $output = "";
  if (isset($form["Manage"]["Players"])) {
    foreach(element_children($form["Manage"]["Players"]) as $key) {
      $row = array();
      foreach (element_children($form["Manage"]["Players"][$key]) as $fvar) {
        $row[] = array("data" => drupal_render($form["Manage"]["Players"][$key][$fvar]));
      }
      $rows[] = $row;
    }
    $header = array();
    $header[] = array("data" => t("Default"), "class" => "radio");
    $header[] = t("Players");
    $header[] = t("Control Bar");
    $header[] = t("Skin");
    $header[] = t("Dock");
    $header[] = t("Autostart");
    $header[] = t("Height");
    $header[] = t("Width");
    $header[] = t("Actions");
    $form["Manage"]["Players"]["#value"] .= theme("table", $header, $rows);
  } else if (isset($form["JWPlugins"])) {
    jquery_ui_add('ui.tabs');
    $form["JWPlugins"]["#value"] .= "<div id='tabs'><ul id='tabNavigation'>";
    foreach(element_children($form["JWPlugins"]) as $key) {
      $form["JWPlugins"]["#value"] .= "<li id='$key" . "_tab'>" . drupal_render($form["JWPlugins"][$key]["tab"]) . "</li>";
    }
    $form["JWPlugins"]["#value"] .= "</ul>";
    foreach(element_children($form["JWPlugins"]) as $key) {
      $form["JWPlugins"]["#value"] .= "<div id='$key'>" . drupal_render($form["JWPlugins"][$key]["body"]) . "</div>";
    }
    $form["JWPlugins"]["#value"] .= "</div>";
  }
  if (isset($form["Breadcrumbs"])) {
    $output .= "<div id='breadcrumbs'>";
    foreach(element_children($form["Breadcrumbs"]) as $key) {
      $breadcrumb = $form["Breadcrumbs"][$key];
      drupal_render($form["Breadcrumbs"][$key]);
      $output .= "<input onclick='form.submit();' type='" . $breadcrumb["#type"] . "' id='$key' name='" . $breadcrumb["#name"] . "' value='" . $breadcrumb["#return_value"] ."'";
      if ($breadcrumb["#default_value"] == $breadcrumb["#return_value"]) {
        $output .= " checked='checked'";
      }
      $output .= ">";
      $output .= "<label for='" . $key . "' role='button'";
      if ($breadcrumb["#default_value"] == $breadcrumb["#return_value"]) {
        $output .= " class='Active'";
      }
      $output .= "><span>" . $breadcrumb["#title"] . "</span></label>";
    }
    $output .= "</div>";
  }
  $output .= drupal_render($form);
  return $output;
}