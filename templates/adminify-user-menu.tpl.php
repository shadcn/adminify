<?php

/**
 * @file
 * Default theme implementation to display the user menu.
 */
?>
<?php if (count($links)): ?>
  <nav class="sidebar-menu">
    <ul class="nav">
      <?php foreach ($links as $link): ?>
        <li><?php print $link; ?></li>
      <?php endforeach; ?>
    </ul>
  </nav>
<?php endif; ?>
