function compute(radius){
	var pi=3.14;
	var area=pi*radius*radius;
	return area;
}

function show(){
	var radius=parseFloat((document.getElementById("radiustext").value));
	var area=compute(radius);
	document.getElementById("areatext").value=area;
	return;
}