<?php

/**
 * @file
 * Admin callbacks for adminify module.
 */


/**
 * Provide a the admin dashboard for logged in users.
 * Shows a login form for anonymous users.
 */
function adminify_admin_menu_block_page() {
  // Show the login form if user is not logged in.
  if (user_is_anonymous()) {
    return drupal_get_form('user_login');
  }

  // Show the administration page otherwise.
  return t('Welcome to your administration dashboard.');
}
