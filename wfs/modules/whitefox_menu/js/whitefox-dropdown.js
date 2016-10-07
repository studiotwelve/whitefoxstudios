(function($){
  $(document).ready(function(e){
    $('.whitefox-dropdown a.active').each(function(){
      $(this).parents('li.expanded').addClass('active');
    });
  });
})(jQuery);
