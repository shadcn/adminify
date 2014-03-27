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
  $info = _adminify_get_info_for_current_user();

  // Add the page title.
  $variables['title'] = drupal_get_title();

  // Add messages to adminify template.
  $variables['messages'] = theme('status_messages');

  // Add the logged in user as adminify_user.
  $variables['adminify_user'] = $user;
  $variables['adminify_username'] = theme('username', array('account' => $user));

  // Add sidebar menu.
  $variables['sidebar_menu'] = '';
  $sections = _adminify_get_sections_from_info($info);
  if (count($sections)) {
    $variables['sidebar_menu'] = theme('adminify_sidebar_menu', array('links' => $sections));
  }

  // Add user menu.
  $variables['user_menu'] = '';
  $links = _adminify_get_links_from_info($info);
  if (count($links)) {
    $variables['user_menu'] = theme('adminify_user_menu', array('links' => $links));
  }

  // Add tabs.
  $tabs = _adminify_get_tabs(current_path());
  $variables['tabs'] = theme('adminify_tabs', array('tabs' => $tabs));
  // $action_links = _adminify_get_page_action_links();
  // $variables['action_links'] = theme('adminify_action_links', array('links' => $action_links));

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
 * Implements template_preprocess_adminify_sidebar_menu().
 */
function template_preprocess_adminify_sidebar_menu(&$variables) {
  $links = $variables['links'];
  $sections = array();

  // Render each section as an adminify section.
  foreach ($links as $key => $link) {
    $sections[] = theme('adminify_section', array('section' => array($key => $link)));
  }

  $variables['sections'] = $sections;
}

/**
 * Implements template_preprocess_adminify_section().
 */
function template_preprocess_adminify_section(&$variables) {
  $title = key($variables['section']);
  $section = reset($variables['section']);

  // Add title to template.
  $variables['title'] = $title;

  // Create a section id from $title.
  $variables['section_id'] = $section_id = drupal_html_id($title);

  // Link for section.
  $link_title = '';
  $link_attributes = array();
  if (isset($section['icon'])) {
    $link_title .= '<i class="fa fa-' . $section['icon'] . '"></i>';
  }
  $link_title .= $title;

  // Build an array of pages.
  $variables['pages'] = array();
  if (isset($section['pages'])) {
    $section_pages = $section['pages'];
    foreach ($section_pages as $key => $section_page) {
      $variables['pages'][] = l($key, $section_page['path']);
    }

    // Add icon to link.
    $link_title .= '<i class="arrow fa fa-angle-right pull-right"></i>';
    // $link_attributes['data-toggle'] = 'dropdown';
    $link_attributes['data-toggle'] = 'collapse';
    $link_attributes['data-target'] = '#'. $section_id;
  }

  // Add link to template.
  $variables['link'] = l($link_title, current_path(), array(
    'absolute' => TRUE,
    'fragment' => FALSE,
    'html' => TRUE,
    'attributes' => $link_attributes,
  ));
}

/**
 * Implements template_preprocess_adminify_user_menu().
 */
function template_preprocess_adminify_user_menu(&$variables) {
  $links = array();

  // Format links and add to template.
  foreach ($variables['links'] as $key => $link) {
    $link_title = '';

    // Add icon to title.
    if (isset($link['icon'])) {
      $link_title .= '<i class="fa fa-' . $link['icon'] . '"></i>';
    }

    // Use key as title.
    $link_title .= $key;

    $links[] = l($link_title, $link['path'], array('html' => TRUE));
  }

  $variables['links'] = $links;
}

/**
 * Implements template_preprocess_adminify_tabs().
 */
function template_preprocess_adminify_tabs(&$variables) {
  $tabs = array();

  // Render each tab as a link.
  foreach ($variables['tabs'] as $title => $tab) {
    $tabs[] = l($title, $tab['path']);
  }

  $variables['tabs'] = $tabs;
}
