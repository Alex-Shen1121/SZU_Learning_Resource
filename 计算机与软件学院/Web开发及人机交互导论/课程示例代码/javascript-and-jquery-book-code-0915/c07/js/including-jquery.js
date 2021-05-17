$(document).ready(function() {
  $('h2').hide().slideDown();
  $('li').hide().each( function(index) {
    $(this).delay(700*index).fadeIn(700);
  });
});