(function(){
  var $content = $('#share-options').detach();   // Remove modal from page

  $('#share').on('click', function() {           // Click handler to open modal
    modal.open({content: $content, width:340, height:300});
  });
}());