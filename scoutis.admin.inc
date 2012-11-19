<?php
/**
 * @file
 * Config form
*/

function scoutis_config_form($form, &$form_state){
  //$form = array();
  $form['testenv'] = array(
    '#type' => 'checkbox',
    '#title' => t('Is this a test envireonment ?'),
    '#default_value' => variable_get('scoutis_testenv', true),
    '#required' => true,
    );
// http://api.drupal.org/api/drupal/developer%21topics%21forms_api_reference.html/7
  return system_settings_form($form);
}
