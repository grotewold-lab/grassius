<?php

/**
 * @file
 *
 * These api functions are deprecated, if your site is currently using them
 * please update your code with the newer tripal_chado functions.
 */

/**
 * @defgroup tripal_chado_DEPRECATED_api
 * @ingroup tripal_chado_api
 * @{
 * Deprecated legacy api code.
 * @}
 */

/**
 * Publishes content in Chado as a new TripalEntity entity.
 *
 * @param $values
 *   A key/value associative array that supports the following keys:
 *   - bundle_name:  The name of the the TripalBundle (e.g. bio_data-12345).
 * @param $job_id
 *   (Optional) The numeric job ID as provided by the Tripal jobs system. There
 *   is no need to specify this argument if this function is being called
 *   outside of the jobs systems.
 *
 * @return boolean
 *   TRUE if all of the records of the given bundle type were published, and
 *   FALSE if a failure occured.
 *
 * @ingroup tripal_chado_DEPRECATED_api
 */
function tripal_chado_publish_records($values, $job_id = NULL) {
  return chado_publish_records($values, $job_id = NULL);
}

/**
 * Returns an array of tokens based on Tripal Entity Fields.
 *
 * @param $base_table
 *    The name of a base table in Chado.
 *
 * @return
 *    An array of tokens where the key is the machine_name of the token.
 *
 * @ingroup tripal_chado_DEPRECATED_api
 */
function tripal_get_chado_tokens($base_table) {
  return chado_get_tokens($base_table);
}

/**
 * Replace all Chado Tokens in a given string.
 *
 * NOTE: If there is no value for a token then the token is removed.
 *
 * @param string $string
 *   The string containing tokens.
 * @param $record
 *   A Chado record as generated by chado_generate_var()
 *
 * @return
 *   The string will all tokens replaced with values.
 *
 * @ingroup tripal_chado_DEPRECATED_api
 */
function tripal_replace_chado_tokens($string, $record) {
  return chado_replace_tokens($string, $record);
}

/**
 * Migrate Tripal content types
 *
 * Migrate specified Tripal content type and publish all its content. The
 * content type will be created if it does not already exist.
 *
 * @param $type
 *   A type array specifying the vocabular, accession, term_name, and chado
 *   data_table e.g.
 *     $type = array(
 *       'vocabulary' => 'OBI',
 *       'accession' => '0100026',
 *       'term_name' => 'organism',
 *       'storage_args' => array (
 *         'data_table' => $table
 *       )
 *     )
 *
 * @ingroup tripal_chado_DEPRECATED_api
 */
function tripal_chado_migrate_tripal_content_type($type = []) {
  return chado_migrate_tripal_content_type($type = []);
}


/**
 * Add a materialized view to the chado database to help speed data access. This
 * function supports the older style where postgres column specifications
 * are provided using the $mv_table, $mv_specs and $indexed variables. It also
 * supports the newer preferred method where the materialized view is described
 * using the Drupal Schema API array.
 *
 * @param $name
 *   The name of the materialized view.
 * @param $modulename
 *   The name of the module submitting the materialized view
 *   (e.g. 'tripal_library').
 * @param $mv_schema
 *   If using the newer Schema API array to define the materialized view then
 *   this variable should contain the array or a string representation of the
 *   array.
 * @param $query
 *   The SQL query that loads the materialized view with data.
 * @param $comment
 *   A string containing a description of the materialized view.
 * @param $redirect
 *   Optional (default: TRUE). By default this function redirects back to
 *   admin pages. However, when called by Drush we don't want to redirect. This
 *   parameter allows this to be used as a true API function.
 *
 * @ingroup tripal_chado_DEPRECATED_api
 */
function tripal_add_mview($name, $modulename, $mv_schema, $query, $comment = NULL, $redirect = TRUE) {
  return chado_add_mview($name, $modulename, $mv_schema, $query, $comment, $redirect);
}

