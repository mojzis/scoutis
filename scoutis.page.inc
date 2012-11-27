<?php
/**
 *
 * https://is.skaut.cz/JunakWebservice/UserManagement.asmx?op=UserDetail
 */
/**
 * scoutis_login : page callback
 * @todo clear respective sessions before an attempt for login
 * @todo an ajax to obtain sis token
 */
function scoutis_sislogin() {
  $content = '';
  $content = 'connection test';
  // get params from post
  // dpm($_POST);
  // ctools_include('scoutis','scoutis.integration');
  libraries_load('skautis');
  $scout = new ScoutIS();
  $scout->logMeIn($_POST['skautIS_Token']);
  //dpm($scout->getLoginID();
  // eventually go somewhere (? acccording to backurl if set)
  return $content;
}

function scoutis_sislogout() {
  $content = '';
  $content = 'thanks for your visit';

  // logout

  return $content;
}
