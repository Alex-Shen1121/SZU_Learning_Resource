// This example has been updated to use Modernizr - please note the use of localstorage in lowercase
if (Modernizr.localstorage) {

  var txtUsername = document.getElementById('username'); // Get form elements
  var txtAnswer = document.getElementById('answer');

  txtUsername.value = localStorage.getItem('username');  // Elements populated
  txtAnswer.value = localStorage.getItem('answer');      // by localStorage data

  txtUsername.addEventListener('input', function () {    // Data saved on keyup
    localStorage.setItem('username', txtUsername.value);
  }, false);

  txtAnswer.addEventListener('input', function () {      // Data saved on keyup
    localStorage.setItem('answer', txtAnswer.value);
  }, false);
}