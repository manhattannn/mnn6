<article class="cert-class node <?php print $classes; ?>" id="node-<?php print $node->nid; ?>">

  <header>
    <?php if (!$page): ?>
      <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
  </header>
  
	<div class="content">
		<?php print $node->content['body']['#value']; ?>
	</div>

  <div class="location">
    <h2>Location</h2>
    <?php 
      foreach ($node->field_class_locations as $key => $value) {
        print '<p>'. $value['value'] .'</p>';
      }
    ?>
  </div>
	<?php if ($node->field_instructor[0]['nid']){	$instructor = node_load($node->field_instructor[0]['nid']);	}	?>
	<?php if ($instructor) : ?>
	<div class="instructor">
		<h2>Instructor</h2>
		<div class="photo"><?php print theme('imagecache', 'certification-class-instructor', $instructor->field_photo[0]['filepath']) ?></div>
		<div class="copy-column">
			<h3 class="name"><?php print $instructor->title ?></h3>
			<div class="title"><?php print $instructor->field_title[0]['value'] ?></div>
			<div class="body-copy"><?php print $instructor->body ?></div>
			<div class="contact-info"><?php print $instructor->field_contact_info[0]['value'] ?></div>
		</div>
	</div>
	<?php endif; ?>

</article>

<?php
// print '<pre>';
// print_r($node);
// print '</pre>';
?>
