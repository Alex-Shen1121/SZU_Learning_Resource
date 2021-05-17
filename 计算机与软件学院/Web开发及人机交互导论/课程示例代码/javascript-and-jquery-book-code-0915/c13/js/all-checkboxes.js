(function() {
  var form     = document.getElementById('interests'); // Get form
  var elements = form.elements;                      // All elements in form
  var options  = elements.genre;                     // Array: genre checkboxes
  var all      = document.getElementById('all');     // The 'All' checkbox

  function updateAll() {
    for (var i = 0; i < options.length; i++) {       // Loop through checkboxes
      options[i].checked = all.checked;              // Update checked property
      console.log(options[i].name);
    }
  }
  addEvent(all, 'change', updateAll);                // Add event listener

  function clearAllOption(e) {
    var target = e.target || e.srcElement;           // Get target of event
    if (!target.checked) {                           // If not checked
      all.checked = false;                           // Uncheck 'All' checkbox
    }
  }
  for (var i = 0; i < options.length; i++) {         // Loop through checkboxes 
    addEvent(options[i], 'change', clearAllOption);  // Add event listener
  }

}());