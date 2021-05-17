// This example has been updated to fire on the keyup event instead of keypress 
// (on the last line in the event listener) as new text is not in the textarea until the key is released

var el;                                                    // Declare variables

function charCount(e) {                                    // Declare function
  var textEntered, charDisplay, counter, lastkey;          // Declare variables
  textEntered = document.getElementById('message').value;  // User's text
  charDisplay = document.getElementById('charactersLeft'); // Counter element
  counter = (180 - (textEntered.length));                  // Num of chars left
  charDisplay.textContent = counter;                       // Show chars left
  lastkey = document.getElementById('lastKey');            // Get last key elem
  lastkey.textContent = 'Last key in ASCII code: ' + e.keyCode; // Create msg 
}
el = document.getElementById('message');                   // Get msg element
el.addEventListener('keyup', charCount, false); // on keyup - call charCount()