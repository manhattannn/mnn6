<article class="event node <?php print $classes; ?>" id="node-<?php print $node->nid; ?>">
  <header class="clearfix">
    <?php if ($node->taxonomy): ?>
      <small class="taxonomy">
	      <?php
					foreach($node->taxonomy as $tax) {
	          if ($tax->vid != 12) // do not show the 'Event Types' terms (mnn-sponsored, community-sponsored, etc).
							$categories .= $tax->name .', ';
					}
			    $len = strlen($categories);
		      print substr($categories, 0, ($len - 2));
	      ?>
      </small>
    <?php endif; ?>

		<div class="date-time-address">
			<div class="date"><?php print date('F j, Y', strtotime($node->field_date[0]['value'])) ?></div>
			<div class="time"><?php print date('g:i A', strtotime($node->field_dates[0]['value'])) ?></div>
			<div class="address"><?php print $node->field_address[0]['safe'] ?></div>
		</div>

  </header>
  
    <div class="content">
      <?php print $node->content['body']['#value']; ?>
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

<pre>
	<?php //print_r($node); ?>
</pre>
