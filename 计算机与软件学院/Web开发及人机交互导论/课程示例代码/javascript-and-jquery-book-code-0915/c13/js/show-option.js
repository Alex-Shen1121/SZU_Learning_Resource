(function() {
  var form, options, other, otherText, hide;           // Declare variables
  form      = document.getElementById('how-heard');    // Get the form
  options   = form.elements.heard;                     // Get the radio buttons
  other     = document.getElementById('other');        // Other radio button
  otherText = document.getElementById('other-text');   // Other text input
  otherText.className = 'hide';                        // Hide other text input

  for (var i = [0]; i < options.length; i++) {         // Loop through radios
    addEvent(options[i], 'click', radioChanged);       // Add event listener
  }

  function radioChanged() {
    hide = other.checked ? '' : 'hide';                // Is other checked?
    otherText.className = hide;                        // Text input visibility
    if (hide) {                                        // If text input hidden
      otherText.value = '';                            // Empty its contents
    }
  }
}());