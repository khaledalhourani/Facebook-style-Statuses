<?php

/**
 * @file
 * facebook_status_comments template.
 */
?>

<div class="<?php print $classes; ?>">
  <div class="fbss-comments-userpic"><?php print $userpic; ?></div>
  <div class="fbss-comments-author"><?php print $username; ?></div>
  <div class="fbss-comments-text"><?php print $comment_text; ?></div>
  <div class="fbss-comments-closure">
    <span class="fbss-comments-created">
      <?php print $facebook_time; ?>
    </span>
    <?php if (isset($edit_link)):?>
      <span class="fbss-comments-edit-delete">
        <?php print $edit_link; ?>
      </span>
    <?php endif;?>
    <?php if (isset($delete_link)):?>
      <span class="fbss-comments-edit-delete">
        <?php print $delete_link; ?>
      </span>
    <?php endif;?>
  </div>
</div>