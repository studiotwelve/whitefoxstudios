(function($){
  $(document).ready(function(){
    $('.admin-menu [action*="/admin"] .form-actions [type=submit], .admin-menu [action*="/edit"] .form-actions [type=submit], .admin-menu [action*="/add"] .form-actions [type=submit], .admin-menu:not(page-admin) #branding .tabs > li > a, .admin-menu:not(page-admin) #page .tabs > li > a, .admin-menu:not(page-admin) .region-content > .tabs > ul > li > a').each(function(i,o){

      $(o).clone().appendTo('.whitefox-menu').click(function(e){
        $(o).click();
      });

      $(o).hide();

      $("#views-display-menu-tabs.tabs.secondary > li > a").show();

      $("#views-display-menu-tabs.tabs.secondary").css({
            "left" : "auto",
        "position" : "relative",
      });
    });
    
    adjustMargins($("#admin-menu").outerHeight(), $(".whitefox-menu").outerHeight());
  });
  
  $(window).on("load, resize", function(e){
    adjustMargins($("#admin-menu").outerHeight(), $(".whitefox-menu").outerHeight());
  });

  function adjustMargins(x,y){
    x=" "+x+"px!important"; y=" "+y+"px!important";
    
    $("body.admin-menu").css({"margin-top": x, "margin-bottom": y});
  }
})(jQuery);
