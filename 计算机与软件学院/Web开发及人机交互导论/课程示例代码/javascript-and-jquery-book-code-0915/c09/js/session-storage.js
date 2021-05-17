// This example has been updated to use Modernizr - please note the use of of lowercase in sessionstorage
if (Modernizr.sessionstorage) {

  var txtUsername = document.getElementById('username'),  // Get form elements
      txtAnswer = document.getElementById('answer');

  txtUsername.value = sessionStorage.getItem('username'); // Elements populated
  txtAnswer.value = sessionStorage.getItem('answer');     // by sessionStorage

  txtUsername.addEventListener('input', function () {     // Save data on keyup
    sessionStorage.setItem('username', txtUsername.value);
  }, false);

  txtAnswer.addEventListener('input', function () {       // Save data on keyup
    sessionStorage.setItem('answer', txtAnswer.value);
  }, false);
}