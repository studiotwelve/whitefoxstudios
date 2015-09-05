<?php
function wfs_seo_token_info(){
  $info = array(
    "types" => array(
      "company" => array(
        "name" => t("Company tokens"),
        "description" => t("Prints company info based on the description"),
      ),
    ),
  );
  
  include_once("wfs_seo.vars.inc");
    
  $vars = wfs_seo_variables();
  
  $tokens = array();
  
  foreach($vars as $k => $v){
    $n = ucwords(str_replace("_", " ", $k));
    
    $tokens[$k] = array(
      "name" => t($n),
      "description" => t("Outputs $n, eg. $v"),
    );
  }
  
  $info["tokens"]["company"] = $tokens;
  
  return $info;
}

function wfs_seo_tokens($type, $tokens, array $data = array(), array $options = array()){
  include_once("wfs_seo.vars.inc");
  
  $vars = wfs_seo_variables();
  
  $replacements = array();
  
  $sanitize = !empty($options['sanitize']);
  
  if ($type == 'company') {
    foreach($tokens as $name => $original){
      $val = $vars[$name];
      $replacements[$original] = $sanitize ? check_plain($val) : $val;
    }
  }
  
  return $replacements;
}
