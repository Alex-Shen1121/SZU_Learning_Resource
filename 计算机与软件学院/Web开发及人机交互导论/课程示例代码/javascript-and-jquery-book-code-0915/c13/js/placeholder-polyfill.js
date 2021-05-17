(function() {                                        // Place code in an IIFE
  // Test: Create an input element, and see if the placeholder is supported
  if ('placeholder' in document.createElement('input')) {
    return;
  }

  var length = document.forms.length;               // Get number of forms
  for (var i = 0; i < length; i++ ) {               // Loop through each one - updated shorter syntax
    showPlaceholder(document.forms[i].elements);    // Call showPlaceholder()
  }

  function showPlaceholder(elements) {              // Declare function
    for (var i = 0, l = elements.length; i < l; i++) { // For each element
      var el = elements[i];                         // Store that element

      if (!el.placeholder) {                        // If no placeholder set
        continue;                                   // Go to next element
      }                                             // Otherwise

      el.style.color = '#666666';                      // Set text to gray
      el.value = el.placeholder;                    // Add placeholder text

      addEvent(el, 'focus', function () {           // If it gains focus
        if (this.value === this.placeholder) {      // If value=placeholder 
          this.value = '';                          // Empty text input
          this.style.color = '#000000';                // Make text black
        }
      });

      addEvent(el, 'blur', function () {            // On blur event
        if (this.value === '') {                    // If the input is empty
          this.value = this.placeholder;            // Make value placeholder
          this.style.color = '#666666';                      // Set text to gray
        }
      }); 
    }                                                // End of for loop
  }                                                  // End showPlaceholder()
}());