<article class="watch-live node <?php print $classes; ?>" id="node-<?php print $node->nid; ?>">

	<div class="video">
		<?php print $node->field_video_feed[0]['view']; ?>
	</div>

	<header>
      <h1 class="title"><?php print $title; ?></h1>
  </header>
  
    <div class="content">
      <?php print $node->content['body']['#value']; ?>
      <?php print $node->links['addthis']['title']; ?>
    </div>
 

</article>

<pre><?php //print_r($node) ?></pre>