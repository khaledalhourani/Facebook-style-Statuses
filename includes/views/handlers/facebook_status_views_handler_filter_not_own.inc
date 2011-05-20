<?php

/**
 * @file
 *   Filter to allow only statuses posted on one's own profile.
 */

/**
 * Allows only statuses posted on one's own profile.
 */
class facebook_status_views_handler_filter_not_own extends views_handler_filter_boolean_operator {
  function construct() {
    $this->definition['type'] = 'yes-no';
    $this->definition['label'] = t("Show only posts to other entities");
    $this->value_value = $this->definition['label'];
    parent::construct();
  }

  function query() {
    if ($this->value) {
      $this->ensure_my_table();
      
      $this->query->add_where_expression(0, "$this->table_alias.type <> 'user' OR $this->table_alias.sender <> $this->table_alias.recipient");
    }
  }
}
