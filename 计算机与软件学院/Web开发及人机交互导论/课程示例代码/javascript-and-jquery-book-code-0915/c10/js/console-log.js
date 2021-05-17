console.log('And we\'re off...');               // Indicates script is running
var $form, width, height, area;
$form = $('#calculator');

$('form input[type="text"]').on('blur', function() { // When input loses focus
  console.log('You entered ', this.value );          // Write value to console
});

$('#calculator').on('submit', function(e) {     // When the user clicks submit
  e.preventDefault();                           // Prevent the form submitting
  console.log('Clicked submit...');             // Indicate button was clicked

  width = $('#width').val();
  console.log('Width ' + width);                // Write width to console

  height = $('#height').val();
  console.log('Height ', height);               // Write height to console

  area = width * height;
  console.log(area);                            // Write area to console

  $form.append('<p>' + area + '</p>')
});