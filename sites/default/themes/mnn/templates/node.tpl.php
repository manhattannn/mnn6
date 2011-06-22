<article class="node <?php print $classes; ?>" id="node-<?php print $node->nid; ?>">
  <header>
    <?php if (!$page): ?>
      <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>

    <?php if ($submitted): ?>
      <small class="submitted"><?php print $submitted; ?></small>
    <?php endif; ?>
        
  </header>
  
    <div class="content">
      <?php print $content; ?>
    </div>
 

</article>