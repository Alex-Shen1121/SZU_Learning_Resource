(function () {
  var bio = $('#bio');
  var bioCounter = $('#bio-count');

  // show the counter when the field is focused and update the class
  // depending on amount of characters left
  bio.on('focus', updateCounter);
  bio.on('keyup', updateCounter);

  // when we leave the textarea, we hide the counter unless there are too
  // many characters
  bio.on('blur', function () {
    if (bioCounter.text() >= 0) {
      bioCounter.addClass('hide');
    }
  });


  function updateCounter(e) {
    var count = 140 - bio.val().length;
    var status = '';
    if (count < 0) {
      status = 'error';
    } else if (count <= 15) {
      status = 'warn';
    } else {
      status = 'good';
    }

    // remove previous classes
    bioCounter.removeClass('error warn good hide');
    // add new class
    bioCounter.addClass(status);
    bioCounter.text(count);
  }

}());