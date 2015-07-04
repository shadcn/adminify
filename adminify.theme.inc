<?php

/**
 * @file
 * Theme and preprocess functions for adminify module.
 */

/**
 * Implements theme_adminify_links().
 */
function theme_adminify_links(&$variables) {
  $output = '';
  $default_options = array('html' => TRUE);
  $links = $variables['links'];

  // Render each link as li.
  // The wrapping ul element is left to the theme.
  foreach ($links as $link_name => $link) {
    $icon = !empty($link['icon']) ? '<i class="fa fa-' . $link['icon'] . '"></i>&nbsp; ' : '';
    $options = !empty($link['options']) ? array_merge($link['options'], $default_options) : $default_options;

    $dropdown_menu_output = '';
    if (!empty($link['dropdown'])) {
      $options['attributes']['class'][] = 'dropdown-toggle';
      $options['attributes']['data-toggle'] = 'dropdown';

      // Render the dropdown menu.
      $dropdown_menu_output = '<ul class="dropdown-menu">';
      $dropdown_menu_links = $link['dropdown'];
      foreach ($dropdown_menu_links as $dropdown_menu_link_name => $dropdown_menu_link) {
        $dropdown_menu_link_icon = !empty($dropdown_menu_link['icon']) ? '<i class="fa fa-' . $dropdown_menu_link['icon'] . '"></i>&nbsp; ' : '';
        $dropdown_menu_link_output = l($dropdown_menu_link_icon . $dropdown_menu_link['title'], $dropdown_menu_link['path'], array('html' => TRUE));
        $dropdown_menu_output .= '<li class="link-' . drupal_html_class($dropdown_menu_link_name) . '">' . $dropdown_menu_link_output . '</li>';
      }
      $dropdown_menu_output .= '</ul>';
    }

    // Add active trail.
    if (!empty($options['in_active_trail']) && $options['in_active_trail']) {
      $options['attributes']['class'][] = 'active';
    }

    // Render the link.
    $link_output = l($icon . $link['title'], $link['path'], $options);

    $output .= '<li class="link-' . drupal_html_class($link_name) . '">' . $link_output . $dropdown_menu_output . '</li>';
  }

  return $output;
}
