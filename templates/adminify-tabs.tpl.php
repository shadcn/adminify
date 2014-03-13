<?php

/**
 * @file
 * Default theme implementation to display the adminify tabs.
 */
?>
<?php if (count($tabs)): ?>
  <ul class="nav nav-pills pull-right">
    <?php foreach ($tabs as $title => $path): ?>
      <li><?php print l($title, $path); ?></li>
    <?php endforeach; ?>
  </ul>
<?php endif; ?>
