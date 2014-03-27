<?php
/**
 * @file
 * Default theme implementation to display an adminify section.
 */
?>
<?php print $link; ?>
<?php if (count($pages)): ?>
  <ul id="<?php print $section_id; ?>" class="section-pages collapse">
    <?php foreach ($pages as $page): ?>
      <li><?php print $page; ?></li>
    <?php endforeach; ?>
  </ul>
<?php endif; ?>
