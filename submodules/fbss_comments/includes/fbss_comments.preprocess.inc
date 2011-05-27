<?php

/**
 * @file
 * Preprocess functions for the facebook_status_comments template.
 */
function template_preprocess_fbss_comments_item(&$variables) {
	$comment = $variables['comment'];
  if (!fbss_comments_can_view($comment)) {
    return FALSE;
  }
  array_unshift($variables['classes'], 'fbss-comments-comment');
  $variables['classes_array'] += $variables['classes'];
  
  // make an object that we pass through drupal_alter (hook_fbss_comments_render_alter),
  // before we pass variables to template.
  $comm = new stdClass;
  $userobj = _facebook_status_user_load($comment->uid);
  $comm->userpic = theme('user_picture', array('account' => $userobj));
  $comm->username = theme('username', array('account' => $userobj));
  $comm->facebook_time = theme('facebook_status_time', array('time' => $comment->created));
  
  // run filter if one is set in admin
  $comment_text = _facebook_status_run_filter($comment->comment);
  $comm->comment_text = nl2br($comment_text);
  
  $q = $_GET['q'];
  if ($variables['destination']) {
    $q = $variables['destination'];
  }
  elseif (strpos($q, 'fbss_comments/js/refresh') !== FALSE) {
    $q = '<front>';
  }
  if (fbss_comments_can_edit($comment)) {
      $comm->edit_link = l(t('Edit'), 'statuses/comment/' . $comment->cid . '/edit', array('query' => array('destination' => $q)));
  }
  if (fbss_comments_can_delete($comment)) {
      $comm->delete_link = l(t('Delete'), 'statuses/comment/' . $comment->cid . '/delete', array('query' => array('destination' => $q)));
  }
  // Invokes hook_fbss_comments_render_alter(&$output, $comment).
  drupal_alter('fbss_comments_render', $comm, $comment);
  // grab our variables back from $comm object into variables array
  $variables += get_object_vars($comm);
}