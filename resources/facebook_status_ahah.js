// Mostly copied from the AHAH Helper module.
(function($) {

//if (Drupal.jsEnabled) {
  $(document).ready(function() {
    //if (Drupal.ahah != undefined) {

/**
 * Override of Drupal.ahah.prototype.success to allow for new Drupal.settings.
 */
//Drupal.ahah.prototype.success = function (response, status) {
  Drupal.behaviors.facebook_status = {
  attach: function(context, settings) {
  var wrapper = $(this.wrapper);
  var form = $(this.element).parents('form');
  // Manually insert HTML into the jQuery object. Using $() directly crashes
  // Safari with long string lengths. http://dev.jquery.com/ticket/1152
  //var new_content = $('<div></div>').html(response.data);
  var new_content = $('<div></div>').html(settings.data);

  // Restore the previous action and target to the form.
  form.attr('action', this.form_action);
  this.form_target ? form.attr('target', this.form_target) : form.removeAttr('target');
  this.form_encattr ? form.attr('target', this.form_encattr) : form.removeAttr('encattr');

  // Remove the progress element.
  if (this.progress.element) {
    $(this.progress.element).remove();
  }
  if (this.progress.object) {
    this.progress.object.stopMonitoring();
  }
  $(this.element).removeClass('progress-disabled').attr('disabled', false);

  // Add the new content to the page.
  Drupal.freezeHeight();
  if (this.method == 'replace') {
    wrapper.empty().append(new_content);
  }
  else {
    wrapper[this.method](new_content);
  }

  // Immediately hide the new content if we're using any effects.
  if (this.showEffect != 'show') {
    new_content.hide();
  }

  // Determine what effect use and what content will receive the effect, then
  // show the new content. For browser compatibility, Safari is excluded from
  // using effects on table rows.
  if (($.browser.safari && $("tr.ahah-new-content", new_content).size() > 0)) {
    new_content.show();
  }
  else if ($('.ahah-new-content', new_content).size() > 0) {
    $('.ahah-new-content', new_content).hide();
    new_content.show();
    $(".ahah-new-content", new_content)[this.showEffect](this.showSpeed);
  }
  else if (this.showEffect != 'show') {
    new_content[this.showEffect](this.showSpeed);
  }

  // Merge in new and changed settings, if any.
  if (settings) {
    //$.extend(Drupal.settings, response.settings);
    $.extend(Drupal.settings, settings);
  }

  //Let other processes react to the update.
  wrapper.trigger('ahah_success', this.wrapper);

  // Attach all javascript behaviors to the new content. If the behaviors were
  // successfully added to the page, this if() statement allows #ahah[wrapper]
  // to be optional.
  if (new_content.parents('html').length > 0) {
    //Drupal.attachBehaviors(new_content, settings);
    Drupal.attachBehaviors(new_content);
  }

  Drupal.unfreezeHeight();
  
  } // added
};

    //}
  });
//}

})(jQuery);
