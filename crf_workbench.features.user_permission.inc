<?php
/**
 * @file
 * crf_workbench.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function crf_workbench_user_default_permissions() {
  $permissions = array();

  // Exported permission: access workbench.
  $permissions['access workbench'] = array(
    'name' => 'access workbench',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: access workbench access by role.
  $permissions['access workbench access by role'] = array(
    'name' => 'access workbench access by role',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: administer maillog.
  $permissions['administer maillog'] = array(
    'name' => 'administer maillog',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'maillog',
  );

  // Exported permission: administer workbench.
  $permissions['administer workbench'] = array(
    'name' => 'administer workbench',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: administer workbench access.
  $permissions['administer workbench access'] = array(
    'name' => 'administer workbench access',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: administer workbench moderation.
  $permissions['administer workbench moderation'] = array(
    'name' => 'administer workbench moderation',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: assign workbench access.
  $permissions['assign workbench access'] = array(
    'name' => 'assign workbench access',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: batch update workbench access.
  $permissions['batch update workbench access'] = array(
    'name' => 'batch update workbench access',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: bypass workbench moderation.
  $permissions['bypass workbench moderation'] = array(
    'name' => 'bypass workbench moderation',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: delete maillog.
  $permissions['delete maillog'] = array(
    'name' => 'delete maillog',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'maillog',
  );

  // Exported permission: delete terms in sections.
  $permissions['delete terms in sections'] = array(
    'name' => 'delete terms in sections',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in sections.
  $permissions['edit terms in sections'] = array(
    'name' => 'edit terms in sections',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: moderate content from draft to submitted_to_ocha.
  $permissions['moderate content from draft to submitted_to_ocha'] = array(
    'name' => 'moderate content from draft to submitted_to_ocha',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: moderate content from needs_review to submitted_to_ocha.
  $permissions['moderate content from needs_review to submitted_to_ocha'] = array(
    'name' => 'moderate content from needs_review to submitted_to_ocha',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: moderate content from submitted_to_ocha to needs_review.
  $permissions['moderate content from submitted_to_ocha to needs_review'] = array(
    'name' => 'moderate content from submitted_to_ocha to needs_review',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: moderate content from submitted_to_ocha to published.
  $permissions['moderate content from submitted_to_ocha to published'] = array(
    'name' => 'moderate content from submitted_to_ocha to published',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: use workbench_moderation my drafts tab.
  $permissions['use workbench_moderation my drafts tab'] = array(
    'name' => 'use workbench_moderation my drafts tab',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: use workbench_moderation needs review tab.
  $permissions['use workbench_moderation needs review tab'] = array(
    'name' => 'use workbench_moderation needs review tab',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: view all unpublished content.
  $permissions['view all unpublished content'] = array(
    'name' => 'view all unpublished content',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: view any unpublished assessment content.
  $permissions['view any unpublished assessment content'] = array(
    'name' => 'view any unpublished assessment content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished assessments_batch content.
  $permissions['view any unpublished assessments_batch content'] = array(
    'name' => 'view any unpublished assessments_batch content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished cluster_objectives content.
  $permissions['view any unpublished cluster_objectives content'] = array(
    'name' => 'view any unpublished cluster_objectives content',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished contact content.
  $permissions['view any unpublished contact content'] = array(
    'name' => 'view any unpublished contact content',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished contacts_upload content.
  $permissions['view any unpublished contacts_upload content'] = array(
    'name' => 'view any unpublished contacts_upload content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished content.
  $permissions['view any unpublished content'] = array(
    'name' => 'view any unpublished content',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished crf_request content.
  $permissions['view any unpublished crf_request content'] = array(
    'name' => 'view any unpublished crf_request content',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished hr_sitrep content.
  $permissions['view any unpublished hr_sitrep content'] = array(
    'name' => 'view any unpublished hr_sitrep content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished indicator_data content.
  $permissions['view any unpublished indicator_data content'] = array(
    'name' => 'view any unpublished indicator_data content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished indicator_data_batch content.
  $permissions['view any unpublished indicator_data_batch content'] = array(
    'name' => 'view any unpublished indicator_data_batch content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished indicator_definition content.
  $permissions['view any unpublished indicator_definition content'] = array(
    'name' => 'view any unpublished indicator_definition content',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished link content.
  $permissions['view any unpublished link content'] = array(
    'name' => 'view any unpublished link content',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished page content.
  $permissions['view any unpublished page content'] = array(
    'name' => 'view any unpublished page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished sectoral_analysis content.
  $permissions['view any unpublished sectoral_analysis content'] = array(
    'name' => 'view any unpublished sectoral_analysis content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view maillog.
  $permissions['view maillog'] = array(
    'name' => 'view maillog',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'maillog',
  );

  // Exported permission: view moderation history.
  $permissions['view moderation history'] = array(
    'name' => 'view moderation history',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: view moderation messages.
  $permissions['view moderation messages'] = array(
    'name' => 'view moderation messages',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: view workbench access information.
  $permissions['view workbench access information'] = array(
    'name' => 'view workbench access information',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: view workbench taxonomy pages.
  $permissions['view workbench taxonomy pages'] = array(
    'name' => 'view workbench taxonomy pages',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'workbench_access',
  );

  return $permissions;
}
