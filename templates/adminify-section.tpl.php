<?php
/**
 * @file
 * Default theme implementation to display an adminify section.
 */
?>
<a href="#">
  <?php if ($icon): ?>
    <i class="icon fa fa-<?php print $icon; ?>"></i>
  <?php endif; ?>
  <?php print $title; ?>
  <?php if (count($pages)): ?>
    <i class="arrow fa fa-angle-right pull-right"></i>
  <?php endif; ?>
</a>
<?php if (count($pages)): ?>
  <ul class="section-pages">
    <?php foreach ($pages as $page): ?>
      <li><?php print $page; ?></li>
    <?php endforeach; ?>
  </ul>
<?php endif; ?>
