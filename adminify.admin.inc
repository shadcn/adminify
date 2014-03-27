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
  global $user;

  if (user_is_anonymous()) {
    // Show the login form if user is not logged in.
    return drupal_get_form('user_login');
  }
  else if (_adminify_user_is_adminified($user)) {
    // Show the adminify dashboard.
    return t('Welcome to your administration dashboard.');
  }
  else if (user_access('access administration pages')) {
    // Show the default admin.
    module_load_include('inc', 'system', 'system.admin');
    return system_admin_menu_block_page();
  }
  else {
    // Redirect to front page.
    drupal_goto('');
  }
}
