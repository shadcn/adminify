<?php

/**
 * @file
 * Admin callbacks for adminify module.
 */

/**
 * Provides a the admin dashboard for logged in users.
 * Shows a login form for anonymous users.
 */
function adminify_admin_menu_block_page() {
  if (user_is_anonymous()) {
    // Show the login form if user is not logged in.
    return drupal_get_form('user_login');
  }
  else if (user_access('Use the administration pages and help')) {
    // Show the admin dashboard.
    return t('Welcome to your administration dashboard.');
  }
  else {
    // Redirect to front page.
    drupal_goto('');
  }
}
