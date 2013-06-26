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

$news_url = $fields['url']->content;
$news_publish_date = $fields['field_publish_date_value']->content;
$news_title = $fields['title']->content;
$news_body = $fields['body']->content;

$news_date = date_create_from_format('D, j M Y G:i:s P', $news_publish_date);

?>

<div class="election-news">
  <div class="date"><?php print $news_date->format('F j, Y g:i A') ?></div>
  <h4 class="title"><a href="<?php print $news_url ?>" target="_blank"><?php print $news_title ?></a></h4>
  <div class="summary"><?php print $news_body ?></div>
  <div class="read-more"><a href="<?php print $news_url ?>" target="_blank">Continue Reading</a></div>
</div>
