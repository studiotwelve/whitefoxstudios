<?php
function wfs_admin_settings_form(){
  $pre = "wfs_";

  $var = array(
    $pre."modernizr.js" => TRUE,
    $pre."migrate.js" => TRUE,
    $pre."fix.js" => TRUE,
    $pre."fix.css" => TRUE,
  );

  foreach($var as $name => $value){
    $file = str_replace($pre, "", $name);

    $form[$name] = array(
      "#type" => "checkbox",
      "#title" => t("Load: @file", array("@file" => $file)),
      "#attributes" => array("checked" => (variable_get($name, $value) == 1) ? "checked" : ""),
    );
  }

  return system_settings_form($form);
}
