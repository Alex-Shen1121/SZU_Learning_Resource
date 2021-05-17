(function() {
  var type  = document.getElementById('equipmentType');// Type select box
  var model = document.getElementById('model');        // Model select box
  var cameras = {                                      // Object stores cameras
    bolex: 'Bolex Paillard H8',
    yashica: 'Yashica 30',
    pathescape: 'Pathescape Super-8 Relax',
    canon: 'Canon 512'
  };
  var projectors = {                                  // Store projectors
    kodak: 'Kodak Instamatic M55',
    bolex: 'Bolex Sound 715',
    eumig: 'Eumig Mark S',
    sankyo: 'Sankyo Dualux'
  };

  // WHEN THE USER CHANGES THE TYPE SELECT BOX
  addEvent(type, 'change', function() {
    if (this.value === 'choose') {                // No selection made
      model.innerHTML = '<option>Please choose a type first</option>';
      return;                                     // No need to proceed further
    }
    var models = getModels(this.value);           // Select the right object

    // LOOP THROUGH THE OPTIONS IN THE OBJECT TO CREATE OPTIONS
    var options = '<option>Please choose a model</option>';
    var key;
    for (key in models) {                     // Loop through models
      options += '<option value="' + key + '">' + models[key] + '</option>';
    } // If an option could contain a quote, key should be escaped (see pXXX)
    model.innerHTML = options;                    // Update select box
  });

  function getModels(equipmentType) {
    if (equipmentType === 'cameras') {            // If type is cameras
      return cameras;                             // Return cameras object
    } else if (equipmentType === 'projectors') {  // If type is projectors
      return projectors;                          // Return projectors object
    }
  }
}());