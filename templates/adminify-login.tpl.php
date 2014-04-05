<?php
/**
 * @file
 * Default theme implementation to display the adminify login page.
 */
?>
<div class="container">
  <?php print $messages; ?>
  <div class="brand">
    <a href="/admin" class="logo"><span>Admin</span>ify</a>
  </div>
  <?php print render($page['content']); ?>
</div>
