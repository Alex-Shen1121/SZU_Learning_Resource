(function(){
  var form      = document.getElementById('newPwd');  // The form
  var password  = document.getElementById('pwd');     // Password input
  var submit    = document.getElementById('submit');  // Submit button

  var submitted = false;                            // Has form been submitted?
  submit.disabled = true;                           // Disable submit button
  submit.className = 'disabled';                    // Style submit button
  console.log(submit.className);
  
  // On input: Check whether or not to enable the submit button
  addEvent(password, 'input', function(e) {         // On input of password
    var target = e.target || e.srcElement;          // Target of event
    submit.disabled = submitted || !target.value;   // Set disabled property
    // If form has been submitted or pwd has no value set CSS to disabled
    submit.className = (submitted || !target.value) ? 'disabled' : 'enabled';
  }); 

  // On submit: Disable the form so it cannot be submitted again
  addEvent(form, 'submit', function(e) {            // On submit
    if (submit.disabled || submitted) {             // If disabled OR sent
      e.preventDefault();                           // Stop form submitting
      return;                                       // Stop processing function
    }                                               // Otherwise continue...
    submit.disabled = true;                         // Disable submit button
    submitted = true;                               // Update submitted var
    submit.className = 'disabled';                  // Update style

    // Demo purposes only: What would have been sent & show submit is disabled
    e.preventDefault();                             // Stop form submitting
    alert('Password is ' + password.value);         // Show the text
  });
}());