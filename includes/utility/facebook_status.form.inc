<?php

/**
 * @file
 *   Functions related to the status update form itself.
 */

/**
 * Returns the status update form.
 *
 * @param $context
 *   One of the following:
 *   - A fully qualified context array
 *   - NULL, to have the context automatically determined
 *   - An object representing the owner of the status stream, i.e. the entity
 *     to which status messages will be posted using this form.
 * @param $type
 *   The context stream type. Only applicable if a recipient object is
 *   specified for $context, but it is required in that case.
 * @param $view
 *   The machine name of the view to display with the form. Overrides the one
 *   requested by the context.
 * @return
 *   $build Array display the status update form, or FALSE if:
 *   - The current user has no access to both the form and the associated
 *     status messages, OR
 *   - There are no relevant status messages and the current user does not
 *     have access to use the form
 */
function theme_facebook_status_form_display($variables) {
  $context = $variables['recipient'];
  $type = $variables['type'];
  $view = $variables['view'];
  global $user;
  // $context is NULL, so find everything.
  if (empty($context)) {
    $context = facebook_status_determine_context();
    $recipient = $context['handler']->find_recipient();
    $type = $context['handler']->type();
  }
  // Neither $context nor $type is NULL, so $context is really $recipient.
  elseif (!empty($type)) {
    $recipient = $context;
    $context = facebook_status_determine_context($type);
  }
  // $type is NULL and $context is not, so $context is a full context array.
  else {
    $recipient = $context['handler']->find_recipient();
    $type = $context['handler']->type();
  }
  if (empty($view) && isset($context['view'])) {
    $view = $context['view'];
  }
  
  $selectors = module_invoke_all('facebook_status_refresh_selectors', $recipient, $type) + explode("\n", isset($context['selectors']));
  $conversation = (arg(0) == 'statuses' && arg(1) == 'conversation' && $type == 'user');
  
  $build = array();
  
  if (facebook_status_user_access('add', $recipient, $type, $user)) {
    $self = '';
    if ($type == 'user' && $user->uid == $recipient->uid) {
      $self = ' facebook-status-form-self-update';
    }
    $converse = '';
    if ($conversation) {
      $converse = ' facebook-status-conversation-form';
    }
    $build['form'] = drupal_get_form('facebook_status_box', $recipient, $type);
    $build['form']['#prefix'] = '<div class="clear-block facebook-status-update facebook-status-update-main facebook-status-form-type-' . $type . $self . $converse . '">';
    $build['form']['#suffix'] = '</div>';
  }
  if ($conversation) {
    $args = explode(',', arg(2));
    $count = count($args);
    if (($count === 1 && $args[0] != $user->uid) || ($count === 2 && is_numeric($args[1])) && is_numeric($args[0])) {
      if (count($args) === 1) {
        $args[1] = $user->uid;
      }
      //$arg = implode(',', $args);
      $build['view']['#markup'] = views_embed_view('facebook_status_conversation', 'default', $args[0], $args[1]);
      $selectors[] = '.view-id-facebook_status_conversation';
    }
  }
  elseif (!empty($view)) {
    $build['view']['#markup'] = views_embed_view($view, 'default', $context['handler']->recipient_id($recipient), $type);
    $selectors[] = '.view-id-' . $view;
  }
  if (!empty($selectors)) {
    drupal_alter('facebook_status_refresh_selectors', $selectors, $recipient, $type);
    drupal_add_js(array('facebook_status' => array(
        'refreshIDs' => array_unique($selectors),
      )), array('type' => 'setting', 'scope' => JS_DEFAULT));
  }
  return drupal_render($build);
}

/**
 * The status form.
 *
 * @param $recipient
 *   An object representing the recipient of the status message.
 * @param $type
 *   The stream type.
 * @return
 *   A $form array.
 */
