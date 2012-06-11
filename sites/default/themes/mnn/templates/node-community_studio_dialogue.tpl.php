<?php 

$main_image = theme('imagecache', 'firehouse-main', $node->field_main_image[0]['filepath']);
$main_image_caption = $node->field_main_image[0]['data']['title'];
$body = $node->content['body']['#value'];
?>

<article class="community-studio-dialogue node <?php print $classes; ?>" id="node-<?php print $node->nid; ?>">
  
  <div class="content">
		<div class="main-image image-wrapper">
			<?php print $main_image ?>
			<?php if ($main_image_caption) : ?>
				<div class="caption"><?php print $main_image_caption ?></div>
			<?php endif ?>
		</div>
		<div class="body-copy"><?php print $body ?></div>
  </div>

</article>

<?php
 // print '<pre>';
	// print_r($node);
 // print '</pre>';
?>