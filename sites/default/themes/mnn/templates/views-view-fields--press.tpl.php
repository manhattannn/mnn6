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

// dpm($fields);

$type = $fields['field_link_type_value']->content . $fields['field_download_type_value']->content;
$url = $fields['field_press_link_url']->content . $fields['field_press_download_fid']->content;

?>

<div class="press-item">
  <div class="date-type">
    <span class="date"><?php print $fields['created']->content ?></span> &nbsp; | &nbsp; <span class="type"><?php print $type ?></span>
  </div>
  <div class="name">
    <a href="<?php print $url ?>" target="_blank"><?php print $fields['title']->content ?></a>
  </div>
</div>
