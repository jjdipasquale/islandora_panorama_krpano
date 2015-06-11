<?php

/**
 * @file
 * Handles the display/submission of the admin settings form for this module.
 */

/**
 * Defines the admin settings form.
 *
 * @param array $form
 *   The Drupal form definition.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return array
 *   The Drupal form definition.
 */
function islandora_panorama_krpano_admin_settings_form(array $form, array &$form_state) {
  $get_default_value = function($name, $default) use($form_state) {
    return isset($form_state['values'][$name]) ? $form_state['values'][$name] : variable_get($name, $default);
  };
  $solr_enabled = module_exists('islandora_solr');
  $form = array(
    'islandora_panorama_krpano_compression' => array(
      '#type' => 'textfield',
      '#title' => t('djatoka image compression level'),
      '#description' => t('The level of compression djatoka will use when creating images (usually set at 4 or 5).'),
      '#element_validate' => array('element_validate_number'),
      '#default_value' => $get_default_value('islandora_panorama_krpano_compression', '4'),
    ),
    'islandora_panorama_krpano_overlay_opacity' => array(
      '#type' => 'textfield',
      '#title' => t('Overlay Opacity'),
      '#description' => t('The opacity of the overlay, when opening the info, fulltext and share dialogs (A number between 0 (fully transparent) and 1 (fully opaque)).'),
      '#element_validate' => array('element_validate_number'),
      '#default_value' => $get_default_value('islandora_panorama_krpano_overlay_opacity', '0.5'),
    ),
    'islandora_panorama_krpano_content_type' => array(
      '#type' => 'textfield',
      '#title' => t('The content type being displayed within the IAV.'),
      '#description' => t("This is what will be displayed in the viewer in places such as the info and share dialogs."),
      '#default_value' => $get_default_value('islandora_panorama_krpano_content_type', 'book'),
    ),
    'islandora_panorama_krpano_default_page_view' => array(
      '#type' => 'select',
      '#title' => t('Default page view'),
      '#description' => t('The number of pages to display by default'),
      '#default_value' => $get_default_value('islandora_panorama_krpano_default_page_view', 1),
      '#options' => array(
        1 => 'Single page',
        2 => 'Side by side',
        3 => 'Thumbnails',
      ),
    ),
    'islandora_panorama_krpano_mobile_full_screen' => array(
      '#type' => 'checkbox',
      '#title' => t('Force the Internet Archive Bookreader into full screen for mobile users?'),
      '#default_value' => variable_get('islandora_panorama_krpano_mobile_full_screen', FALSE),
    ),
  );
  return system_settings_form($form);
}
