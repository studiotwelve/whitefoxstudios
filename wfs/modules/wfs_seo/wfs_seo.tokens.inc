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
    $var = variable_get("wfs_seo_$k", $v);
    $tokens[$k] = array(
      "name" => t($n),
      "description" => t("Outputs $n, eg. $var"),
    );
  }

  $info["tokens"]["company"] = $tokens;

  return $info;
}

function wfs_seo_tokens($type, $tokens, array $data = array(), array $options = array()){
  include_once("wfs_seo.vars.inc");

  $vars = wfs_seo_variables();

  $social = array(
    'facebook'    => variable_get('wfs_seo_facebook', false),
    'google_plus' => variable_get('wfs_seo_google_plus', false),
    'instagram'   => variable_get('wfs_seo_instagram', false),
    'linked_in'   => variable_get('wfs_seo_linked_in', false),
    'pinterest'   => variable_get('wfs_seo_pinterest', false),
    'twitter'     => variable_get('wfs_seo_twitter', false),
    'youtube'     => variable_get('wfs_seo_youtube', false),
  );

  $vars += $social;

  $replacements = array();

  $sanitize = !empty($options['sanitize']);

  if ($type == 'company') {

    foreach($tokens as $name => $original){
      $val = $vars[$name];
      if($val=="+1-828-"){$val=$vars["phone"];}
      if($name=="street"&&$val==""){$val=$vars["street"];}

      if(isset($social[$name]) && !empty($social[$name])){
        $val = $social[$name];
      }

      $replacements[$original] = $sanitize ? check_plain($val) : $val;
    }

    foreach($vars as $k => $v){
      $n = ucwords(str_replace("_", " ", $k));
      $var = variable_get("wfs_seo_$k", $v);
      $replacements[$tokens[$k]] = $var;
    }
  }

  return $replacements;
}
