<?php
$channel = node_load($node->field_channel[0]['nid']);

$block = module_invoke('mnnmisc', 'block', 'view', '2');

?>

<article class="watch-live node <?php print $classes; ?>" id="node-<?php print $node->nid; ?>">

	<div class="video">
		<?php print $node->content['body']['#value']; ?>
	</div>

	<header>
      <h1 class="title"><?php print $title; ?></h1>
  </header>
  
    <div class="content">
	    <?php
	      $current_show = mnnshow_current_show_info($channel->field_number[0]['value']);
	      print '<h3>'. $current_show['title']. '</h3>';
		    print '<div class="category">'. $current_show['category'] .'</div>';
		    print '<div class="content">' . $current_show['description'] . '</div>';
	      print $current_show[''];
				if ($current_show['public_url']){
					print '<div class="website"><span class="label">Website: </span><a href="'. $current_show['public_url'] .'">'. $current_show['public_url'] .'</a></div>';
				}
        print $node->links['addthis']['title'];
        print $block['content'];
	    ?>
    </div>

</article>

<pre><?php //print_r($block) ?></pre>
<pre><?php //print_r($channel) ?></pre>

