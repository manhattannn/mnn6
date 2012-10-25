<?php
module_load_include('inc', 'mnnshow', 'includes/mnnshow.common');

$channel = node_load($node->field_channel[0]['nid']);

$url = (!empty($_SERVER['HTTPS']))
  ? "https://".$_SERVER['SERVER_NAME']
  : "http://".$_SERVER['SERVER_NAME'];
$embed_url = drupal_get_path_alias('node/'. $node->field_iframe_embed_url[0]['nid']);
$embed_code = '<iframe src="'. $url .'/'. $embed_url .'?iframe=1" frameborder="0" width="600" height="334" scrolling="no" allowfullscreen></iframe>';
$embed_code = htmlspecialchars($embed_code);

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
	    ?>
      <a href='#' class='modal-trigger watch-live-button' data-modal-element='video-embed-code'>Embed this video</a>
      <div id='video-embed-code'>
        <h3>Embed this video</h3>
        <h5>Copy the embed code below, and paste it to your website.</h5>
        <textarea class="embed-code select-all" spellcheck="false"><?php print $embed_code ?></textarea>
      </div>
    </div>

</article>


