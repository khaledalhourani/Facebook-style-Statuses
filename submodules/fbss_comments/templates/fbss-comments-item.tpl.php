<?php

/**
 * @file
 * facebook_status_comments template.
 */
?>

<div class="<?php print $classes; ?>">
  <?php if (isset($userpic)): ?>
    <div class="fbss-comments-userpic"><?php print $userpic; ?></div>
  <?php endif; ?>
  <?php if (isset($username)): ?>
    <div class="fbss-comments-author"><?php print $username; ?></div>
  <?php endif; ?>
  <?php if (isset($comment_text)): ?>
    <div class="fbss-comments-text"><?php print $comment_text; ?></div>
  <?php endif; ?>
  <?php if (isset($facebook_time) || isset($delete_link) || isset($edit_link)): ?>
	  <div class="fbss-comments-closure">
	    <?php if (isset($facebook_time)): ?>
	      <span class="fbss-comments-created"><?php print $facebook_time; ?></span>
	    <?php endif; ?>
	    <?php if (isset($edit_link)):?>
	      <span class="fbss-comments-edit-delete"><?php print $edit_link; ?></span>
	    <?php endif; ?>
	    <?php if (isset($delete_link)):?>
	      <span class="fbss-comments-edit-delete"><?php print $delete_link; ?></span>
	    <?php endif; ?>
	  </div>
  <?php endif; ?>
</div>