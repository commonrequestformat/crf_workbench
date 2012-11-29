<?php
/**
 * @file
 * crf_workbench.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function crf_workbench_default_rules_configuration() {
  $items = array();
  $items['rules_content_finalised'] = entity_import('rules_config', '{ "rules_content_finalised" : {
      "LABEL" : "Content finalised",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_crf_request" } },
        { "entity_has_field" : {
            "entity" : [ "node:field-crf-request" ],
            "field" : "field_crf_req_contact"
          }
        },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_cluster" } },
        { "entity_has_field" : {
            "entity" : [ "node:field-cluster:field-information-focal-points:0" ],
            "field" : "field_contact_email"
          }
        },
        { "entity_has_field" : {
            "entity" : [ "node:field-cluster:field-information-focal-points:0" ],
            "field" : "field_contact_first_name"
          }
        },
        { "entity_has_field" : {
            "entity" : [ "node:field-cluster:field-information-focal-points:0" ],
            "field" : "field_contact_lastname"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [
              "node:field-cluster:field-information-focal-points:0:field-contact-email"
            ],
            "subject" : "[node:content-type] provided for [node:field-cluster:name] in [node:field-crf-request:title] is now finalised",
            "message" : "Dear [node:field-cluster:field-information-focal-points:0:field-contact-first-name] [node:field-cluster:field-information-focal-points:0:field-contact-lastname],\\r\\n\\r\\nKindly note that the [node:content-type] for [node:field-cluster:name-field] in the Information Request [node:field-crf-request:title] has been finalised.  The information can be viewed online: [node:url]\\r\\n\\r\\nNo action is required on your part at this time.\\r\\n\\r\\nKind regards,\\r\\nOCHA",
            "from" : [ "node:field-crf-request:field-crf-req-contact:0:mail" ],
            "language" : [ "" ]
          }
        },
        { "redirect" : { "url" : "\\u003Cfront\\u003E" } }
      ]
    }
  }');
  $items['rules_content_review_requested'] = entity_import('rules_config', '{ "rules_content_review_requested" : {
      "LABEL" : "Content review requested",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workbench_moderation", "rules", "workbench_access" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_crf_request" } },
        { "entity_has_field" : {
            "entity" : [ "node:field-crf-request" ],
            "field" : "field_crf_req_contact"
          }
        },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_cluster" } },
        { "entity_has_field" : {
            "entity" : [ "node:field-cluster:field-information-focal-points:0" ],
            "field" : "field_contact_email"
          }
        }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "user",
              "property" : "mail",
              "value" : [
                "node:field-cluster:field-information-focal-points:0:field-contact-email"
              ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "information_focal_point" : "Information Focal Point" } }
          }
        },
        { "data_set" : { "data" : [ "node:author" ], "value" : [ "information-focal-point:0" ] } },
        { "workbench_access_assign_access_section" : { "node" : [ "node" ], "access_section" : "46" } },
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "OCHA request information review for [node:author:name] in Request [node:field-crf-request:title]",
            "message" : "Dear [node:author:name],\\r\\n\\r\\nOCHA has reviewed your [node:content-type] submission in [node:field-crf-request:title] and has suggested some changes or a review. Kindly review the information at: [node:url].\\r\\n\\r\\nYou can choose to edit the content as well as view a comparison of historical modifications on this [node:content-type] before re-submitting it to OCHA.\\r\\n\\r\\nKind regards,\\r\\nOCHA",
            "from" : [ "node:field-crf-request:author:mail" ],
            "language" : [ "" ]
          }
        },
        { "redirect" : { "url" : "\\u003Cfront\\u003E" } }
      ]
    }
  }');
  $items['rules_content_submitted_to_ocha'] = entity_import('rules_config', '{ "rules_content_submitted_to_ocha" : {
      "LABEL" : "Content submitted to OCHA",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workbench_moderation", "rules", "workbench_access" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "submitted_to_ocha" } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_crf_request" } },
        { "entity_has_field" : {
            "entity" : [ "node:field-crf-request" ],
            "field" : "field_crf_req_contact"
          }
        }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : {
              "type" : "user",
              "id" : [ "node:field-crf-request:field-crf-req-contact:0:uid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "ocha_user" : "OCHA user" } }
          }
        },
        { "data_set" : { "data" : [ "node:author" ], "value" : [ "ocha-user" ] } },
        { "workbench_access_assign_access_section" : { "node" : [ "node" ], "access_section" : "45" } },
        { "mail" : {
            "to" : [ "node:field-crf-request:field-crf-req-contact:0:mail" ],
            "subject" : "[node:content-type] provided by [site:current-user:field-first-name] [site:current-user:field-last-name] for [node:field-cluster:name-field] in [node:field-crf-request:title]",
            "message" : "Dear [node:field-crf-request:field-crf-req-contact:0:field-first-name] [node:field-crf-request:field-crf-req-contact:0:field-last-name],\\r\\n\\r\\nKindly note that [site:current-user:field-first-name] [site:current-user:field-last-name] has uploaded a [node:content-type] for [node:field-cluster:name-field] in the Information Request [node:field-crf-request:title] to the CRF website.\\r\\n\\r\\nThe data can be reviewed at: [node:url]\\r\\n\\r\\nAt this point, we encourage you review the submission. If changes are required, you can make the necessary edits and send the information back to [site:current-user:field-first-name] [site:current-user:field-last-name] by selecting \\u0022Request Review\\u0022. If the information is complete, you can finish the process by selecting \\u0022Finalise\\u0022.\\r\\n\\r\\nKind regards.",
            "from" : [ "site:current-user:mail" ],
            "language" : [ "" ]
          }
        },
        { "redirect" : { "url" : "\\u003Cfront\\u003E" } }
      ]
    }
  }');
  $items['rules_non_cluster_content_submitted_to_ocha'] = entity_import('rules_config', '{ "rules_non_cluster_content_submitted_to_ocha" : {
      "LABEL" : "Non-Cluster content submitted to OCHA",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workbench_moderation", "rules", "workbench_access" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "submitted_to_ocha" } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_nc_request" } },
        { "entity_has_field" : {
            "entity" : [ "node:field-nc-request" ],
            "field" : "field_crf_req_contact"
          }
        }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : {
              "type" : "user",
              "id" : [ "node:field-nc-request:field-crf-req-contact:0:uid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "ocha_user" : "OCHA user" } }
          }
        },
        { "data_set" : { "data" : [ "node:author" ], "value" : [ "ocha-user" ] } },
        { "workbench_access_assign_access_section" : { "node" : [ "node" ], "access_section" : "45" } },
        { "mail" : {
            "to" : [ "node:field-nc-request:field-crf-req-contact:0:mail" ],
            "subject" : "[node:content-type] provided by [site:current-user:field-first-name] [site:current-user:field-last-name] for [node:field-cluster:name-field] in [node:field-nc-request:title]",
            "message" : "Dear [node:field-nc-request:field-crf-req-contact:0:field-first-name] [node:field-nc-request:field-crf-req-contact:0:field-last-name],\\r\\n\\r\\nKindly note that [site:current-user:field-first-name] [site:current-user:field-last-name] has uploaded a [node:content-type] for [node:field-cluster:name-field] in the Information Request [node:field-nc-request:title] to the CRF website.\\r\\n\\r\\nThe data can be reviewed at: [node:url]\\r\\n\\r\\nAt this point, we encourage you review the submission. If changes are required, you can make the necessary edits and send the information back to [site:current-user:field-first-name] [site:current-user:field-last-name] by selecting \\u0022Request Review\\u0022. If the information is complete, you can finish the process by selecting \\u0022Finalise\\u0022.\\r\\n\\r\\nKind regards.",
            "from" : [ "site:current-user:mail" ],
            "language" : [ "" ]
          }
        },
        { "redirect" : { "url" : "\\u003Cfront\\u003E" } }
      ]
    }
  }');
  $items['rules_pipeline_managers_finalised'] = entity_import('rules_config', '{ "rules_pipeline_managers_finalised" : {
      "LABEL" : "Pipeline Managers finalised",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_nc_request" } },
        { "entity_has_field" : {
            "entity" : [ "node:field-nc-request" ],
            "field" : "field_crf_req_contact"
          }
        },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_pln_mngrs_contacts" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:field-pln-mngrs-contacts:0:mail" ],
            "subject" : "[node:content-type] provided for [node:field-cluster:name] in [node:field-nc-request:title] is now finalised",
            "message" : "Dear [node:field-pln-mngrs-contacts:0:field-first-name] [node:field-pln-mngrs-contacts:0:field-last-name],\\r\\n\\r\\nKindly note that the [node:content-type] for [node:field-cluster:name-field] in the Information Request [node:field-nc-request:title] has been finalised.  The information can be viewed online: [node:url]\\r\\n\\r\\nNo action is required on your part at this time.\\r\\n\\r\\nKind regards,\\r\\nOCHA",
            "from" : [ "node:field-nc-request:field-crf-req-contact:0:mail" ],
            "language" : [ "" ]
          }
        },
        { "redirect" : { "url" : "\\u003Cfront\\u003E" } }
      ]
    }
  }');
  $items['rules_pipeline_managers_review_requested'] = entity_import('rules_config', '{ "rules_pipeline_managers_review_requested" : {
      "LABEL" : "Pipeline Managers review requested",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workbench_moderation", "rules", "workbench_access" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_nc_request" } },
        { "entity_has_field" : {
            "entity" : [ "node:field-nc-request" ],
            "field" : "field_crf_req_contact"
          }
        },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_pln_mngrs_contacts" } }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "user",
              "property" : "mail",
              "value" : [ "node:field-pln-mngrs-contacts:0:mail" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "editor" : "Editor" } }
          }
        },
        { "data_set" : { "data" : [ "node:author" ], "value" : [ "editor:0" ] } },
        { "workbench_access_assign_access_section" : { "node" : [ "node" ], "access_section" : "46" } },
        { "mail" : {
            "to" : [ "editor:0:mail" ],
            "subject" : "OCHA request information review for [editor:0:field-first-name] [editor:0:field-last-name] in Request [node:field-nc-request:title]",
            "message" : "Dear [editor:0:field-first-name] [editor:0:field-last-name],\\r\\n\\r\\nOCHA has reviewed your [node:content-type] submission in [node:field-nc-request:title] and has suggested some changes or a review. Kindly review the information at: [node:url].\\r\\n\\r\\nYou can choose to edit the content as well as view a comparison of historical modifications on this [node:content-type] before re-submitting it to OCHA.\\r\\n\\r\\nKind regards,\\r\\nOCHA",
            "from" : [ "node:field-nc-request:author:mail" ],
            "language" : [ "" ]
          }
        },
        { "redirect" : { "url" : "\\u003Cfront\\u003E" } }
      ]
    }
  }');
  $items['rules_public_info_officers_finalised'] = entity_import('rules_config', '{ "rules_public_info_officers_finalised" : {
      "LABEL" : "Public info officers finalised",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_nc_request" } },
        { "entity_has_field" : {
            "entity" : [ "node:field-nc-request" ],
            "field" : "field_crf_req_contact"
          }
        },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_pbc_info_offcrs_contacts" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:field-pbc-info-offcrs-contacts:0:mail" ],
            "subject" : "[node:content-type] provided for [node:field-cluster:name] in [node:field-nc-request:title] is now finalised",
            "message" : "Dear [node:field-pbc-info-offcrs-contacts:0:field-first-name] [node:field-pbc-info-offcrs-contacts:0:field-last-name],\\r\\n\\r\\nKindly note that the [node:content-type] for [node:field-cluster:name-field] in the Information Request [node:field-nc-request:title] has been finalised.  The information can be viewed online: [node:url]\\r\\n\\r\\nNo action is required on your part at this time.\\r\\n\\r\\nKind regards,\\r\\nOCHA",
            "from" : [ "node:field-nc-request:field-crf-req-contact:0:mail" ],
            "language" : [ "" ]
          }
        },
        { "redirect" : { "url" : "\\u003Cfront\\u003E" } }
      ]
    }
  }');
  $items['rules_public_info_officers_review_requested'] = entity_import('rules_config', '{ "rules_public_info_officers_review_requested" : {
      "LABEL" : "Public info officers review requested",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workbench_moderation", "rules", "workbench_access" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_nc_request" } },
        { "entity_has_field" : {
            "entity" : [ "node:field-nc-request" ],
            "field" : "field_crf_req_contact"
          }
        },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_pbc_info_offcrs_contacts" } }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "user",
              "property" : "mail",
              "value" : [ "node:field-pbc-info-offcrs-contacts:0:mail" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "editor" : "Editor" } }
          }
        },
        { "data_set" : { "data" : [ "node:author" ], "value" : [ "editor:0" ] } },
        { "workbench_access_assign_access_section" : { "node" : [ "node" ], "access_section" : "46" } },
        { "mail" : {
            "to" : [ "editor:0:mail" ],
            "subject" : "OCHA request information review for [editor:0:field-first-name] [editor:0:field-last-name] in Request [node:field-nc-request:title]",
            "message" : "Dear [editor:0:field-first-name] [editor:0:field-last-name],\\r\\n\\r\\nOCHA has reviewed your [node:content-type] submission in [node:field-nc-request:title] and has suggested some changes or a review. Kindly review the information at: [node:url].\\r\\n\\r\\nYou can choose to edit the content as well as view a comparison of historical modifications on this [node:content-type] before re-submitting it to OCHA.\\r\\n\\r\\nKind regards,\\r\\nOCHA",
            "from" : [ "node:field-nc-request:author:mail" ],
            "language" : [ "" ]
          }
        },
        { "redirect" : { "url" : "\\u003Cfront\\u003E" } }
      ]
    }
  }');
  return $items;
}
