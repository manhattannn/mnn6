<article class="yc-join node <?php print $classes; ?>" id="node-<?php print $node->nid; ?>">
  <header>
    <?php if (!$page): ?>
      <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>

  </header>
  
    <div class="content">
	    <?php
		    if ($node->field_image[0]['filepath'])
		      print theme('imagecache', 'news', $node->field_image[0]['filepath']);
        print $node->content['body']['#value'];
      ?>
    </div>
 

</article>

<?php
/*print '<pre>';
print_r($node);
print '</pre>';*/
?>