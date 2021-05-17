var request;                         // Latest image to be requested
var $current;                        // Image currently being shown 
var cache = {};                      // Cache object
var $frame = $('#photo-viewer');     // Container for image
var $thumbs = $('.thumb');           // Thumbnails

function crossfade($img) {           // Function to fade between images
                                     // Pass in new image as parameter
  if ($current) {                    // If there is currently an image showing
    $current.stop().fadeOut('slow'); // Stop any animation & fade it out
  }

  $img.css({                         // Set the CSS margins for the image
    marginLeft: -$img.width() / 2,   // Negative margin of half image's width
    marginTop: -$img.height() / 2    // Negative margin of half image's height
  });

  $img.stop().fadeTo('slow', 1);     // Stop animation on new image & fade in
  
  $current = $img;                   // New image becomes current image

}

$(document).on('click', '.thumb', function(e){ // When a thumb is clicked on
  var $img,                               // Create local variable called $img
      src = this.href;                    // Store path to image
      request = src;                      // Store latest image request
  
  e.preventDefault();                     // Stop default link behavior
  
  $thumbs.removeClass('active');          // Remove active from all thumbs
  $(this).addClass('active');             // Add active to clicked thumb

  if (cache.hasOwnProperty(src)) {        // If cache contains this image
    if (cache[src].isLoading === false) { // And if isLoading is false
      crossfade(cache[src].$img);         // Call crossfade() function
    }
  } else {                                // Otherwise it is not in cache
    $img = $('<img/>');                   // Store empty <img/> element in $img
    cache[src] = {                        // Store this image in cache
      $img: $img,                         // Add the path to the image
      isLoading: true                     // Set isLoading property to false
    };

    // Next few lines will run when image has loaded but are prepared first
    $img.on('load', function(){           // When image has loaded
      $img.hide();                        // Hide it
      // Remove is-loading class from frame & append new image to it
      $frame.removeClass('is-loading').append($img);
      cache[src].isLoading = false;       // Update isLoading in cache
      // If still most recently requested image then
      if (request === src) {
        crossfade($img);                  // Call crossfade() function
      }                                   // Solves asynchronous loading issue
    });

    $frame.addClass('is-loading');        // Add is-loading class to frame

    $img.attr({                           // Set attributes on <img> element
      'src': src,                         // Add src attribute to load image
      'alt': this.title || ''             // Add title if one was given in link
    });

  }

});

// Final line runs once when rest of script has loaded to show the first image
$('.thumb').eq(0).click();                // Simulate click on first thumb