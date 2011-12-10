<?php
// $Id: context_reaction_addjs_path.inc,v 1.1.2.1 2010/09/16 19:55:19 electblake Exp $

/**
 * @file
 * The Context reaction plugin to add Module CSS files
 *
 * Contextually add Module CSS files to any page on your site.
 */

/**
 * Expose themes as context reactions.
 */
class context_reaction_addjs_path extends context_reaction_addjs {

  function __construct($plugin, $info) {
    parent::__construct($plugin, $info);
    $this->search_scope = 'paths';
    $this->title = t('JS from File Paths');
  }

}