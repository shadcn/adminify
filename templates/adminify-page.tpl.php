<?php

/**
 * @file
 * Default theme implementation to display the adminify page.
 */
?>

<?php if ($sidebar_menu): ?>
  <aside id="sidebar-left" class="sidebar">
    <div class="brand">
      <a href="/admin" class="logo"><span>Admin</span>ify</a>
    </div>
    <?php print $sidebar_menu; ?>
  </aside>
<?php endif; ?>

<section class="main-wrapper container">
  <div class="row header">
    <?php if ($sidebar_menu): ?>
      <div class="col-xs-1 text-left">
        <a href="#" data-toggle="push" data-target="#sidebar-left" data-position="right">
          <i class="fa fa-bars fa-border fa-2x"></i>
        </a>
      </div>
    <?php endif; ?>

    <div class="col-xs-10 text-center">
      <h1><?php print $title; ?></h1>
    </div>

    <?php if ($user_menu): ?>
      <div class="col-xs-1 text-right">
        <a href="#" data-toggle="push" data-target="#sidebar-right" data-position="left">
          <i class="fa fa-user fa-border fa-2x"></i>
        </a>
      </div>
    <?php endif; ?>
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
</section>

<?php if ($user_menu): ?>
  <aside id="sidebar-right" class="sidebar">
    <?php print $user_menu; ?>
  </aside>
<?php endif; ?>
