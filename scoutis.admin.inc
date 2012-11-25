<?php
/**
 * @file
 * Config form
*/

function scoutis_config_form($form, &$form_state){
  //$form = array();
  $form['scoutis_testenv'] = array(
    '#type' => 'checkbox',
    '#title' => t('Is this a test environment ?'),
    '#default_value' => variable_get('scoutis_testenv', true),
    '#required' => true,
    );
  $form['scoutis_SISID'] = array(
    '#type' => 'textfield',
    '#title' => t('SkautIS App ID'),
    '#default_value' => variable_get('scoutis_SISID', ''),
    '#required' => true,
    );
  $form['scoutis_use_backlink'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use back Link'),
    '#default_value' => variable_get('scoutis_use_backlink', false),
    );

// http://api.drupal.org/api/drupal/developer%21topics%21forms_api_reference.html/7
  return system_settings_form($form);
}
