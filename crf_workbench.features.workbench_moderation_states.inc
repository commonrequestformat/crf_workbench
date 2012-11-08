<?php
/**
 * @file
 * crf_workbench.features.workbench_moderation_states.inc
 */

/**
 * Implements hook_workbench_moderation_export_states().
 */
function crf_workbench_workbench_moderation_export_states() {
  $items = array(
    'archived' => array(
      'name' => 'archived',
      'label' => 'Archived',
      'description' => 'Archive',
      'weight' => '0',
    ),
    'draft' => array(
      'name' => 'draft',
      'label' => 'Draft',
      'description' => 'Work in progress',
      'weight' => '-10',
    ),
    'finalised' => array(
      'name' => 'finalised',
      'label' => 'Finalised',
      'description' => 'Ready for publication',
      'weight' => '-7',
    ),
    'needs_review' => array(
      'name' => 'needs_review',
      'label' => 'Needs Review',
      'description' => 'Review requested',
      'weight' => '-8',
    ),
    'published' => array(
      'name' => 'published',
      'label' => 'Published',
      'description' => 'Make this version live',
      'weight' => '-6',
    ),
    'submitted_to_ocha' => array(
      'name' => 'submitted_to_ocha',
      'label' => 'Submitted to OCHA',
      'description' => 'Ready for moderation',
      'weight' => '-9',
    ),
  );
  return $items;
}
