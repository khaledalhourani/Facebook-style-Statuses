<?php

/**
 * @file
 *   Allows sending a status message to every user.
 */

/**
 * Admin form callback.
 */
function facebook_status_announce_admin($form, &$form_state) {
  $form = array();
  $form['info'] = array(
    '#markup' => t('Warning: this can be very slow on sites with lots of users.'),
  );
  $form['from'] = array(
    '#type' => 'textfield',
    '#title' => t('Sender'),
    '#description' => t('The username of the user from whom the messages will be sent.'),
    '#autocomplete_path' => 'user/autocomplete',
    '#required' => TRUE,
  );
  $form['message'] = array(
    '#type' => 'textarea',
    '#title' => t('Message'),
    '#required' => TRUE,
  );
  /*
   // Unfortunately we have to use the default format because we don't have any
   // way to keep track of which format to use at display time.
   $formats = filter_formats();
   $f = array();
   foreach ($formats as $format) {
   $f[$format->format] = filter_xss($format->name);
   }
   $form['format'] = filter_form();
   */
  $form['send'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
  );
  return $form;
}

/**
 * Admin form submit callback.
 */
function facebook_status_announce_admin_submit($form, &$form_state) {
  $v = $form_state['values'];
  
  $from = _facebook_status_user_load_by_name($v['from']);
  
  if (!$from->uid) {
    $from = FALSE;
  }
  if (!isset($v['format'])) {
    $v['format'] = NULL;
  }

  $count = db_query("SELECT COUNT(DISTINCT uid) FROM {users} WHERE status = :status", array(':status' => 1))->fetchField();
  $batch = array(
    'operations' => array(
      array('facebook_status_announce_generate_status', array($v['message'], $from, $count, $v['format'])),
    ),
    'finished' => 'facebook_status_announce_batch_finished',
    'title' => t('Sending message to all users'),
    'file' => drupal_get_path('module', 'facebook_status') . '/includes/utility/facebook_status.announce.inc',
  );
  
  batch_set($batch);
}

/**
 * Sends the status message to users.
 *
 * @param $message
 *   The message that will be sent.
 * @param $from
 *   The $user object of the status poster.
 * @param $count
 *   The number of active users.
 * @param $format
 *   The ID of the input format to use for the message.
 */
function facebook_status_announce_generate_status($message, $from, $count, $format, &$context) {
  // because of userid = 1, admin doesn't send himself.
  $count = $count - 1;
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_userid'] = 1;
    $context['sandbox']['max'] = $count;
  }
  $limit = $count;
  
  $result = db_select('users', 'uid')
    ->fields('uid')
    ->condition('uid', $context['sandbox']['current_userid'], '>')
    ->condition('status', 1)
    ->orderBy('uid')
    ->range(0, $limit)
    ->execute();
  
  foreach ($result as $row) {

    $to = user_load($row->uid);
    //$context['message'] = check_plain($to->name);
    
    $context['message'] = t('Sending message to @user (@current of @total)',
    array('@user' => $to->name, '@current' => $context['sandbox']['progress'], '@total' => $count));
    
    facebook_status_save_status($to, 'user', $message, $from);
    
    $context['results'][] = check_plain($to->name);
    
    $context['sandbox']['current_userid'] = $to->uid;
    
	  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
	    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
	  }
	  $context['sandbox']['progress']++;
    
  }
  
}

/**
 * Batch finished callback.
 */
function facebook_status_announce_batch_finished($success, $results, $operations) {
  
  if ($success) {
    $count = count($results);
    if ($count < 50) {
      drupal_set_message(format_plural(count($results),
        'Sent message to 1 user: !list',
        'Sent message to @count users: !list',
        array('!list' => theme('item_list', array('items' => $results)))
      ));
    }
    else {
      drupal_set_message(t('Sent message to @count users.', array('@count' => $count)));
    }
  }
  else {
    $error_operation = reset($operations);
    drupal_set_message(t('An error occurred while processing %error_operation with arguments: @arguments',
      array(
      '%error_operation' => $error_operation[0],
      '@arguments' => print_r($error_operation[1], TRUE),
    )
    ));
  }
}