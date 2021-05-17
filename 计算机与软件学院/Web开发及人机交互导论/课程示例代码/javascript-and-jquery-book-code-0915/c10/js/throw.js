var width = 12;                                     // width variable
var height = 'test';                                // height variable

function calculateArea(width, height) {
  try {
    var area = width * height;                      // Try to calculate area
    if (!isNaN(area)) {                             // If it is a number
      return area;                                  // Return the area
    } else {                                        // Otherwise throw an error
      throw new Error('calculateArea() received invalid number');
    }
  } catch(e) {                                     // If there was an error
    console.log(e.name + ' ' + e.message);          // Show error in console
    return 'We were unable to calculate the area.'; // Show users a message
  }
}

// TRY TO SHOW THE AREA ON THE PAGE
document.getElementById('area').innerHTML = calculateArea(width, height);