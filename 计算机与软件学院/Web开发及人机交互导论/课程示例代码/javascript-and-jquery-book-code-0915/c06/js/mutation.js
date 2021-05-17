var elList, addLink, newEl, newText, counter, listItems; // Declare variables

elList  = document.getElementById('list');               // Get list
addLink = document.querySelector('a');                   // Get add item button
counter = document.getElementById('counter');            // Get item counter

function addItem(e) {                                    // Declare function
  e.preventDefault();                                    // Prevent link action
  newEl = document.createElement('li');                  // New <li> element
  newText = document.createTextNode('New list item');    // New text node
  newEl.appendChild(newText);                            // Add text to <li>
  elList.appendChild(newEl);                             // Add <li> to list
}

function updateCount() {                                 // Declare function
  listItems = elList.getElementsByTagName('li').length;  // Get total of <li>s
  counter.innerHTML = listItems;                         // Update counter
}

addLink.addEventListener('click', addItem, false);       // Click on button
elList.addEventListener('DOMNodeInserted', updateCount, false); // DOM updated