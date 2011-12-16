<article class="news node <?php print $classes; ?>" id="node-<?php print $node->nid; ?>">
  <header class="clearfix">

	  <?php
		  $categories = array();
	    if ($node->taxonomy){
				foreach($node->taxonomy as $tax) {
					$categories[] = $tax->name;
				}
	    }
	    $author = user_load($node->uid);
	  ?>
	  <span class="post-date"><?php print date('M j, Y', $node->created) ?></span><span class="taxonomy"><?php print implode(', ', $categories); ?></span><span class="author">By <?php print $author->profile_fullname ?></span>

  </header>
  
    <div class="content">
			<?php
			  if ($node->field_image[0]['filepath'])
					print theme('imagecache', 'yc-news', $node->field_image[0]['filepath']);
		    print $node->content['body']['#value'];
	    ?>
    </div>

	<?php if ($node->field_link[0]['view']): ?>
		<div class="event-link">
			<a href="<?php print $node->field_link[0]['safe'] ?>">Event Link</a>
		</div>
	<?php endif; ?>

	<div class="share">
		<?php print $node->links['addthis']['title']; ?>
	</div>
 

</article>

<?php
//  print '<pre>';
//	print_r($node);
//  print '</pre>';
?>