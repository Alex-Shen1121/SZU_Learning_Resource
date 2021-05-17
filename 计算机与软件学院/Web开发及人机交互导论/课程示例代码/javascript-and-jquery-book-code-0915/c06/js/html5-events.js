function setup() {
  var textInput;
  textInput = document.getElementById('message');
  textInput.focus();
}

window.addEventListener('DOMContentLoaded', setup, false);

window.addEventListener('beforeunload', function(event) {
  // This example has been updated to improve cross-browser compatibility (as recommended by MDN)
  var message = 'You have changes that have not been saved';
  (event || window.event).returnValue = message;
  return message;
});