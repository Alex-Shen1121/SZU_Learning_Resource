$('.tab-list').each(function(){                   // Find lists of tabs
  var $this = $(this);                            // Store this list
  var $tab = $this.find('li.active');             // Get the active list item
  var $link = $tab.find('a');                     // Get link from active tab
  var $panel = $($link.attr('href'));             // Get active panel

  $this.on('click', '.tab-control', function(e) { // When click on a tab
    e.preventDefault();                           // Prevent link behavior
    var $link = $(this),                          // Store the current link
        id = this.hash;                           // Get href of clicked tab 

    if (id && !$link.is('.active')) {             // If not currently active
      $panel.removeClass('active');               // Make panel inactive
      $tab.removeClass('active');                 // Make tab inactive

      $panel = $(id).addClass('active');          // Make new panel active
      $tab = $link.parent().addClass('active');   // Make new tab active 
    }
  });
});