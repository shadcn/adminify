<?php

/**
 * @file
 * Admin page callbacks for the radix_admin module.
 */

/**
 * Callback for admin path.
 */
function adminify_menu_block_page() {
  if (user_is_anonymous()) {
    // Show the login form if user is not logged in.
    return drupal_get_form('user_login');
  }
  else if (user_access('access administration pages')) {
    // Show the default admin.
    module_load_include('inc', 'system', 'system.admin');
    return system_admin_menu_block_page();
  }
  else {
    drupal_goto('<front>');
  }
}