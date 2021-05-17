function setup() {                                  // Declare function
  var textInput;                                    // Create variable
  textInput = document.getElementById('username');  // Get username input
  textInput.focus();                                // Give username focus
}

window.addEventListener('load', setup, false); // When page loaded call setup()


/* LONGER VERSION WITH IE8 (and lower) compatibility

if (el.addEventListener) {
      el.addEventListener('click', function(e) {
        itemDone(e);
    }, false);
} else {
    el.attachEvent('onload', function(e){
      itemDone(e);
    });
}

*/