jQuery.MigrateMute=true;(function(){var h,g=function(){},e=["assert","clear","count","debug","dir","dirxml","error","exception","group","groupCollapsed","groupEnd","info","log","markTimeline","profile","profileEnd","table","time","timeEnd","timeStamp","trace","warn"],f=e.length,d=(window.console=window.console||{});while(f--){h=e[f];if(!d[h]){d[h]=g}}}());/android|crios|mobi/i.test(navigator.userAgent)&&!location.hash&&setTimeout(function(){if(!pageYOffset){window.scrollTo(0,0)}},1000);var a=navigator.userAgent,b,c=(a.indexOf("Mozilla/5.0")>-1&&a.indexOf("Android ")>-1&&a.indexOf("AppleWebKit")>-1&&a.indexOf("Chrome")===-1);if(a.match(/IEMobile\/10\.0/)){b=document.createElement("style");b.appendChild(document.createTextNode("@-ms-viewport{width:auto!important}"));document.querySelector("head").appendChild(b)}if(c){jQuery("select.form-control").removeClass("form-control").css("width","100%"); jQuery("html,body").addClass("not-ie");}

jQuery(document).ready(function(){
  jQuery("[data-toggle=collapse]").each(function(i,o){
    o = jQuery(o);
    o.on("click", function(e){
      var p = jQuery(o.attr("href"));
      p.on("shown.bs.collapse",function(e){
        var pOffset = p.offset(),
            pTop = pOffset.top;
        window.scroll(0,pTop-130);
      });
    });
  });
});
