<?php

/**
 * @file
 *   Allow only statuses where a given user is a participant.
 */

/**
 * Argument handler to select statuses where a given user is a participant.
 */
class facebook_status_views_handler_argument_participant extends views_handler_argument {
  /*
  function query() {
    $argument = $this->argument;
    $this->query->add_where(0, "($this->table.sender = :d OR $this->table.recipient = :d) AND $this->table.type = 'user'", array(':d' => $argument));
  }
  
  function query() {
    $this->ensure_my_table();
    if (isset($definition['field'])) {
      $this->real_field = $definition['field'];
    }
    $placeholder = $this->definition['numeric'];
    $this->query->add_where(0, "$this->table_alias.$this->real_field = $placeholder", $this->argument);
  }*/
  
  
  
  
  
}
