<article class="yc-service node <?php print $classes; ?>" id="node-<?php print $node->nid; ?>">

    <div class="content">
	    <?php
		    if ($node->field_image[0]['filepath'])
		      print theme('imagecache', 'yc-our-services', $node->field_image[0]['filepath']);
        print $node->content['body']['#value'];
      ?>
    </div>
 

</article>

<?php
/*print '<pre>';
print_r($node);
print '</pre>';*/
?>