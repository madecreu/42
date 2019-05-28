var el = document.getElementById("new");
el.addEventListener("click", check);
el.addEventListener("click", todo);
var index = 0;

function strIsEmpty(str) {
	return (str.length === 0 || !str.trim());
}
function check ()
{
	var task = document.getElementById('ft_list');
	task.innerHTML = decodeURIComponent(getCookie('todo'));
}

function getCookie(name)
{
	var nom = name + "=";
	var ca = document.cookie.split(';');
	for(var i=0; i<ca.length; i++)
	{
		var c = ca[i];
		while (c.charAt(0)==' ') c = c.substring(1);
		if (c.indexOf(nom) == 0) return c.substring(nom.length,c.length);
	}
	return "";
}

function setCookie(name, value, days)
{
	var d = new Date();
	d.setTime(d.getTime() + (days * 24 * 60 * 60 * 1000));
	var expires = "expires="+d.toUTCString();
	document.cookie = name + "=" + value + "; " + expires;
}

function todo()
{
	var taskText = prompt("Nouvelle tâche : ");
	if (!strIsEmpty(taskText)) 
    {
		var container = document.getElementById('ft_list');
		var h = document.createTextNode(taskText);	
		var div = document.createElement("div");
		div.appendChild(h);
		div.setAttribute("id", index)
		div.setAttribute("onclick", "del(this)")
		container.insertBefore(div, container.firstChild);
		date=new Date;
		date.setMonth(date.getMonth()+1);
		date = date.toUTCString();
		setCookie('todo', encodeURIComponent(container.innerHTML), 1);
		index++;
	}
}

function del(i)
{
	 if (confirm("Supprimer cette tâche ?")) 
	 { 
		var task = document.getElementById('ft_list');
		task.removeChild(i);
		setCookie('todo', encodeURIComponent(task.innerHTML), 1);
     }
}