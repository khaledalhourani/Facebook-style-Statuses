<?php

/**
 * @file
 *   Allow only statuses where a given user is a participant.
 */

/**
 * Argument handler to select statuses where a given user is a participant.
 */
class facebook_status_views_handler_argument_participant extends views_handler_argument {
  
  function query() {
    $this->ensure_my_table();
    #echo '<pre>'.print_r($this, true).'</pre>'; die();
    $xx[] = $this->view->args;
    $arg1 = $xx[0][0];
    $arg2 = $xx[0][1];
    $operator = '=';
    // views_plugin_query_default.inc - line 844
    $this->query->add_where_expression(0, "($this->table_alias.sender $operator $arg1 AND $this->table_alias.recipient $operator $arg2) OR ($this->table_alias.sender $operator $arg2 AND $this->table_alias.recipient $operator $arg1)", array());
  }

}
