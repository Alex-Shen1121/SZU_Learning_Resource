// Set up the object
var hotel = {
  name : 'Park',
  rooms : 120,
  booked : 77
};

hotel.gym = true;
hotel.pool = false;
delete hotel.booked;

// Update the HTML
var elName = document.getElementById('hotelName'); // Get element
elName.textContent = hotel.name;                   // Update HTML with property of the object

var elPool = document.getElementById('pool');      // Get element
elPool.className = hotel.pool;                     // Update HTML with property of the object

var elGym = document.getElementById('gym');        // Get element
elGym.className = hotel.gym;                       // Update HTML with property of the object

/* 
NOTE: textContent does not work in IE8 or earlier
You can use innerHTML on line 14, but note the security issues on p228-231
*/