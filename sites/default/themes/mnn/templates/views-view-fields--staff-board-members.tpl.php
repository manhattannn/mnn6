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

//foreach($fields as $key => $value){
//	print '<br>key: '.$key;
//}

?>

<div class="person clearfix">
	<?php if ($fields['field_photo_fid']) : ?>
		<div class="photo"><?php print $fields['field_photo_fid']->content ?></div>
	<?php endif; ?>
	<div class="copy-column">
		<h3 class="name"><?php print $fields['title']->content ?></h3>
		<div class="title"><?php print $fields['field_title_value']->content ?></div>
		<div class="body-copy"><?php print $fields['body']->content ?></div>
		<div class="contact-info"><?php print $fields['field_contact_info_value']->content ?></div>
	</div>
</div>
