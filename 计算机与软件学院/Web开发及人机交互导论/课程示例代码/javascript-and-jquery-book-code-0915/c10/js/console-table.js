var contacts = {                 // Store contact info in an object literal
  "London": {
    "Tel": "+44 (0)207 946 0128",
    "Country": "UK"},
  "Sydney": {
    "Tel": "+61 (0)2 7010 1212",
    "Country": "Australia"},
  "New York": {
    "Tel": "+1 (0)1 555 2104",
    "Country": "USA"}
};

console.table(contacts);                   // Write data content to console

var city, contactDetails;                  // Declare variables
contactDetails = '';                       // Will hold details written to page

$.each(contacts, function(city, contacts) {
  contactDetails += city + ': ' + contacts.Tel + '<br />';
});
$('h2').after('<p>' + contactDetails + '</p>');