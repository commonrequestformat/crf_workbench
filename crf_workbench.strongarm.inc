<?php
/**
 * @file
 * crf_workbench.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function crf_workbench_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access';
  $strongarm->value = 'taxonomy';
  $export['workbench_access'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_allow_multiple';
  $strongarm->value = 0;
  $export['workbench_access_allow_multiple'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_auto_assign';
  $strongarm->value = 1;
  $export['workbench_access_auto_assign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_custom_form';
  $strongarm->value = 1;
  $export['workbench_access_custom_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_label';
  $strongarm->value = 'Section';
  $export['workbench_access_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_menu';
  $strongarm->value = array(
    'devel' => 0,
    'main-menu' => 0,
    'management' => 0,
    'navigation' => 0,
    'user-menu' => 0,
  );
  $export['workbench_access_menu'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_assessment';
  $strongarm->value = 0;
  $export['workbench_access_node_type_assessment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_assessments_batch';
  $strongarm->value = 1;
  $export['workbench_access_node_type_assessments_batch'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_cluster_objectives';
  $strongarm->value = 0;
  $export['workbench_access_node_type_cluster_objectives'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_contact';
  $strongarm->value = 1;
  $export['workbench_access_node_type_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_contacts_upload';
  $strongarm->value = 0;
  $export['workbench_access_node_type_contacts_upload'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_crf_request';
  $strongarm->value = 0;
  $export['workbench_access_node_type_crf_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_hr_sitrep';
  $strongarm->value = 1;
  $export['workbench_access_node_type_hr_sitrep'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_indicator_data';
  $strongarm->value = 0;
  $export['workbench_access_node_type_indicator_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_indicator_data_batch';
  $strongarm->value = 1;
  $export['workbench_access_node_type_indicator_data_batch'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_indicator_definition';
  $strongarm->value = 0;
  $export['workbench_access_node_type_indicator_definition'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_link';
  $strongarm->value = 0;
  $export['workbench_access_node_type_link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_page';
  $strongarm->value = 0;
  $export['workbench_access_node_type_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_sectoral_analysis';
  $strongarm->value = 1;
  $export['workbench_access_node_type_sectoral_analysis'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_taxonomy';
  $strongarm->value = array(
    'sections' => 'sections',
    'clusters' => 0,
    'coordination_hubs' => 0,
    'disaster_types' => 0,
    'display_properties' => 0,
    'emergencies' => 0,
    'funding' => 0,
    'job_title' => 0,
    'locations' => 0,
    'organization_types' => 0,
    'organizations' => 0,
    'population_types' => 0,
    'themes' => 0,
  );
  $export['workbench_access_taxonomy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_assessments_batch';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_assessments_batch'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_contacts_upload';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_contacts_upload'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_crf_request';
  $strongarm->value = 'published';
  $export['workbench_moderation_default_state_crf_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_hr_sitrep';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_hr_sitrep'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_indicator_data_batch';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_indicator_data_batch'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_sectoral_analysis';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_sectoral_analysis'] = $strongarm;

  return $export;
}
