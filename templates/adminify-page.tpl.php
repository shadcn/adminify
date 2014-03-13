<?php

/**
 * @file
 * Default theme implementation to display the adminify page.
 */
?>

<aside class="sidebar">
  <?php print $sidebar; ?>
</aside>

<section class="main-wrapper container">
  <div class="row header">
    <div class="col-xs-1 text-left">
      <i class="fa fa-bars fa-border fa-2x"></i>
    </div>
    <div class="col-xs-10 text-center">
      <h1><?php print $title; ?></h1>
    </div>
    <div class="col-xs-1 text-right">
      <i class="fa fa-user fa-border fa-2x"></i>
    </div>
  </div>
  <div class="row tabs-wrapper">
    <div class="col-md-6 text-left">
      <?php print render($breadcrumb); ?>
    </div>
    <div class="col-md-6 text-right">
      <?php print $tabs; ?>
    </div>
  </div>
  <div class="row main">
    <?php print $messages; ?>
    <div class="col-md-12">
      <?php print render($page['content']); ?>
    </div>
  </div>
</div>
