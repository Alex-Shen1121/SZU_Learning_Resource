var Pagnation = require('./lib/pagnation')

module.exports = function (Model) {
  return new Pagnation(Model);
}
