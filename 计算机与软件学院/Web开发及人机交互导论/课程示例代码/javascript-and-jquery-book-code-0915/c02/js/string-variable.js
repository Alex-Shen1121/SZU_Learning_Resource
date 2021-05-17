// Create variables to hold the name and note text.
var username;
var message;

// Assign values to these variables.
username = 'Molly';
message = 'See our upcoming range';

// Get the element with an id of name.
var elName = document.getElementById('name');
// Replace the content of this element.
elName.textContent = username;

// Get the element with an id of note.
var elNote = document.getElementById('note');
// Replace the content of this element.
elNote.textContent = message;

/* 
NOTE: textContent does not work in IE8 or earlier
You can use innerHTML, but note the security issues on p228-231
elName.innerHTML = username;
elNote.innerHTML = message;
*/