<?php
/**
 * @file
 * crf_workbench.features.uuid_entities.inc
 */

/**
 * Implements hook_uuid_default_entities().
 */
function crf_workbench_uuid_default_entities() {
  $entities = array();

  $entities['sections'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/a74f3cb4-9641-4948-9cb8-9b62ee1ac7aa',
      'cause' => FALSE,
    ),
    'description' => NULL,
    'description_field' => array(
      'und' => array(
        0 => array(
          'format' => 'simple',
          'summary' => NULL,
          'value' => NULL,
        ),
      ),
    ),
    'description_original' => NULL,
    'format' => 'simple',
    'name' => 'OCHA',
    'name_field' => array(
      'und' => array(
        0 => array(
          'format' => NULL,
          'value' => 'OCHA',
        ),
      ),
    ),
    'name_original' => 'OCHA',
    'rdf_mapping' => array(
      'rdftype' => array(
        0 => 'skos:Concept',
      ),
      'name' => array(
        'predicates' => array(
          0 => 'rdfs:label',
          1 => 'skos:prefLabel',
        ),
      ),
      'description' => array(
        'predicates' => array(
          0 => 'skos:definition',
        ),
      ),
      'vid' => array(
        'predicates' => array(
          0 => 'skos:inScheme',
        ),
        'type' => 'rel',
      ),
      'parent' => array(
        'predicates' => array(
          0 => 'skos:broader',
        ),
        'type' => 'rel',
      ),
    ),
    'translations' => array(
      'original' => NULL,
      'data' => array(),
    ),
    'uuid' => 'a74f3cb4-9641-4948-9cb8-9b62ee1ac7aa',
    'vocabulary_machine_name' => 'sections',
    'weight' => '0',
  );
  $entities['sections'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/fb03c566-0ce0-4edc-a4f1-0ed8ab4289a1',
      'cause' => FALSE,
    ),
    'description' => NULL,
    'description_field' => array(
      'und' => array(
        0 => array(
          'format' => 'simple',
          'summary' => NULL,
          'value' => NULL,
        ),
      ),
    ),
    'description_original' => NULL,
    'format' => 'simple',
    'name' => 'Clusters',
    'name_field' => array(
      'und' => array(
        0 => array(
          'format' => NULL,
          'value' => 'Clusters',
        ),
      ),
    ),
    'name_original' => 'Clusters',
    'rdf_mapping' => array(
      'rdftype' => array(
        0 => 'skos:Concept',
      ),
      'name' => array(
        'predicates' => array(
          0 => 'rdfs:label',
          1 => 'skos:prefLabel',
        ),
      ),
      'description' => array(
        'predicates' => array(
          0 => 'skos:definition',
        ),
      ),
      'vid' => array(
        'predicates' => array(
          0 => 'skos:inScheme',
        ),
        'type' => 'rel',
      ),
      'parent' => array(
        'predicates' => array(
          0 => 'skos:broader',
        ),
        'type' => 'rel',
      ),
    ),
    'translations' => array(
      'original' => NULL,
      'data' => array(),
    ),
    'uuid' => 'fb03c566-0ce0-4edc-a4f1-0ed8ab4289a1',
    'vocabulary_machine_name' => 'sections',
    'weight' => '0',
  );

  return $entities;
}
