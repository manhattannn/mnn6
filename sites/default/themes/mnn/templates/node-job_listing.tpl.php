<article class="node job-listing <?php print $classes; ?>" id="node-<?php print $node->nid; ?>">

  <div class="type-date clearfix">
    <div class="type"><?php print $node->field_employment_type[0]['view'] ?></div>
    <div class="date">Posted <?php print date('F j, Y', $node->created) ?></div>
  </div>
  <div class="body-copy"><?php print $node->content['body']['#value'] ?></div>
  <div class="application-link"><a href="<?php print $node->field_application_link[0]['value'] ?>">Submit application</a></div>

</article>

<?php 

// print '<pre>';
// print_r($node);
// print '</pre>';

 ?>