/**
 * Edits a materialized view to the chado database to help speed data access.
 * This function supports the older style where postgres column specifications
 * are provided using the $mv_table, $mv_specs and $indexed variables. It also
 * supports the newer preferred method where the materialized view is described
 * using the Drupal Schema API array.
 *
 * @param $mview_id
 *   The mview_id of the materialized view to edit.
 * @param $name
 *   The name of the materialized view.
 * @param $modulename
 *   The name of the module submitting the materialized view
 *   (e.g. 'tripal_library').
 * @param $mv_table
 *   The name of the table to add to chado. This is the table that can be
 *   queried.
 * @param $mv_specs
 *   The table definition.
 * @param $indexed
 *   The columns that are to be indexed.
 * @param $query
 *   The SQL query that loads the materialized view with data.
 * @param $special_index
 *   currently not used.
 * @param $comment
 *   A string containing a description of the materialized view.
 * @param $mv_schema
 *   If using the newer Schema API array to define the materialized view then
 *   this variable should contain the array.
 *
 * @ingroup tripal_chado_DEPRECATED_api
 */
function tripal_edit_mview($mview_id, $name, $modulename, $mv_table, $mv_specs,
                           $indexed, $query, $special_index, $comment = NULL, $mv_schema = NULL) {
  return chado_edit_mview($mview_id, $name, $modulename, $mv_table, $mv_specs,
    $indexed, $query, $special_index, $comment = NULL, $mv_schema = NULL);
}

/**
 * Retrieve the materialized view_id given the name.
 *
 * @param $view_name
 *   The name of the materialized view.
 *
 * @return
 *   The unique identifier for the given view.
 *
 * @ingroup tripal_chado_DEPRECATED_api
 */
function tripal_get_mview_id($view_name) {
  return chado_get_mview_id($view_name);
}

/**
 * Populates the specified Materialized View.
 *
 * @param $mview_id
 *   The unique ID of the materialized view for the action to be performed on.
 *
 * @ingroup tripal_chado_DEPRECATED_api
 */
function tripal_refresh_mview($mview_id) {
  return chado_refresh_mview($mview_id);
}

/**
 * Retrieves the list of materialized view IDs and their names.
 *
 * @return
 *   An array of objects with the following properties:  mview_id, name.
 *
 * @ingroup tripal_chado_DEPRECATED_api
 *
 */
function tripal_get_mviews() {
  return chado_get_mviews();
}

/**
 * Does the specified action for the specified Materialized View.
 *
 * @param $op
 *   The action to be taken. One of update or delete.
 * @param $mview_id
 *   The unique ID of the materialized view for the action to be performed on.
 *
 * @ingroup tripal_chado_DEPRECATED_api
 */
function tripal_delete_mview($mview_id) {
  return chado_delete_mview($mview_id);
}

/**
 * Update a Materialized View.
 *
 * @param $mview_id
 *   The unique identifier for the materialized view to be updated.
 *
 * @return
 *   True if successful, FALSE otherwise.
 *
 * @ingroup tripal_chado_DEPRECATED_api
 */
function tripal_populate_mview($mview_id) {
  return chado_populate_mview($mview_id);
}

/**
 * Alter the name of the schema housing Chado and/or Drupal.
 *
 * This example implementation shows a solution for the case where your chado
 * database was well established in the "public" schema and you added Drupal
 * later in a "drupal" schema. Please note that this has not been tested and
 * while we can ensure that Tripal will work as expected, we have no control
 * over whether Drupal is compatible with not being in the public schema. That's
 * why we recommened the organization we have (ie: Chado in a "chado" schema and
 * Drupal in the "public schema).
 *
 * @param $schema_name
 *   The current name of the schema as known by Tripal. This is likely the
 *   default set in tripal_get_schema_name() but in the case of multiple alter
 *   hooks, it might be different.
 * @param $context
 *   This is an array of items to provide context.
 *     - schema: this is the schema that was passed to tripal_get_schema_name()
 *       and will be either "chado" or "drupal". This should be used to
 *       determine you are changing the name of the correct schema.
 *
 * @ingroup tripal_chado_DEPRECATED_api
 */
function hook_tripal_get_schema_name_alter($schema_name, $context) {
  return hook_chado_get_schema_name_alter($schema_name, $context);
}

/**
 * Retrieve the name of the PostgreSQL schema housing Chado or Drupal.
 *
 * @param $schema
 *   Wehter you want the schema name for 'chado' or 'drupal'. Chado is the
 *   default.
 *
 * @return
 *   The name of the PostgreSQL schema housing the $schema specified.
 *
 * @ingroup tripal_chado_DEPRECATED_api
 */
