<?php
function wfs_seo_company_info_form(){
  include_once("wfs_seo.vars.inc");
  
  $vars = wfs_seo_variables();
  
  $pre = "wfs_seo_";
  
  $point = geocoder('google', $vars["address"]);

  if($point){
    $geoJSON = $point->out('json');
    $geoObject = json_decode($geoJSON);
    
    $vars["lat"] = $geoObject->coordinates[1];
    $vars["long"] = $geoObject->coordinates[0];
  } else {
    drupal_set_message("didn't geocode ".$vars["address"]);
  }
  
  foreach($vars as $key => $value){
    $title = t(ucwords(str_replace("_", " ", $key)));
    $default_value = variable_get($pre.$key, $value);
    
    if($key == "logo" && is_null($default_value)){
      $theme_default = variable_get('theme_default', NULL);
      $logo = theme_get_setting("logo", $theme_default);
      $logo_url = file_create_url($logo);
      
      $default_value = $logo_url;
    }
    
    if($key == "address" && is_null($default_value)){
      $default_value = t("@street @city, @state @zip", array(
        "@street" => $vars["street"],
        "@city" => $vars["city"],
        "@state" => $vars["state"],
        "@zip" => $vars["zip"],
      ));
    }
    
    if($key == "nap" && is_null($default_value)){
      $default_value = t("@name @address @phone", array(
        "@name" => $vars["name"],
        "@address" => $vars["address"],
        "@phone" => str_replace("+1-", "", $vars["phone"]),
      ));
    }
    
    $form[$pre.$key] = array(
      "#type"          => "textfield",
      "#title"         => $title,
      "#default_value" => $default_value,
    );
  }
  
  return system_settings_form($form);
}