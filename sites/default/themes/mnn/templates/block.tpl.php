<?php

/**
 * @file
 * HTML5 Base's theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $block->content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $block_classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user module
 *     is responsible for handling the default user navigation block. In that case
 *     the class would be "block-user".
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 */

/*
 * ADD ATTRIBUTES TO THE BLOCK
 * see http://drupal.org/node/197694
 * and http://webdeveloper.beforeseven.com/drupal/give-your-drupal-blocks-more-descriptive-html-id-attribute
*/
// Add standard block class
$default_class = 'clear-block block'. ($block->module ? ' block-'. $block->module : '') . ' ' . $block_zebra;
if (function_exists(block_class))
	$default_class .= ' ' . block_class($block); // 'block_edit' module

if (!isset($block->attributes))
  $block->attributes = array();
if (!isset($block->attributes['class']))
  $block->attributes['class'] = $default_class;
else
  $block->attributes['class'] = $default_class .' '. $block->attributes['class'];

if (!isset($block->attributes['id'])) {
  /*
   * GIVE A READABLE ID TO THE BLOCK (instead of Drupal's useless block-module-29)
  */
  $info = module_invoke($block->module, 'block', 'list');
  if ($info[$block->delta]['info']) {
    $block_id = 'block-' . $block->module . '-' . $info[$block->delta]['info'];
    $block_id = str_replace(array('(', ')', ':','!'), '', strtolower($block_id));
    $block_id = str_replace(array(' ', '_'), '-', strtolower($block_id));
    $block->attributes['id'] = $block_id;
  }
  else {
    $block->attributes['id'] = 'block-' . $block->module . '-' . $block-delta;
  }
}
?>
<div <?php print drupal_attributes($block->attributes); ?>>
  <div class="top">
    <?php if (!empty($block->subject)): ?>
      <h3 class="title block-title"><?php print $block->subject; ?></h3>
    <?php endif; ?>
  </div>
  <div class="outer"><div class="inner">
    <div class="content"><?php print $block->content; ?></div>
  </div></div>
</div>
