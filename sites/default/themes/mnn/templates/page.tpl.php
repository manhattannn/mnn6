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

<div id="skip"><a href="#content"><?php print t('Skip to Content'); ?></a> <a href="#navigation"><?php print t('Skip to Navigation'); ?></a></div>
<div id="page">


	<header>

		<nav id="main-menu" class="menu">
			<div class="pinch">
				<?php print $main_menu ?>
			</div>
		</nav>

		<hgroup id="logo-title">
			<div class="pinch">
				<?php if (!empty($logo)): ?>
				<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
					<img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/>
				</a>
				<?php endif; ?>

				<?php if (!empty($site_slogan)): ?>
				<div id="site-slogan"><?php print $site_slogan; ?></div>
				<?php endif; ?>

				<?php print $search_box; ?>
			</div>
		</hgroup>

		<?php if ($sub_header): ?>
		<div id="sub-header">
			<div class="pinch">
				<?php print $sub_header; ?>
			</div>
		</div>
		<?php endif; ?>

	</header>

	<?php if ($header): ?>
	<div id="header">
		<?php print $header; ?>
	</div>
	<?php endif; ?>

	<?php if ($watch_now): ?>
	<section id="watch-now">
		<div class="pinch">
			<?php print $watch_now ?>
		</div>
	</section>
	<?php endif; ?>

	<section id="main" class="clearfix">
		<?php print $main_top; ?>
		<div class="pinch">

			<div id="content">
				<?php if ($breadcrumb || $title || $mission || $messages || $help || $tabs): ?>
				<header id="content-header">

					<?php print $breadcrumb; ?>

					<?php if ($mission): ?>
					<div id="mission"><?php print $mission; ?></div>
					<?php endif; ?>

					<?php print $messages; ?>

					<?php print $help; ?>

					<?php if ($tabs): ?>
					<nav class="tabs"><?php print $tabs; ?></nav>
					<?php endif; ?>

				</header>
				<?php endif; ?>

				<div id="content-inner" class="inner column center">

					<?php if ($content_header) : ?>
					<div id="content-header-content">
						<?php print $content_header ?>
					</div>
					<?php endif; ?>

					<?php if ($title): ?>
					<div id="title"><h1 class="title"><?php print $title; ?></h1></div>
					<?php endif; ?>

					<?php if ($content_top): ?>
					<section id="content-top">
						<?php print $content_top; ?>
					</section>
					<?php endif; ?>

					<div id="content-area">
						<?php print $content; ?>
					</div> <!-- /#content-area -->

					<?php print $feed_icons; ?>

					<?php if ($content_bottom): ?>
					<div id="content-bottom">
						<?php print $content_bottom; ?>
					</div>
					<?php endif; ?>

				</div>
			</div>

			<?php if ($sidebar_first): ?>
			<aside id="sidebar-first" class="column sidebar first">
				<?php print $sidebar_first; ?>
			</aside>
			<?php endif; ?>

			<?php if ($sidebar_second): ?>
			<aside id="sidebar-second" class="column sidebar second">
				<?php print $sidebar_second; ?>
			</aside>
			<?php endif; ?>

		</div>
	</section>


	<?php if(!empty($above_footer)): ?>
	<footer id="above-footer">
		<div class="pinch">
			<?php print $above_footer; ?>
		</div>
	</footer>
	<?php endif; ?>

	<?php if(!empty($footer_message) || !empty($footer)): ?>
	<footer id="footer">
		<div class="pinch">
			<?php print $footer_message; ?>
			<?php print $footer; ?>
		</div>
	</footer>
	<?php endif; ?>

	<?php if(!empty($sub_footer)): ?>
	<footer id="sub-footer">
		<div class="pinch">
			<?php print $sub_footer; ?>
		</div>
	</footer>
	<?php endif; ?>

</div>
<?php print $closure; ?>
</body>
</html>
