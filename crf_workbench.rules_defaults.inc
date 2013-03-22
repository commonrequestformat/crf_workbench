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
      "LABEL" : "Workflow content type finalised",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "finalised" } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_request" } },
        { "entity_has_field" : {
            "entity" : [ "node:field-request" ],
            "field" : "field_request_recipients"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:field-request:field-request-recipients:0:mail" ],
            "subject" : "[node:content-type] provided for [node:field-request:title] is now finalised",
            "message" : "Dear [node:field-request:field-request-recipients:0:field-first-name] [node:field-request:field-request-recipients:0:field-last-name],\\r\\n\\r\\nKindly note that the [node:content-type] for the Information Request [node:field-request:title] has been finalised.\\r\\n\\r\\n[node:log]\\r\\n\\r\\nThe information can be viewed online: [node:url]\\r\\n\\r\\nNo action is required on your part at this time.\\r\\n\\r\\nKind regards,\\r\\nOCHA",
            "from" : [ "site:mail" ],
            "language" : [ "" ]
          }
        },
        { "redirect" : { "url" : "\\u003Cfront\\u003E" } }
      ]
    }
  }');
  $items['rules_content_review_requested'] = entity_import('rules_config', '{ "rules_content_review_requested" : {
      "LABEL" : "Workflow content type review requested",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workbench_moderation", "rules", "workbench_access" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_request" } },
        { "entity_has_field" : {
            "entity" : [ "node:field-request" ],
            "field" : "field_request_recipients"
          }
        }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "user",
              "property" : "mail",
              "value" : [ "node:field-request:field-request-recipients:0:mail" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "information_focal_point" : "Information Focal Point" } }
          }
        },
        { "data_set" : { "data" : [ "node:author" ], "value" : [ "information-focal-point:0" ] } },
        { "workbench_access_assign_access_section" : { "node" : [ "node" ], "access_section" : "2" } },
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "OCHA request information review for [node:author:name] in Request [node:field-request:title]",
            "message" : "Dear [node:author:name],\\r\\n\\r\\nOCHA has reviewed your [node:content-type] submission in [node:field-request:title] and has suggested some changes or a review.\\r\\n\\r\\n[node:log]\\r\\n\\r\\nKindly review the information at: [node:url].\\r\\n\\r\\nYou can choose to edit the content as well as view a comparison of historical modifications on this [node:content-type] before re-submitting it to OCHA.\\r\\n\\r\\nKind regards,\\r\\nOCHA",
            "from" : [ "site:mail" ],
            "language" : [ "" ]
          }
        },
        { "redirect" : { "url" : "\\u003Cfront\\u003E" } }
      ]
    }
  }');
  $items['rules_content_submitted_to_ocha'] = entity_import('rules_config', '{ "rules_content_submitted_to_ocha" : {
      "LABEL" : "Report submitted to OCHA",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "report" : "report" } } } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_request" } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_reporting_type" } },
        { "entity_has_field" : {
            "entity" : [ "node:field-request" ],
            "field" : "field_request_requested_by"
          }
        }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : {
              "type" : "user",
              "id" : [ "node:field-request:field-request-requested-by:0:uid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "ocha_user" : "OCHA user" } }
          }
        },
        { "mail" : {
            "to" : [ "node:field-request:field-request-requested-by:0:mail" ],
            "subject" : "[node:field-reporting-type:0:name] provided by [site:current-user:field-first-name] [site:current-user:field-last-name] for [node:field-request:title]",
            "message" : "Dear [node:field-request:field-request-requested-by:0:field-first-name] [node:field-request:field-request-requested-by:0:field-last-name],\\r\\n\\r\\nKindly note that [site:current-user:field-first-name] [site:current-user:field-last-name] has uploaded a [node:field-reporting-type:0:name] for the Information Request [node:field-request:title] to the CRF website.\\r\\n\\r\\nThe data can be reviewed at: [node:url]\\r\\n\\r\\nKind regards.",
            "from" : [ "site:current-user:mail" ],
            "language" : [ "" ]
          }
        },
        { "redirect" : { "url" : "\\u003Cfront\\u003E" } }
      ]
    }
  }');
  return $items;
}
