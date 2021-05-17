(function() {

  // STORE EACH PERSON AS AN OBJECT IN AN ARRAY
  var people = [
    {                                              // Each person is an object
      name: 'Casey',                               // It holds name and rate
      rate: 60
    },
    {
      name: 'Camille',
      rate: 80
    },
    {
      name: 'Gordon',
      rate: 75
    },
    {
      name: 'Nigel',
      rate: 120
    }
  ];

  var rows = [],                        // rows array
      $min = $('#value-min'),           // Minimum text input
      $max = $('#value-max'),           // Maximum text input
      $table = $('#rates');             // The table that shows results

  function makeRows() {                 // Create table rows and the array
    people.forEach(function(person) {   // For each person object in people
      var $row = $('<tr></tr>');        // Create a row for them
      $row.append( $('<td></td>').text(person.name) ); // Add their name
      $row.append( $('<td></td>').text(person.rate) ); // Add their rate
      rows.push({ // Create rows array which links people objects to table rows
        person: person,                 // Reference to the person object
        $element: $row                  // Reference to row as jQuery selection
      });
    });
  }

  function appendRows() {               // Adds rows to the table
    var $tbody = $('<tbody></tbody>');  // Create <tbody> element
    rows.forEach(function(row) {        // For each object in the rows array
      $tbody.append(row.$element);      // Add the HTML for the row
    });
    $table.append($tbody);              // Add the rows to the table
  }

  function update(min, max) {           // Update the table content
    rows.forEach(function(row) {        // For each row in the rows array
      if (row.person.rate >= min && row.person.rate <= max) { // If in range
        row.$element.show();            // Show the row
      } else {                          // Otherwise
        row.$element.hide();            // Hide the row
      }
    });
  }

  function init() {                     // Tasks when script first runs
    $('#slider').noUiSlider({           // Set up the slide control
      range: [0, 150], start: [65, 90], handles: 2, margin: 20, connect: true,
      serialization: {to: [$min, $max],resolution: 1}
    }).change(function() { update($min.val(), $max.val()); });
    makeRows();                           // Create table rows and rows array
    appendRows();                         // Add the rows to the table
    update($min.val(), $max.val());     // Update table to show matches
  }

  $(init);                              // Call init() when DOM is ready
}());