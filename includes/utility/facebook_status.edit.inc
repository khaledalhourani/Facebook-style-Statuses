<?php

/**
 * @file
 *   Provides edit/delete status forms.
 */

/**
 * The edit status form.
 */
function facebook_status_edit($form, &$form_state, $status) {
  $context = facebook_status_determine_context($status->type);
  //$path = drupal_get_path('module', 'facebook_status') . '/resources';
  //drupal_add_js($path . '/facebook_status.js');
  //drupal_add_css($path . '/facebook_status.css');
  $intro = _facebook_status_get_edit_intro($status, $context);
  $self = '';
  if ($status->type == 'user' && $status->sender == $status->recipient) {
    $self = ' facebook-status-form-self-update';
  }
  #$form = array('#cache' => TRUE);
  $form['intro'] = array(
    '#type' => 'markup',
    '#markup' => '<span class="facebook-status-intro">' . $intro . '</span>',
    '#prefix' => '<div class="clear-block facebook-status-update facebook-status-form-type-' . $status->type . $self . '>',
    '#suffix' => '</div>',
    '#weight' => -45,
  );
  $form['fbss-status'] = array(
    '#type' => 'textarea',
    '#rows' => variable_get('facebook_status_box_rows', 2),
    '#default_value' => $status->message,
    '#resizable' => FALSE,
    '#weight' => -40,
  );
  $form['sid'] = array(
    '#type' => 'hidden',
    '#value' => $status->sid,
    '#weight' => -35,
  );
  $form['fbss-submit'] = array(
    '#type'       => 'submit',
    '#value' => t('Save'),
    '#weight' => -25,
  );
  return $form;
}

/**
 * Validate function for the status update form.
 */
function facebook_status_edit_validate($form, &$form_state) {
	return;
}

/**
 * Submit function for the status update form.
 */
function facebook_status_edit_submit($form, &$form_state) {
  $status_old = facebook_status_load($form_state['values']['sid']);
  $context = facebook_status_determine_context($status_old->type);
  $new_status = trim($form_state['values']['fbss-status']);
  $time = REQUEST_TIME;
  global $user;
  //Pretend to have set a new status if the submitted status is exactly the same as the old one.
  if ($new_status != $status_old->message) {
    db_update('facebook_status')
		  ->fields(array(
		    'message' => $new_status,
		    'created' => $time,
		  ))
		  ->condition('sid', $status_old->sid)
		  ->execute();
    //Invokes hook_facebook_status_save($status, $edit).
    $status_old->message = $new_status;
    $status_old->created = $time;
    module_invoke_all('facebook_status_save', $status_old, $context, TRUE);
  }
  $form_state['redirect'] = empty($_GET['destination']) ? array('statuses/share') : array($_GET['destination']);
  drupal_set_message(t('Status has been successfully edited.'));
  //Trigger integration. Don't call if the status is blank because usually nothing interesting is happening.
  /* i have to close this out, caus some things aren't implemented correct yet. <---
  if (module_exists('trigger') && !empty($new_status)) {
    $op = 'fbss_edited_' . $status_old->type;
    if ($status_old->type == 'user') {
      $op .= ($status_old->recipient == $status_old->sender ? '_self' : '_other');
    }
    module_invoke_all('facebook_status', $op, $status_old, $context);
  }
   <--- leave !!! */
}

/**
 * The delete status confirmation form.
 */
function _facebook_status_delete($form, &$form_state, $status) {
  $form['infotext'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t('Are you sure you want to permanently delete the status !status?', array('!status' => $status->message)) . '</p>'
  );
  $form['confirm'] = array(
    '#type' => 'submit',
    '#value' => t('Confirm'),
    '#submit' => array('_facebook_status_delete_confirm'),
  );
  $form['back'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array('_facebook_status_delete_cancel'),
  );
  $form['status-sid'] = array(
    '#type' => 'hidden',
    '#value' => $status->sid,
  );
  return $form;
}

/**
 * Deletes a status.
 */
function _facebook_status_delete_confirm($form, &$form_state) {
  $status = facebook_status_load($form_state['values']['status-sid']);
  facebook_status_delete_status($status->sid);
  drupal_set_message(t('Status deleted.'));
  
  if (isset($_GET['destination'])) {
    $form_state['redirect'] = $_GET['destination'];
  }
  else {
    $form_state['redirect'] = $status->type == 'user' ? 'user' : '<front>';
  }
}

/**
 * Cancels status deletion.
 */
function _facebook_status_delete_cancel($form, &$form_state) {
  $status = facebook_status_load($form_state['values']['status-sid']);
  if (isset($_GET['destination'])) {
    $form_state['redirect'] = $_GET['destination'];
  }
  else {
    $form_state['redirect'] = $status->type == 'user' ? 'user' : '<front>';
  }
}

/**
 * Determines what text to display above the edit status form.
 *
 * @param $status
 *   A status object.
 * @param $context
 *   A context array.
 * @return
 *   A translated string to display above the edit status form.
 */
function _facebook_status_get_edit_intro($status, $context) {
  global $user;
  $orig = nl2br(check_plain($status->message));
  if ($status->type == 'user') {
    if ($user->uid == $status->sender && $status->sender == $status->recipient) {
      $intro = '<strong>' . t('Original status: !status', array('!status' => $orig)) . ' </strong>';
    }
    elseif ($user->uid == $status->sender) {
      $intro = '<strong>' . t('Original message from you to !recipient: !status', array(
        '!recipient' => theme('username', array('account' => _facebook_status_user_load($status->recipient))),
        '!status' => $orig,
      )) . '</strong>';
    }
    elseif ($user->uid == $status->recipient) {
      $intro = '<strong>' . t('Original message from !sender to you: !status', array(
        '!sender' => theme('username', array('account' => _facebook_status_user_load($status->sender))),
        '!status' => $orig,
      )) . '</strong>';
    }
    elseif ($status->sender == $status->recipient) {
      $intro = '<strong>' . t('Original status by !creator: !status', array(
        '!creator' => theme('username', array('account' => _facebook_status_user_load($status->sender))),
        '!status' => $orig,
      )) . '</strong>';
    }
    else {
      $intro = '<strong>' . t('Original message from !sender to !recipient: !status', array(
        '!sender' => theme('username', array('account' => _facebook_status_user_load($status->sender))),
        '!recipient' => theme('username', array('account' => _facebook_status_user_load($status->recipient))),
        '!status' => $orig,
      )) . '</strong>';
    }
  }
  else {
    if ($status->sender == $user->uid) {
      $intro = '<strong>' . t('Original message from you to !recipient: !status', array(
        '!recipient' => $context['handler']->recipient_link($context['handler']->load_recipient($status->recipient)),
        '!status' => $orig,
      )) . '</strong>';
    }
    else {
      $intro = '<strong>' . t('Original message from !sender to !recipient: !status', array(
        '!sender' => theme('username', array('account' => _facebook_status_user_load($status->sender))),
        '!recipient' => $context['handler']->recipient_link($context['handler']->load_recipient($status->recipient)),
        '!status' => $orig,
      )) . '</strong>';
    }
  }
  return $intro;
}