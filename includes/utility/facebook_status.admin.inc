<?php

/**
 * @file
 *   Handles admin pages for the Facebook-style Statuses module.
 */

/**
 * Settings form.
 */
function facebook_status_admin($form, &$form_state) {
  global $user;
  $formats = filter_formats($user);
  $options = array('none' => t('None (HTML escaped)'));
  foreach ($formats as $format) {
    $options[$format->format] = check_plain($format->name);
  }
  $form['facebook_status_filter'] = array(
    '#type' => 'select',
    '#title' => t('Input filter'),
    '#description' => '<strong>' . t('This input filter will run on all your statuses AND ACCESS TO IT IS NOT CHECKED, so make sure it is secure.') . '</strong>',
    '#default_value' => variable_get('facebook_status_filter', 'none'),
    '#options' => $options,
    '#weight' => -30,
  );
  $form['facebook_status_repost'] = array(
    '#type' => 'textfield',
    '#title' => t('Re-post format'),
    '#description' => t('The format of the default message when users click a link to re-post a status.') . ' ' .
      t("@name will be replaced with the poster's name and @status will be replaced with the status text."),
    '#default_value' => variable_get('facebook_status_repost', 'Re: @name @status '),
    '#weight' => -20,
  );
  $views = views_get_all_views();
  $list = array('' => t('None'));
  foreach ($views as $name => $view) {
    if (!isset($view->disabled) || $view->disabled != TRUE) {
      $list[$name] = $name;
    }
  }
  $form['facebook_status_share_view'] = array(
    '#type' => 'select',
    '#title' => t('Show a view under the status update form at the "Share status" page at /statuses/share'),
    '#description' => t('The default facebook_status_stream view is recommended.'),
    '#default_value' => variable_get('facebook_status_share_view', $list['facebook_status_mystream']),
    '#options' => $list,
    '#weight' => -10,
  );
  return system_settings_form($form);
}

/**
 * Validate function for the settings form.
 */
function facebook_status_admin_validate($form, &$form_state) {
}

/**
 * Advanced settings form.
 */
function facebook_status_admin_advanced($form, &$form_state) {
  $form['facebook_status_box_rows'] = array(
    '#type' => 'textfield',
    '#title' => t('Status update box rows'),
    '#description' => t('The default number of lines for the status update box.'),
    '#default_value' => variable_get('facebook_status_box_rows', 2),
    '#size' => 3,
    '#maxlength' => 3,
    '#required' => TRUE,
    '#weight' => -80,
  );
  $form['facebook_status_nl2br'] = array(
    '#type' => 'checkbox',
    '#title' => t('Convert line breaks'),
    '#description' => t('By default, line breaks in the status update form are ignored.') . ' ' .
      t('If you use an input filter to fix that, the status text will appear on a different line than the username and other information.') . ' ' .
      t('Enabling this setting allows line breaks to appear without the side-effect of the input filter.'),
    '#default_value' => variable_get('facebook_status_nl2br', 0),
    '#weight' => -60,
  );
  $form['facebook_status_profile'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the status stream on the default user profiles'),
    '#description' => t('If enabled, the status update form and view will appear on default user profiles.') . ' ' .
      t('This setting should only matter if you have not overridden the default user profile.'),
    '#default_value' => variable_get('facebook_status_profile', 1),
    '#weight' => -40,
  );
  $form['facebook_status_default_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Default text'),
    '#description' => t('The text that appears by default in the status update box.') . ' ' .
      t('This will be automatically cleared when a user clicks in (or focuses on) the status update box.'),
    '#default_value' => variable_get('facebook_status_default_text', ''),
    '#weight' => -30,
  );
  $form['facebook_status_reply_type'] = array(
    '#type' => 'select',
    '#title' => t('Reply method'),
    '#default_value' => variable_get('facebook_status_reply_type', 'at'),
    '#options' => array(
      'at' => t('Reply by @mention'),
      'convo' => t('Reply in conversation view'),
    ),
    '#weight' => -20,
  );
  return system_settings_form($form);
}

/**
 * Validate function for the advanced settings form.
 */
function facebook_status_admin_advanced_validate($form, &$form_state) {
  $size = $form_state['values']['facebook_status_box_rows'];
  if (!is_numeric($size) || $size < 1 || $size != round($size)) {
    form_set_error('facebook_status_box_rows', t('The number of rows of the status update box must be a positive integer.'));
  }
}

