<article class="watch-live node <?php print $classes; ?>" id="node-<?php print $node->nid; ?>">

	<div class="video">
		<?php print $node->content['body']['#value']; ?>
	</div>

	<header>
      <h1 class="title"><?php print $title; ?></h1>
  </header>
  
    <div class="content">
	    <?php print $node->field_description[0]['view']; ?>
      <?php print $node->links['addthis']['title']; ?>
    </div>
 

</article>

<pre><?php //print_r($node) ?></pre>