<?php
// $Id: views-view-fields.tpl.php,v 1.6 2008/09/24 22:48:21 merlinofchaos Exp $
/**
 * @file views-view-fields.tpl.php
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->separator: an optional separator that may appear before a field.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>

<?php

$img = $fields['field_image_fid'];
print $img->content;
print '<div class="datetime-category">';
print $fields['created']->content .' '. $fields['tid']->content;
print '</div>';
print '<h3 class="title">'. $fields['title']->content .'</h3>';
print '<div class="content">';
if ($img->content)
	print $fields['body']->content;
else
	print $fields['body_1']->content;
print '</div>';
$path = 'node/'. $fields['nid']->content;
print '<div>'. l('Continue Reading', $path, array('attributes' => array('class' => 'read-more'))) .'</div>';

?>