var elUsername = document.getElementById('username');   // Username input
var elMsg      = document.getElementById('feedback');   // Error msg element

function checkUsername(minLength) {                     // Declare function
  if (elUsername.value.length < minLength) {            // If username too short
    // Set the error message
    elMsg.innerHTML = 'Username must be ' + minLength + ' characters or more';
  } else {                                             // Otherwise
    elMsg.innerHTML = '';                              // Clear msg
  }
}

elUsername.addEventListener('blur', function() {        // When it loses focus
  checkUsername(5);                                     // Pass argument here
}, false);