/**
 * The draggable-table stream context configuration form.
 */
function facebook_status_admin_contexts($form, &$form_state) {
  $data = facebook_status_all_contexts();
  
  $form = array();
  $form['components'] = array();
  $form['components']['#tree'] = TRUE;
  $count = count($data);
  $views = views_get_all_views();
  $options = array('' => t('None'));
  foreach ($views as $name => $view) {
    //if (empty($view->disabled)) {
    if (!isset($view->disabled) || $view->disabled != TRUE) {
      $options[$name] = $name;
    }
  }
  foreach ($data as $type => $values) {
    $form['components'][$type]['title'] = array(
      //'#prefix' => '<div title="' . (isset($values['description']) ? $values['description'] : '') . '">',
      //'#value' => $values['title'],
      '#markup' => $values['title'],
      //'#suffix' => '</div>',
    );
    $form['components'][$type]['view'] = array(
      '#type' => 'select',
      '#default_value' => isset($values['view']) ? $values['view'] : '',
      '#options' => $options,
    );
    $form['components'][$type]['selectors'] = array(
      '#type' => 'textarea',
      '#rows' => 2,
      '#default_value' => isset($values['selectors']) ? $values['selectors'] : '',
    );
    $form['components'][$type]['weight'] = array(
      '#type' => 'weight',
      '#delta' => $count,
      '#default_value' => isset($values['weight']) ? $values['weight'] : 0,
    );
    $form['components'][$type]['type'] = array(
      '#type' => 'hidden',
      '#value' => $type,
    );
    $form['components'][$type]['already_saved'] = array(
      '#type' => 'hidden',
      '#value' => isset($values['in_db']) ? $values['in_db'] : FALSE,
    );
  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

/**
 * The submit callback for the stream context configuration form.
 */
function facebook_status_admin_contexts_submit($form, &$form_state) {
  foreach ($form_state['values']['components'] as $item) {
    $record = array(
      'type' => $item['type'],
      'weight' => intval($item['weight']),
      'view' => $item['view'],
      'selectors' => $item['selectors'],
    );
    if ($item['already_saved']) {
      drupal_write_record('facebook_status_contexts', $record, 'type');
    }
    else {
      drupal_write_record('facebook_status_contexts', $record);
    }
  }
}

/**
 * Themes the stream context configuration form in a draggable table.
 */
function theme_facebook_status_admin_contexts($variables) {
  $form = $variables['form'];
  drupal_add_tabledrag('facebook-status-admin-contexts-table', 'order', 'sibling', 'weight-group');
  $header = array(t('Title'), t('View'), t('Refreshable DOM selectors'), t('Weight'), '', '');
  $rows = array();
  foreach (element_children($form['components']) as $key) {
    $element = &$form['components'][$key];
    $row = array();
    $row[] = drupal_render($element['title'], array('#attributes' => array('class' => 'title-group')));
    $row[] = drupal_render($element['view'], array('#attributes' => array('class' => 'view-group')));
    $row[] = drupal_render($element['selectors'], array('#attributes' => array('class' => 'selectors-group')));
    $row[] = drupal_render($element['weight'], array('#attributes' => array('class' => 'weight-group')));
    $row[] = drupal_render($element['type'], array('#attributes' => array('class' => 'type')));
    $row[] = drupal_render($element['already_saved'], array('#attributes' => array('class' => 'already-saved')));
    $rows[] = array(
      'data' => $row,
      'class' => array('class' => 'draggable'),
    );
  }
  $output = '<p>' .
    t('In the "Refreshable DOM selectors" column, enter CSS selectors that specify sections of the page that should be automatically refreshed via AJAX when a status of that type is submitted.') . ' ' .
    t('For example, to automatically update all &lt;div&gt; elements with class "myclass", enter "div.myclass" in the box (without the quotes).') . ' ' .
    t('Do not include selectors that include the status update form.') . ' ' .
    t('Enter each selector on a separate line.') .
    '</p><p>' .
    t('Also note that the view assigned to the "User profiles" context does not affect the view shown on conversation pages.') .
    '</p>';
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'facebook-status-admin-contexts-table')));
  $output .= drupal_render_children($form);
  return $output;
}
