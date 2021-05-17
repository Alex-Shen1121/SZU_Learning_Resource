var noteInput, noteName, textEntered, target;    // Declare variables

noteName = document.getElementById('noteName');  // Element that holds note
noteInput = document.getElementById('noteInput');// Input for writing the note

function writeLabel(e) {                         // Declare function
  if (!e) {                                      // If event object not present
    e = window.event;                            // Use IE5-8 fallback
  }
  target = e.target || e.srcElement;             // Get target of event
  textEntered = target.value;                    // Value of that element
  noteName.textContent = textEntered;            // Update note text
}


function recorderControls(e) {                   // Declare recorderControls()
  if (!e) {                                      // If event object not present
    e = window.event;                            // Use IE5-8 fallback
  }
  target = e.target || e.srcElement;             // Get the target element
  if (e.preventDefault) {                        // If preventDefault() supported
    e.preventDefault();                          // Stop default action
  } else {                                       // Otherwise
    e.returnValue = false;                       // IE fallback: stop default action
  }

  switch(target.getAttribute('data-state')) {    // Get the data-state attribute
    case 'record':                               // If its value is record
      record(target);                            // Call the record() function
      break;                                     // Exit function to where called
    case 'stop':                                 // If its value is stop
      stop(target);                              // Call the stop() function
      break;                                     // Exit function to where called
      // More buttons could go here...
  }
}

function record(target) {                        // Declare function
  target.setAttribute('data-state', 'stop');     // Set data-state attr to stop
  target.textContent = 'stop';                   // Set text to 'stop'
}

function stop(target) {
  target.setAttribute('data-state', 'record');   //Set data-state attr to record
  target.textContent = 'record';                 // Set text to 'record'
}

if (document.addEventListener) {                 // If event listener supported
  document.addEventListener('click', function(e) {// For any click document
    recorderControls(e);                         // Call recorderControls()
  }, false);                                     // Capture during bubble phase
  // If input event fires on noteInput input call writeLabel()
  noteInput.addEventListener('input', writeLabel, false); 
} else {                                         // Otherwise
  document.attachEvent('onclick', function(e) {  // IE fallback: any click
    recorderControls(e);                         // Calls recorderControls()
  });
 // If keyup event fires on noteInput call writeLabel()
  noteInput.attachEvent('onkeyup', writeLabel);
}