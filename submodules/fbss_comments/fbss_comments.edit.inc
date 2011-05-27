<?php

/**
 * @file
 *   Edit and delete forms for the Facebook-style Statuses Comments module.
 */

/**
 * The edit form for status comments.
 *
 * @param $comment
 *   The comment object for the status comment being edited.
 */
function fbss_comments_edit($form, $form_state, $comment) {
  $form = array();
  $form['status-comment-edit'] = array(
    '#type' => 'textarea',
    '#rows' => 3,
    '#required' => TRUE,
    '#default_value' => $comment->comment,
  );
  $form['cid'] = array(
    '#type' => 'hidden',
    '#value' => $comment->cid,
  );
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
  );
  return $form;
}

/**
 * The submit handler for the edit form for status comments.
 */
function fbss_comments_edit_submit($form, &$form_state) {
  
  db_update('fbss_comments')
    ->fields(array(
      'comment' => $form_state['values']['status-comment-edit'],
    ))
	  ->condition('cid', $form_state['values']['cid'])
	  ->execute();
  #$c = fbssc_load($form['#cid']);
  module_invoke_all('fbss_comments_after_save', $form_state['values']['cid'], TRUE);
  if (isset($_GET['destination']) && ($_GET['destination'] != 'fbss_comments/js/refresh')) {
    $form_state['redirect'] = $_GET['destination'];
  }
  else {
    $form_state['redirect'] = '<front>';
  }
  drupal_set_message(t('Status comment has been successfully edited.'));
}

/**
 * The delete form for status comments.
 *
 * @param $comment
 *   The comment object for the status comment being deleted.
 */
function fbss_comments_delete($form, $form_state, $comment) {
  $form = array();
  $form['infotext'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t('Are you sure you want to permanently delete the status comment %comment?',
      array('%comment' => $comment->comment)) . '</p>',
  );
  $form['confirm'] = array(
    '#type' => 'submit',
    '#value' => t('Confirm'),
    '#submit' => array('fbss_comments_delete_confirm'),
  );
  $form['back'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array('fbss_comments_delete_cancel'),
  );
  $form['cid'] = array(
    '#type' => 'hidden',
    '#value' => $comment->cid,
  );
  return $form;
}

/**
 * The confirmation submit handler for the delete form for status comments.
 */
function fbss_comments_delete_confirm($form, &$form_state) {
  fbss_comments_delete_comment($form_state['values']['cid']);
  drupal_set_message(t('Status comment deleted.'));
  if (isset($_GET['destination']) && ($_GET['destination'] != 'fbss_comments/js/refresh')) {
    $form_state['redirect'] = $_GET['destination'];
  }
  else {
    $form_state['redirect'] = '<front>';
  }
}

/**
 * The cancellation submit handler for the delete form for status comments.
 */
function fbss_comments_delete_cancel($form, &$form_state) {
  drupal_set_message(t('Status comment was not deleted.'));
  if (isset($_GET['destination']) && $_GET['destination'] != 'fbss_comments/js/refresh') {
    $form_state['redirect'] = $_GET['destination'];
  }
  else {
    $form_state['redirect'] = '<front>';
  }
}
