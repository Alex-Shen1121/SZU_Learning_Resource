$(function() {

  // Get the background color of the first list item.
  var backgroundColor = $('li').css('background-color');

  // Write what the background color was after the list.
  $('ul').append('<p>Color was: ' + backgroundColor + '</p>');

  // Set several properties on all list items.
  $('li').css({
    'background-color': '#c5a996',
    'border': '1px solid #fff',
    'color': '#000',
    'text-shadow': 'none',
    'font-family': 'Georgia',
    'padding-left': '+=75'
  });
});