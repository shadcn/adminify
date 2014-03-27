<?php

/**
 * @file
 * Default theme implementation to display the adminify tabs.
 */
?>
<?php if (count($tabs)): ?>
  <ul class="nav nav-pills pull-right tabs">
    <?php foreach ($tabs as $tab): ?>
      <li><?php print $tab; ?></li>
    <?php endforeach; ?>
  </ul>
<?php endif; ?>
