// NOTE: Because this example loads external data it will not work locally in some browsers
// You can try it online at http://javascriptbook.com/code/c09 
// or run it on your own web server
function TimetableCtrl($scope, $http) {
  $http.get('js/items.json')
  .success(function(data) { $scope.sessions = data.sessions; })
  .error(function(data) { console.log('error'); });
}