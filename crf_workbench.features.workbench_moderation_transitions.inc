<?php
/**
 * @file
 * crf_workbench.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function crf_workbench_workbench_moderation_export_transitions() {
  $items = array(
    'draft:submitted_to_ocha' => array(
      'from_name' => 'draft',
      'to_name' => 'submitted_to_ocha',
      'transition_label' => 'Submit to OCHA',
    ),
    'needs_review:submitted_to_ocha' => array(
      'from_name' => 'needs_review',
      'to_name' => 'submitted_to_ocha',
      'transition_label' => 'Submit to OCHA',
    ),
    'submitted_to_ocha:needs_review' => array(
      'from_name' => 'submitted_to_ocha',
      'to_name' => 'needs_review',
      'transition_label' => 'Request review',
    ),
  );
  return $items;
}
