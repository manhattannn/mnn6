<article class="election-video node <?php print $classes; ?>" id="node-<?php print $node->nid; ?>">

	<div class="video">
		<?php print $node->field_video[0]['view']; ?>
	</div>

	<header>
      <h1 class="title"><?php print $title; ?></h1>

    <?php if ($submitted): ?>
      <small class="meta-data">
	      <span class="date"><?php print date('M j, Y', $node->created); ?></span>
	      <span class="video-duration"><?php print gmdate('i:s', intval($node->field_video[0]['duration'])) ?></span>
      </small>
    <?php endif; ?>

  </header>

    <div class="content">
      <?php print $node->content['body']['#value']; ?>
	    <?php print $node->links['addthis']['title']; ?>
    </div>


</article>

<?php
//print '<pre>';
//print_r($node);
//print '</pre>';
?>
