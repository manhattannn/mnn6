<?php
// $Id: context_reaction_addcss.inc,v 1.1.2.2 2010/09/17 14:46:00 electblake Exp $

/**
 * @file
 * The Context reaction plugin to add CSS files
 *
 * Contextually add CSS files to any page on your site.
 */

// Load the base Add Assets Reaction class
if (!class_exists('context_reaction_addassets_base')) {
  module_load_include('inc', 'context_addassets', 'plugins/context_reaction_addassets_base');
}

/**
 * Expose themes as context reactions.
 */
class context_reaction_addcss extends context_reaction_addassets_base {
  var $search_scope;
  function __construct($plugin, $info) {
    parent::__construct($plugin, $info);
    $this->title = t('CSS from Themes');
    $this->search_type = 'css';
  }
}