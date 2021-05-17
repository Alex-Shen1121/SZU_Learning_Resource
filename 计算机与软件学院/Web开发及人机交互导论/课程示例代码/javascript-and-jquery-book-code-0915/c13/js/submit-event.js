(function(){ 
  var form = document.getElementById('login');       // Get form element

  addEvent(form, 'submit', function(e) {             // When user submits form
    e.preventDefault();                              // Stop it being sent
    var elements = this.elements;                    // Get all form elements
    var username = elements.username.value;          // Select username entered
    var msg      = 'Welcome ' + username;            // Create welcome message
    document.getElementById('main').textContent = msg; // Write welcome message
  });
}());