function facebook_status_box($form, &$form_state, $recipient, $type = 'user') {
  global $user;
  _facebook_status_use_autogrow();
  
  drupal_add_js('jQuery(document).ready(function () { 
    jQuery(".facebook-status-text").autogrow();
  });', 
  array('type' => 'inline', 'scope' => 'footer', 'weight' => 5));
  
  if (isset($form_state['facebook_status'])) {
    $type = $form_state['facebook_status']['type'];
    $context = facebook_status_determine_context($type);
    $rid = $form_state['facebook_status']['recipient'];
    $recipient = $context['handler']->load_recipient($rid);
  }
  else {
    $context = facebook_status_determine_context($type);
    $type = $context['handler']->type();
    $recipient = $context['handler']->find_recipient();
    $rid = $context['handler']->recipient_id($recipient);
  }
  $default = variable_get('facebook_status_default_text', '');
  $intro = '';
  if (arg(0) == 'statuses' && arg(1) == 'share') {
    //This page is autofocused. We don't want default text there since the user would have to manually remove it.
    $default = '';
  }
  if (isset($_GET['s']) && arg(0) == 'statuses' && arg(1) == 'share') {
    //Other modules might use "s," so only accept it on the share-status page.
    $default = $_GET['s'];
  }
  elseif (isset($_GET['share-status'])) {
    $default = $_GET['share-status'];
  }
  //@todo: Replace with a "true" re-posting system.
  if (isset($_GET['sid']) && is_numeric($_GET['sid'])) {
    $rs = facebook_status_load($_GET['sid']);
    $sender = user_load($rs->sender);
    if ($sender->uid != $user->uid && $rs->message) {
      $name = '@' . $sender->name;
      //Properly reference tags with word-break characters in them.
      if (preg_match('/.+\b.+/', $sender->name)) {
        $name = '[' . $name . ']';
      }
      $default = str_replace(array('@name', '@status'), array($name, $rs->message), variable_get('facebook_status_repost', 'Re: @name @status '));
      $intro = '';
    }
  }
  elseif (isset($_GET['rsid']) && is_numeric($_GET['rsid'])) {
    $status = facebook_status_load($_GET['rsid']);
    if ($status->sid) {
      $sender = user_load($status->sender);
      if ($sender->uid != $user->uid) {
        $name = '@' . $sender->name;
        //Properly reference tags with word-break characters in them.
        if (preg_match('/.+\b.+/', $sender->name)) {
          $name = '[' . $name . ']';
        }
        $default = $name;
      }
      $intro = t('In response to !status', array('!status' => theme('facebook_status_item', array('status' => $status, 'options' => array('links' => FALSE)))));  
    }
  }
  
  if (!empty($intro)) {
    $form['intro'] = array(
      '#type' => 'markup',
      '#markup' => '<span class="facebook-status-intro">' . $intro . '</span>',
      '#weight' => -45,
    );
  }
  $form['fbss-status'] = array(
    '#type' => 'textarea',
    '#rows' => variable_get('facebook_status_box_rows', 2),
    '#default_value' => $default,
    '#weight' => -40,
    '#attributes' => array('class' => array('facebook-status-text facebook-status-text-main')), 
    '#prefix' => '<div id="facebook-status-replace">',
    '#suffix' => '</div>',
  );
  $form['recipient'] = array(
    '#type' => 'hidden',
    '#value' => $context['handler']->recipient_id($recipient),
    '#weight' => 10,
  );
  $form['type'] = array(
    '#type' => 'hidden',
    '#value' => $type,
    '#weight' => 10,
  );
  $form['sdefault'] = array(
    '#type' => 'hidden',
    '#value' => $default,
    '#weight' => -10,
  );
  $form['fbss-submit'] = array(
    '#type' => 'submit',
    '#value' => t('Share'),
    '#submit' => array('facebook_status_box_submit'),
    '#weight' => -25,
    '#attributes' => array('class' => array('facebook-status-submit')),
    /*'#ajax' => array(
      'callback' => 'fb_callback',
      'wrapper' => 'facebook-status-replace',
      #'method' => 'replace',
    ),*/
  );
  if (arg(0) == 'statuses' && arg(1) == 'share' && !empty($_GET['destination']) && $_GET['destination'] != $_GET['q']) {
    $form['back'] = array(
      '#type' => 'markup',
      '#markup' => l(t('Back'), $_GET['destination'], array('attributes' => array('class' => 'facebook-status-back'), 'html' => 'true')),
      '#weight' => 20,
    );
  }
  return $form;
} 

/**
 * Validate function for the status update form.
 */
function facebook_status_box_validate($form, &$form_state) {
	return;
}

/**
 * Submit function for the status update form.
 */
function facebook_status_box_submit($form, &$form_state) {
  $type = $form_state['values']['type'];
  $rid = $form_state['values']['recipient'];
  $context = facebook_status_determine_context($type);
  $recipient = $context['handler']->load_recipient($rid);
  $new_status = trim($form_state['values']['fbss-status']);
  $default = $form_state['values']['sdefault'];
  // Don't save the status if it wasn't changed from the default.
  if ($new_status != $default) {
    $new_status_obj = facebook_status_save_status($recipient, $type, $new_status);
    if (isset($new_status_obj->sid)) {
      $status = new stdClass();
      $status->sid = $new_status_obj->sid;
      $status->message = $new_status;
      module_invoke('facebook_status_tags', 'facebook_status_save', $status, $context, FALSE);
    }
  }
}

/**
 * Adds the Autogrow jQuery extension.
 */
function _facebook_status_use_autogrow() {
  if (module_exists('libraries')) {
    drupal_add_js(libraries_get_path('autogrow') . '/jquery.autogrow.js');
    return;
  }
  if (file_exists('sites/all/libraries/autogrow/jquery.autogrow.js')) {
    drupal_add_js('sites/all/libraries/autogrow/jquery.autogrow.js');
  }
  elseif (file_exists('libraries/jquery.autogrow.js')) {
    drupal_add_js('libraries/jquery.autogrow.js');
  }
}