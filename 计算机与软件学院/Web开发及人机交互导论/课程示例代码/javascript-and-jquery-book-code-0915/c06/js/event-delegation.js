function getTarget(e) {                          // Declare function
  if (!e) {                                      // If there is no event object
    e = window.event;                            // Use old IE event object
  }
  return e.target || e.srcElement;               // Get the target of event
}

function itemDone(e) {                           // Declare function
  // Remove item from the list
  var target, elParent, elGrandparent;           // Declare variables
  target = getTarget(e);                         // Get the item clicked link

  /*
  The book used the following code - but it had two shortcomings
  - Clicking between list items would remove the whole list
  - Clicking on italic text would remove the link - not the list item

  elParent = target.parentNode;
  elGrandparent = target.parentNode.parentNode;
  elGrandparent.removeChild(elParent);

  The next 10 lines improve that example
  */

  if ( target.nodeName.toLowerCase() == "a" ) {  // If user clicked on an a element
    elListItem = target.parentNode;              // Get its li element
    elList = elListItem.parentNode;              // Get the ul element
    elList.removeChild(elListItem);              // Remove list item from list
  }
  if ( target.nodeName.toLowerCase() == "em" ) { // If the user clicked on an em element
    elListItem = target.parentNode.parentNode;   // Get its li element
    elList = elListItem.parentNode;              // Get the ul element
    elList.removeChild(elListItem);              // Remove list item from list
  }

  // Prevent the link from taking you elsewhere
  if (e.preventDefault) {                        // If preventDefault() works
    e.preventDefault();                          // Use preventDefault() 
  } else {                                       // Otherwise
    e.returnValue = false;                       // Use old IE version
  }
}

// Set up event listeners to call itemDone() on click
var el = document.getElementById('shoppingList');// Get shopping list
if (el.addEventListener) {                       // If event listeners work
  el.addEventListener('click', function(e) {     // Add listener on click
    itemDone(e);                                 // It calls itemDone()
  }, false);                                     // Use bubbling phase for flow
} else {                                         // Otherwise
  el.attachEvent('onclick', function(e) {        // Use old IE model: onclick
    itemDone(e);                                 // Call itemDone()
  });
}