function tripal_get_schema_name($schema = 'chado') {
  return chado_get_schema_name($schema);
}


/**
 * Adds a new Chado table to the semantic web support for Chado.
 *
 * Newly added tables (i.e. custom tables) need to be integrated into the
 * semantic web infrastructure.  After a new table is created and added to
 * the Chado schema, this function should be called to indicate that the
 * table should be included in the semantic web. No associations are made for
 * the columns. The associations should be added using the
 * tripal_associate_chado_semweb_term() function.
 *
 * If the table has already been added previously then this function does
 * nothing. It will not overwrite existing assocations.
 *
 * Temporary tables (e.g. Tripal tables that begin with 'tripal_' and end with
 * '_temp', are not supported.
 *
 * @param $chado_table
 *   The name of the Chado table.
 *
 * @ingroup tripal_chado_DEPRECATED_api
 */
function tripal_add_chado_semweb_table($chado_table) {
  return chado_add_semweb_table($chado_table);
}

/**
 * Associates a controlled vocabulary term with a field in a Chado table.
 *
 * For sharing of data via the semantic web we need to associate a
 * term from a controlled vocabulary with every column of every table in Chado.
 *
 * Temporary tables (e.g. Tripal tables that begin with 'tripal_' and end with
 * '_temp', are not supported.
 *
 * @param $chado_table
 *   The name of the table in Chado. This argument is optional. If left empty
 *   or set to NULL then all fields in all Chado tables with that have the
 *   $column_name will be associated with the provided $term.
 * @param $chado_column
 *   The column name in the Chado table to which the term should be associated.
 * @param $term
 *   A cvterm object as returned by chado_generate_var().
 * @param $update
 *   Set to TRUE if the association should be updated to use the new term
 *   if a term is already associated with the table and column.  Default is
 *   FALSE.  If not TRUE and a term is already associated, then no change
 *   occurs.
 *
 * @return boolean
 *   Returns TRUE if the association was made successfully and FALSE otherwise.
 *
 * @ingroup tripal_chado_DEPRECATED_api
 */
function tripal_associate_chado_semweb_term($chado_table, $chado_column, $term,
                                            $update = FALSE) {
  return chado_associate_semweb_term($chado_table, $chado_column, $term, $update);
}


/**
 * Retrieves the term that maps to the given Chado table and field.
 *
 * @param $chado_table
 *   The name of the Chado table.
 * @param $chado_column
 *   The name of the Chado field.
 * @param $options
 *   An associative array of one or more of the following keys:
 *     -return_object:  Set to TRUE to return the cvterm object rather than
 *      the string version of the term.
 *
 * @return
 *   Returns a string-based representation of the term (e.g. SO:0000704). If
 *   the 'return_object' options is provided then a cvterm object is returned.
 *   returns NULL if no term is mapped to the table and column.
 *
 * @ingroup tripal_chado_DEPRECATED_api
 */
function tripal_get_chado_semweb_term($chado_table, $chado_column, $options = []) {
  return chado_get_semweb_term($chado_table, $chado_column, $options);
}

/**
 * Formats a controlled vocabulary term from Chado for use with Tripal.
 *
 * @param $cvterm
 *   A cvterm object.
 *
 * @return
 *   The semantic web name for the term.
 *
 * @ingroup tripal_chado_DEPRECATED_api
 */
function tripal_format_chado_semweb_term($cvterm) {
  return chado_format_semweb_term($cvterm);
}

/**
 * Retreive the column name in a Chado table that matches a given term.
 *
 * @param $chado_table
 *   The name of the Chado table.
 * @param $term
 *   The term. This can be a term name or a unique identifer of the form
 *   {db}:{accession} or of the form {db}__{term_name}.
 *
 * @return
 *   The name of the Chado column that matches the given term or FALSE if the
 *   term is not mapped to the Chado table.
 *
 * @ingroup tripal_chado_DEPRECATED_api
 */
function tripal_get_chado_semweb_column($chado_table, $term) {
  return chado_get_semweb_column($chado_table, $term);
}
