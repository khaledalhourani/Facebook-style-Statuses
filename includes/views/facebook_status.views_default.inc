<?php

/**
 * @file
 *   Provides default Views for the Facebook-style Statuses module.
 */

/**
 * Implementation of hook_views_default_views().
 */
function facebook_status_views_default_views() {
  /*
   * View 'facebook_status_all'
   */
  $view = new view;
  $view->name = 'facebook_status_all';
  $view->description = 'Displays all status updates.';
  $view->tag = 'Facebook-style Statuses';
  $view->view_php = '';
  $view->base_table = 'facebook_status';
  $view->is_cacheable = FALSE;
  $view->api_version = 3;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'user_contextual_pic' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'user_contextual_pic',
      'table' => 'facebook_status',
      'field' => 'user_contextual_pic',
      'relationship' => 'none',
    ),
    'message' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'message',
      'table' => 'facebook_status',
      'field' => 'message',
      'relationship' => 'none',
    ),
    'edit' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'edit',
      'table' => 'facebook_status',
      'field' => 'edit',
      'relationship' => 'none',
    ),
    'delete' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'delete',
      'table' => 'facebook_status',
      'field' => 'delete',
      'relationship' => 'none',
    ),
    'respond' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'respond',
      'table' => 'facebook_status',
      'field' => 'respond',
      'relationship' => 'none',
    ),
    'repost' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'repost_text' => 'Share',
      'exclude' => 1,
      'id' => 'repost',
      'table' => 'facebook_status',
      'field' => 'repost',
      'relationship' => 'none',
    ),
    'created' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'themed',
      'custom_date_format' => '',
      'exclude' => 1,
      'id' => 'created',
      'table' => 'facebook_status',
      'field' => 'created',
      'relationship' => 'none',
    ),
    'nothing' => array(
      'label' => '',
      'alter' => array(
        'text' => '<div>[user_contextual_pic] [message]</div>

<div>[created] [edit] [delete] [respond] [repost]</div>',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'nothing',
      'table' => 'views',
      'field' => 'nothing',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'created' => array(
      'order' => 'DESC',
      'id' => 'created',
      'table' => 'facebook_status',
      'field' => 'created',
      'relationship' => 'none',
    ),
    'sid' => array(
      'order' => 'DESC',
      'id' => 'sid',
      'table' => 'facebook_status',
      'field' => 'sid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'message' => array(
      'operator' => '!=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'case' => 1,
      'id' => 'message',
      'table' => 'facebook_status',
      'field' => 'message',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'permission',
    'permission' => 'view all statuses',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'statuses/all');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->override_option('use_pager', 'mini');
  $handler->override_option('block_description', 'Facebook-style Statuses: All Statuses');
  $handler->override_option('block_caching', -1);
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->override_option('style_plugin', 'rss');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
  ));
  $handler->override_option('row_plugin', 'facebook_status_rss');
  $handler->override_option('path', 'statuses/all/feed');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array(
    'page_1' => 'page_1',
    'default' => 0,
    'block_1' => 0,
  ));
  $handler->override_option('sitename_title', FALSE);
  $views[$view->name] = $view;

  /*
   * View 'facebook_status_conversation'
   */
  $view = new view;
  $view->name = 'facebook_status_conversation';
  $view->description = 'Displays the conversation in status messages between two users.';
  $view->tag = 'Facebook-style Statuses';
  $view->view_php = '';
  $view->base_table = 'facebook_status';
  $view->is_cacheable = FALSE;
  $view->api_version = 3;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'picture' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'picture',
      'table' => 'users',
      'field' => 'picture',
      'relationship' => 'none',
    ),
    'name' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_user' => 1,
      'overwrite_anonymous' => 0,
      'anonymous_text' => '',
      'exclude' => 1,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'relationship' => 'none',
    ),
    'message' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'message',
      'table' => 'facebook_status',
      'field' => 'message',
      'relationship' => 'none',
    ),
    'edit' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'edit',
      'table' => 'facebook_status',
      'field' => 'edit',
      'relationship' => 'none',
    ),
    'delete' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'delete',
      'table' => 'facebook_status',
      'field' => 'delete',
      'relationship' => 'none',
    ),
    'created' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'themed',
      'custom_date_format' => '',
      'exclude' => 1,
      'id' => 'created',
      'table' => 'facebook_status',
      'field' => 'created',
      'relationship' => 'none',
    ),
    'nothing' => array(
      'label' => '',
      'alter' => array(
        'text' => '<div>[picture] [name] [message]</div>

<div>[created] [edit] [delete]</div>',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'nothing',
      'table' => 'views',
      'field' => 'nothing',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'created' => array(
      'order' => 'DESC',
      'id' => 'created',
      'table' => 'facebook_status',
      'field' => 'created',
      'relationship' => 'none',
    ),
    'sid' => array(
      'order' => 'DESC',
      'id' => 'sid',
      'table' => 'facebook_status',
      'field' => 'sid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'participant' => array(
      'default_action' => 'not found',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'breadcrumb' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'user',
      'validate_fail' => 'not found',
      'id' => 'participant',
      'table' => 'facebook_status',
      'field' => 'participant',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_fixed' => '',
      'default_argument_user' => 0,
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'book' => 0,
        'page' => 0,
        'story' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_php' => '',
    ),
    'participant_1' => array(
      'default_action' => 'not found',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'breadcrumb' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'user',
      'validate_fail' => 'not found',
      'id' => 'participant_1',
      'table' => 'facebook_status',
      'field' => 'participant',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_fixed' => '',
      'default_argument_user' => 0,
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'book' => 0,
        'page' => 0,
        'story' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'message' => array(
      'operator' => '!=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'case' => 1,
      'id' => 'message',
      'table' => 'facebook_status',
      'field' => 'message',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'permission',
    'permission' => 'view all statuses',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $views[$view->name] = $view;


   /*
   * View 'facebook_status_mystream'
   */
  $view = new view;
  $view->name = 'facebook_status_mystream';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'facebook_status';
  $view->human_name = 'facebook_status_mystream';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'user_contextual_pic' => 'user_contextual_pic',
    'message' => 'message',
    'created' => 'created',
    'edit' => 'edit',
    'delete' => 'delete',
    'comment-box' => 'comment-box',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'user_contextual_pic' => array(
      'align' => '',
      'separator' => '',
    ),
    'message' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'edit' => array(
      'align' => '',
      'separator' => '',
    ),
    'delete' => array(
      'align' => '',
      'separator' => '',
    ),
    'comment-box' => array(
      'align' => '',
      'separator' => '',
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Field: Facebook-style Statuses: Users with Pictures */
  $handler->display->display_options['fields']['user_contextual_pic']['id'] = 'user_contextual_pic';
  $handler->display->display_options['fields']['user_contextual_pic']['table'] = 'facebook_status';
  $handler->display->display_options['fields']['user_contextual_pic']['field'] = 'user_contextual_pic';
  $handler->display->display_options['fields']['user_contextual_pic']['label'] = '';
  $handler->display->display_options['fields']['user_contextual_pic']['exclude'] = TRUE;
  $handler->display->display_options['fields']['user_contextual_pic']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['user_contextual_pic']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['user_contextual_pic']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['user_contextual_pic']['alter']['external'] = 0;
  $handler->display->display_options['fields']['user_contextual_pic']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['user_contextual_pic']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['user_contextual_pic']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['user_contextual_pic']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['user_contextual_pic']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['user_contextual_pic']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['user_contextual_pic']['alter']['html'] = 0;
  $handler->display->display_options['fields']['user_contextual_pic']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['user_contextual_pic']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['user_contextual_pic']['hide_empty'] = 0;
  $handler->display->display_options['fields']['user_contextual_pic']['empty_zero'] = 0;
  /* Field: Facebook-style Statuses: Status message */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'facebook_status';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  $handler->display->display_options['fields']['message']['label'] = '';
  $handler->display->display_options['fields']['message']['exclude'] = TRUE;
  $handler->display->display_options['fields']['message']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['message']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['message']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['message']['alter']['external'] = 0;
  $handler->display->display_options['fields']['message']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['message']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['message']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['message']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['message']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['message']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['message']['alter']['html'] = 0;
  $handler->display->display_options['fields']['message']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['message']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['message']['hide_empty'] = 0;
  $handler->display->display_options['fields']['message']['empty_zero'] = 0;
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  /* Field: Facebook-style Statuses: Edit */
  $handler->display->display_options['fields']['edit']['id'] = 'edit';
  $handler->display->display_options['fields']['edit']['table'] = 'facebook_status';
  $handler->display->display_options['fields']['edit']['field'] = 'edit';
  $handler->display->display_options['fields']['edit']['label'] = '';
  $handler->display->display_options['fields']['edit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['edit']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit']['empty_zero'] = 0;
  /* Field: Facebook-style Statuses: Delete */
  $handler->display->display_options['fields']['delete']['id'] = 'delete';
  $handler->display->display_options['fields']['delete']['table'] = 'facebook_status';
  $handler->display->display_options['fields']['delete']['field'] = 'delete';
  $handler->display->display_options['fields']['delete']['label'] = '';
  $handler->display->display_options['fields']['delete']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete']['alter']['external'] = 0;
  $handler->display->display_options['fields']['delete']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['delete']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delete']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['delete']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete']['empty_zero'] = 0;
  /* Field: Facebook-style Statuses: Status comment box */
  $handler->display->display_options['fields']['comment-box']['id'] = 'comment-box';
  $handler->display->display_options['fields']['comment-box']['table'] = 'facebook_status';
  $handler->display->display_options['fields']['comment-box']['field'] = 'comment-box';
  $handler->display->display_options['fields']['comment-box']['label'] = '';
  $handler->display->display_options['fields']['comment-box']['exclude'] = TRUE;
  $handler->display->display_options['fields']['comment-box']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['comment-box']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['comment-box']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['comment-box']['alter']['external'] = 0;
  $handler->display->display_options['fields']['comment-box']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['comment-box']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['comment-box']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['comment-box']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['comment-box']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['comment-box']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['comment-box']['alter']['html'] = 0;
  $handler->display->display_options['fields']['comment-box']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['comment-box']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['comment-box']['hide_empty'] = 0;
  $handler->display->display_options['fields']['comment-box']['empty_zero'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div>[user_contextual_pic] [message]</div>

<div>[created] [edit] [delete] [comment-box]</div>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  /* Sort criterion: Facebook-style Statuses: Created time */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'facebook_status';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Facebook-style Statuses: Only own statuses */
  $handler->display->display_options['filters']['only_own']['id'] = 'only_own';
  $handler->display->display_options['filters']['only_own']['table'] = 'facebook_status';
  $handler->display->display_options['filters']['only_own']['field'] = 'only_own';
  $handler->display->display_options['filters']['only_own']['value'] = '1';
  $translatables['facebook_status_mystream'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('<div>[user_contextual_pic] [message]</div>
       <div>[created] [edit] [delete] [comment-box]</div>'),
  );
  $views[$view->name] = $view;

  
  return $views;
}
