<?php

/**
 * @file
 *   Filter to allow only statuses posted on one's own profile.
 */

/**
 * Allows only statuses posted on one's own profile.
 */
class facebook_status_views_handler_filter_own extends views_handler_filter_boolean_operator {
  function construct() {
    $this->definition['type'] = 'yes-no';
    $this->definition['label'] = t('Show only own statuses');
    if (isset($this->definition['label'])) {
      $this->value_value = $this->definition['label'];
    }
    parent::construct();
  }

  function query() {
    if ($this->value) {
      $this->ensure_my_table();
      
      $this->query->add_where_expression(0, "$this->table_alias.type = 'user' AND $this->table_alias.sender = $this->table_alias.recipient");
      
      /*
	    if (isset($definition['field'])) {
	      $this->real_field = $definition['field'];
	    }
      $this->query->add_where(0, $this->real_field);
      */
    }
  }
}
