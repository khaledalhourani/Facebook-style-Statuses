(function ($) {

  Drupal.behaviors.fbss_comments = {
    attach: function (context, settings) {
      $('.fbss-comments-show-comment-form', context).one('click', function() {
        $(this).hide();
        $('#'+ this.id +' + div').show();
        return false;
      });
      $('.fbss-comments-show-comment-form-inner', context).one('click', function() {
        $(this).hide();
        $('#'+ this.id +' + div').show();
        return false;
      });
      $('a.fbss-comments-show-comments', context).one('click', function() {
        $(this).hide();
        $('#'+ this.id +' ~ div.fbss-comments-hide').show();
        return false;
      });
    }
  }

})(jQuery);