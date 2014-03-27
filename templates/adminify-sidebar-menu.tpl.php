<?php

/**
 * @file
 * Default theme implementation to display the adminify sidebar.
 */
?>
<nav class="sidebar-menu">
  <ul class="nav">
    <?php foreach ($sections as $section): ?>
      <li><?php print $section; ?></li>
    <?php endforeach; ?>
  </ul>
</nav>
