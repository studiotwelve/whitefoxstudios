<?php
function wfs_structured_data_sitelinks_search_box_form(){
  global $base_url;
  $u = $base_url; 
  $s = <<<EOL
<script type="application/ld+json">
{
  "@context": "http://schema.org",
  "@type": "WebSite",
  "url": "$u",
  "potentialAction": {
    "@type": "SearchAction",
    "target": "$u/?q=search/node/{search_term_string}",
    "query-input": "required name=search_term_string"
  }
}
</script>
EOL;

  $pre = "wfs_structured_data_";

  $form[$pre.'sitelinks_search_box'] = array(
    "#type"          => "textarea",
    "#title"         => t("Sitelinks Search Box Markup"),
    "#default_value" => variable_get($pre.'sitelinks_search_box', $s),
    "#description"   => t("Careful here, we're injecting html into the head."),
  );

  return system_settings_form($form);
}
