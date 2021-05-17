$(function() {
  var $listItemHTML = $('li').html();
  $('li').append('<i>' + $listItemHTML + '</i>');
});