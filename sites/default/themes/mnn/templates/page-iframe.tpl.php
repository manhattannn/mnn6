<!DOCTYPE html>
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>" <?php print $modernizr_head; ?>>

<head>
	<title><?php print $head_title; ?></title>
	<?php print $head; ?>
	<?php print $styles; ?>
	<?php print $scripts; ?>
	<!-- www.phpied.com/conditional-comments-block-downloads/ -->
	<!--[if IE]><![endif]-->
	<?php // Add HTML5 shiv if Modernizr is not included
	if (!theme_get_setting('html5_base_modernizr')): ?>
		<!--[if lt IE 9]><script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script><![endif]-->
		<?php endif; ?>
</head>

<!-- paulirish.com/2008/conditional-stylesheets-vs-css-hacks-answer-neither/ -->

<!--[if lt IE 7 ]> <body id="<?php print $body_id ?>" class="ie6 <?php print $body_classes; ?>"> <![endif]-->
<!--[if IE 7 ]>    <body id="<?php print $body_id ?>" class="ie7 <?php print $body_classes; ?>"> <![endif]-->
<!--[if IE 8 ]>    <body id="<?php print $body_id ?>" class="ie8 <?php print $body_classes; ?>"> <![endif]-->
<!--[if IE 9 ]>    <body id="<?php print $body_id ?>" class="ie9 <?php print $body_classes; ?>"> <![endif]-->
<!--[if (gt IE 9)|!(IE)]><!--> <body id="<?php print $body_id ?>" class="<?php print $body_classes; ?>"> <!--<![endif]-->

<div id="iframe-page">
	<?php print $content; ?>
</div>
<?php print $closure; ?>
</body>
</html>
