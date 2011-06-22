<?php

/*
 *	 This function creates the body classes that are relative to each page
 *
 *	@param $vars
 *	  A sequential array of variables to pass to the theme template.
 *	@param $hook
 *	  The name of the theme function being called ("page" in this case.)
 */
function mnn_preprocess_page(&$vars, $hook) {
	if ($vars['is_front']) {
		$body_id = $section_class = 'homepage';
	}
	else {
		// Remove base path and any query string.
		global $base_path;
		list(,$path) = explode($base_path, $_SERVER['REQUEST_URI'], 2);
		list($path,) = explode('?', $path, 2);
		$path = rtrim($path, '/');
		// Construct the id name from the path, replacing slashes with dashes.
		$body_id = str_replace('/', '-', $path);
		// Construct the class name from the first part of the path only.
		list($section_class,) = explode('/', $path, 2);
	}
	$body_id = 'page-'. $body_id;
	$section_class = 'section-'. $section_class;

  $vars['body_classes'] .= ' ' . $section_class;
	$vars['body_id'] = $body_id;
}
