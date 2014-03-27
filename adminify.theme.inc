<?php

/**
 * @file
 * Theme and preprocess functions for adminify module.
 */

/**
 * Implements hook_preprocess_adminify_page().
 */
function adminify_preprocess_adminify_page(&$variables, $hook) {
  global $user;

  // Add messages to adminify template.
  $variables['messages'] = theme('status_messages');

  // Add the logged in user as adminify_user.
  $variables['adminify_user'] = $user;
  $variables['adminify_username'] = theme('username', array('account' => $user));

  // Add sidebar.
  $variables['sidebar'] = theme('adminify_sidebar');

  // Add tabs.
  $variables['tabs'] = theme('adminify_tabs');
  // $action_links = _adminify_get_page_action_links();
  // $variables['action_links'] = theme('adminify_action_links', array('links' => $action_links));

  // Add the page title.
  $variables['title'] = drupal_get_title();

  // Add breadcrumb.
  // TODO: Breadcrumb should be built from adminify paths.
  $variables['breadcrumb'] = theme('breadcrumb', array('breadcrumb' => drupal_get_breadcrumb()));
}

/**
 * Implements hook_preprocess().
 */
function adminify_preprocess_adminify_login(&$variables, $hook) {
  // Add messages to adminify template.
  $variables['messages'] = theme('status_messages');
}

/**
 * Implements template_preprocess_adminify_sidebar().
 */
function template_preprocess_adminify_sidebar(&$variables) {
  $info = _adminify_get_info_for_current_user();
  $sections = _adminify_get_sections_from_info($info);
  $variables['sections'] = array();

  foreach ($sections as $key => $section) {
    $variables['sections'][] = theme('adminify_section', array('section' => array($key => $section)));
  }
}

/**
 * Implements template_preprocess_adminify_section().
 */
function template_preprocess_adminify_section(&$variables) {
  $title = key($variables['section']);
  $section = reset($variables['section']);

  // Add title and icon to template.
  $variables['title'] = $title;
  $variables['icon'] = isset($section['icon']) ? $section['icon'] : '';

  // Build an array of pages.
  $variables['pages'] = array();
  $section_pages = $section['pages'];
  foreach ($section_pages as $key => $section_page) {
    $variables['pages'][] = l($key, $section_page['path']);
  }
}

/**
 * Implements template_preprocess_adminify_tabs().
 */
function template_preprocess_adminify_tabs(&$variables) {
  $variables['tabs'] = _adminify_get_tabs(current_path());
}
