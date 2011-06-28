<?php
$orig_title = $title;
drupal_set_title('Shows');
?>

<article class="show node <?php print $classes; ?>" id="node-<?php print $node->nid; ?>">
  <header>
    <h2 class="title"><?php print $orig_title; ?></h2>

    <?php if ($node->taxonomy): ?>
      <small class="taxonomy">
	      <?php
					foreach($node->taxonomy as $tax) {
						$categories .= '<a href="#">'. $tax->name .'</a>, ';
					}
			    $len = strlen($categories);
		      print substr($categories, 0, ($len - 2));
	      ?>
      </small>
    <?php endif; ?>
        
  </header>
  
    <div class="content">
      <?php print $node->content['body']['#value']; ?>
    </div>

	<div class="share">
		<?php print $node->links['addthis']['title']; ?>
	</div>
 

</article>

<pre>
	<?php print_r($node); ?>
</pre>
