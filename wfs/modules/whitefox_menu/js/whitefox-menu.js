(function($){
  $(document).ready(function(e){
    $('.whitefox-dropdown a.active').each(function(i, o){
      $(o).parents('li.expanded').addClass('active');
    });

    $('.whitefox-dropdown li.expanded').each(function(i, o){
      var $o  = $(o),
      $toggle = $('<span class="menu-toggler fa fa-angle-right"></span>');

      $toggle.click(function(e){
        $(this).toggleClass('open');
        $o.toggleClass('open');
        $o.find('>ul,>.whitefox-menu-mega').toggleClass('menu-open');
      });

      $o.append($toggle);
    });

    $('.whitefox-dropdown .menu-attach-block-wrapper').parent('li').addClass('block-attach');

    $('.whitefox-menu-toggler').click(function(e){
      var $menu = $($(this).data('target'));

      if ($menu != null) {
        $menu.toggleClass('mobile-open');

        $(this).toggleClass('open');
      }

      return false;
    });

    $('.whitefox-dropdown ul li').click(
      function(){
        var container_width = $('.container').width(),
            $submenu        = $(this).find('>ul,>.whitefox-menu-mega').not('.container'),
            ww              = $(window).width(),
            innerw          = ww - (ww - container_width) / 2;

        if ($submenu.length === 0)
          return;

        var offsetX = $submenu.offset().left + $submenu.width() - innerw;

        if (offsetX > 0) {
          var transformX = 0 - offsetX + 'px';

          $submenu.css({
            transform: 'translateX('+transformX+')'
          });
        }
      }
    );

    $('.whitefox-dropdown .container').each(function(){
      $(this).parent('li').addClass('whitefox-static')
    });
  });
})(jQuery);
