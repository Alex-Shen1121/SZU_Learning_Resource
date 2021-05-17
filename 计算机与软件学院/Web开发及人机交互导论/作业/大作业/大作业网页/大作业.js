/*设置出现或隐藏div的JS*/
document.getElementById("function1Button").onclick = function() {
	document.getElementById("function2").style.display = "none";
	document.getElementById("function3").style.display = "none";
	if (document.getElementById("function4"))
		document.getElementById("function4").style.display = "none";
	document.getElementById("function1").style.display = "block";
}
document.getElementById("function2Button").onclick = function() {
	document.getElementById("function1").style.display = "none";
	document.getElementById("function3").style.display = "none";
	if (document.getElementById("function4"))
		document.getElementById("function4").style.display = "none";
	document.getElementById("function2").style.display = "block";
}
document.getElementById("function3Button").onclick = function() {
	document.getElementById("function1").style.display = "none";
	document.getElementById("function2").style.display = "none";
	if (document.getElementById("function4"))
		document.getElementById("function4").style.display = "none";
	document.getElementById("function3").style.display = "block";
}
document.getElementById("function4Button").onclick = function() {
	document.getElementById("function1").style.display = "none";
	document.getElementById("function2").style.display = "none";
	document.getElementById("function3").style.display = "none";
	document.getElementById("function4").style.display = "block";
}

/*清空表单*/
function clear1() {
	document.getElementById('form1').form.reset();
}

function clear3() {
	document.getElementById('form3').form.reset();
}

function clear2() {
	/*根据行数，推断下一次的序列号*/
	var rownum = document.getElementById("table2").rows.length;
	/*获得inputbox的输入属性*/
	var date1 = document.getElementById('submitDate').value;
	var distance1 = document.getElementById('distance').value;
	/*因为div为固定高度，若大于11行，信息会超出div*/
	if (rownum > 11) {
		alert("当前骑行信息太多，请联系管理员删除部分信息。");
		return;
	}
	/*检查是否为空信息*/
	if (date1 == "" || distance1 == "") {
		alert("请正确输入信息！");
		return;
	}
	/*添加新的一行*/
	addtr(rownum, date1, distance1);
	addtr2(rownum, date1, distance1);
	/*清空表单*/
	document.getElementById('form2').form.reset();
}

function addtr(num, date, distance) {
	var j = 1;
	var tableobj = document.getElementById("table2");
	var trobj = document.createElement("tr");
	var tdobj = document.createElement("td");
	var thobj = document.createElement("th");
	/*在dom树下添加新的子节点，第一项为th，后两项为td*/
	for (var i = 0; i < 3; i++) {
		if (i == 0) {
			var thobj = document.createElement("th");
			thobj.innerHTML = num + '.';
			trobj.appendChild(thobj);
			continue;
		}
		if (i == 1) {
			var tdobj = document.createElement("td");
			tdobj.innerHTML = date;
			trobj.appendChild(tdobj);
		}
		if (i == 2) {
			var tdobj = document.createElement("td");
			tdobj.innerHTML = distance + 'km';
			trobj.appendChild(tdobj);
		}
	}
	trobj.appendChild(tdobj);
	tableobj.appendChild(trobj);
}

function addtr2(num, date, distance) {
	var j = 1;
	var tableobj = document.getElementById("table4");
	var trobj = document.createElement("tr");
	var tdobj = document.createElement("td");
	var thobj = document.createElement("th");
	/*在dom树下添加新的子节点，第一项为th，后三项为td*/
	for (var i = 0; i < 4; i++) {
		if (i == 0) {
			var thobj = document.createElement("th");
			thobj.innerHTML = num + '.';
			trobj.appendChild(thobj);
			continue;
		}
		if (i == 1) {
			var tdobj = document.createElement("td");
			tdobj.innerHTML = date;
			trobj.appendChild(tdobj);
		}
		if (i == 2) {
			var tdobj = document.createElement("td");
			tdobj.innerHTML = distance + 'km';
			trobj.appendChild(tdobj);
		}
		if (i == 3) {
			var tdobj = document.createElement("td");
			var id = "last" + num;
			/*为新id做准备*/
			num++;
			/*获取前一次总价*/
			var sum_ = document.getElementById(id).innerHTML;
			/*强制转换为float型*/
			var sum = parseFloat(sum_);
			sum += distance * 1.4;
			/*保留两位小数*/
			sum = Math.round(sum * 100) / 100
			tdobj.innerHTML = sum;
			tdobj.id = "last" + num;
			trobj.appendChild(tdobj);
		}
	}
	trobj.appendChild(tdobj);
	tableobj.appendChild(trobj);
}
