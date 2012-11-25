<?php
/**
 * @file
 *
 */

class ScoutIS {


  private $sis;

  private $sisID;

  public function __construct() {
    $this->sis = SkautIS::getInstance(
      variable_get('scoutis_SISID','1234'),
      variable_get('scoutis_testenv', true));
  }

  public function getLoginID() {

    try {
        $this->sisID = $this->sis->user->userDetail()->ID;
    } catch (SkautIS_Exception $ex) {
        //return false;
    }
    //return $this->sisID;
  }

  public function logMeIn($token) {
    $this->sis->setToken($token);
    if (!$this->sisID) {
      $this->getLoginID();
    }
    dpm($this->sisID);
    // find him in database
    if($this->sisID) {
      $q = ldh_efq('user','user');
      $r = $q->fieldCondition('field_skautis_user','value',$this->sisID)
        ->execute();
      if (isset($r['user'])) {
        $uid = end(array_keys($r['user']));
        global $user;
        $user = user_load($uid);
        $usrar = array('uid' => $uid);
        // ? $form_state['redirect'] = 'user/' . $user->uid;
        user_login_finalize($usrar);
      } else {
        dpm('id not found in drupal');
      }
    } else {
      dpm('no id from SIS');
    }
  }

  public function skautLink() {
    $backlink = null;
    if (variable_get('scoutis_use_backlink', false)) {
      //$backlink = ;
    }
    return $this->sis->getLoginUrl($backlink);
  }

}
