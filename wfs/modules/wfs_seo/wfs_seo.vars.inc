<?php
function wfs_seo_vars(){
  global $base_url;

  $pre = "wfs_seo_";

  $theme_default = variable_get('theme_default', NULL);
  $logo = theme_get_setting("logo", $theme_default);
  $logo_url = file_create_url($logo);

  $vars = array(
    "company" => array(
      "@context" => "http://schema.org",
      "@type" => "LocalBusiness",
      "@id" => $base_url,

      "name" => variable_get($pre."name", variable_get("site_name", NULL)),

      "address" => array(
        "@type" => "postalAddress",
        "addressLocality" => variable_get($pre."city", NULL),
        "addressRegion"   => variable_get($pre."state", NULL),
        "streetAddress"   => variable_get($pre."street", NULL),
        "postalCode"      => variable_get($pre."zip", NULL),
      ),

      "geo" => array(
        "@type" => "geoCoordinates",
        "latitude" => variable_get($pre."lat", NULL),
        "longitude" => variable_get($pre."long", NULL),
      ),

      "telephone" => variable_get($pre."phone", NULL),

      "url" => variable_get($pre."url", $base_url),

      "email" => variable_get($pre."email", variable_get("site_mail", NULL)),

      "openingHours" => variable_get($pre."hours", NULL),

      "logo" => variable_get($pre."logo", $logo_url),
    ),
  );

  $variables = array(
    "wfs_seo_company_json" => json_encode($vars["company"], JSON_PRETTY_PRINT | JSON_UNESCAPED_SLASHES),
  );

  foreach($vars["company"] as $key => $val){
    $key = str_replace("@", "", $key);

    if(is_array($val)){
      foreach($val as $k => $v){
        $k = str_replace("@", "", $k);

        $variables[$pre.$key."_".$k] = variable_get($pre.$key."_".$k, $v);
      }
    } else {
      $variables[$pre.$key] = variable_get($pre.$key, $val);
    }
  }

  return $variables;
}

function wfs_seo_variables(){
  include_once("wfs_seo.vars.inc");

  $pre = "wfs_seo_";

  $variables = wfs_seo_vars();

  $no_var = array(
    "context",
    "type",
    "address_type",
    "geo_type",
    "company_json",
  );

  foreach($no_var as $value){
    unset($variables[$pre.$value]);
  }

  $map = array(
    "address_addressLocality" => "city",
    "address_addressRegion" => "state",
    "address_streetAddress" => "street",
    "address_postalCode" => "zip",
    "geo_latitude" => "lat",
    "geo_longitude" => "long",
    "telephone" => "phone",
    "openingHours" => "hours",
  );

  $vars = array();

  foreach($variables as $key => $value){
    $k = str_replace($pre, "", $key);

    if(array_key_exists($k, $map)){
      $k = $map[$k];
    }
    
    if($k=="telephone"){$k="phone";}

    $value = is_null($value) ? variable_get($pre.$key, $value) : $value;

    $vars[$k] = $value;
  }
  
  $vars["phone"] = variable_get("wfs_seo_phone", false);
  $vars["street"] = variable_get("wfs_seo_street", false);

  $vars["address"] = variable_get($pre."address", t("@street @city, @state @zip", array(
    "@street" => $vars["street"],
    "@city" => $vars["city"],
    "@state" => $vars["state"],
    "@zip" => $vars["zip"],
  )));

  $vars["nap"] = variable_get($pre."nap", t("@name @address @phone", array(
    "@name" => $vars["name"],
    "@address" => $vars["address"],
    "@phone" => str_replace("+1-", "", $vars["phone"]),
  )));
  
  $social = array(
    'facebook'    => variable_get('wfs_seo_social_facebook', false),
    'google_plus' => variable_get('wfs_seo_social_google_plus', false),
    'instagram'   => variable_get('wfs_seo_social_instagram', false),
    'linked_in'   => variable_get('wfs_seo_social_linked_in', false),
    'pinterest'   => variable_get('wfs_seo_social_pinterest', false),
    'twitter'     => variable_get('wfs_seo_social_twitter', false),
    'youtube'     => variable_get('wfs_seo_social_youtube', false),
  );
  
  $vars += $social;

  return $vars;
}
