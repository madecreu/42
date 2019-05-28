var i = 0;
function strIsEmpty(str) {
	return (str.length === 0 || !str.trim());
}
$(document).ready(function(){
 	$.ajax({
        	url : 'select.php',
        	type : 'GET',
        	dataType : 'json',
        	success : function(code_html, statut){
        		var o = 0;
        		while (code_html[o])
        		{
        			var split = code_html[o].split(";");
	           		var id = split[0];
	           		var tak = split[1];
        			$("#ft_list").prepend("<div onclick=del(this) id="+id+">"+tak+"</div>");
        			o++;
        			i++;
        		}
	       }
		})	       
    $("#new").click(function(){
    	
    	var taskText = prompt("Nouvelle tâche : ");
    	if (!strIsEmpty(taskText)) 
    	{
        $.ajax({
        	url : 'insert.php',
        	type : 'GET',
        	data : 'id='+ i +'& task='+taskText,
        	dataType : 'html',
        	success : function(code_html, statut){
	           var split = code_html.split("-");
	           var id = split[0];
	           var tak = split[1];
	           $("#ft_list").prepend("<div onclick=del(this) id="+id+">"+tak+"</div>");
	       }



        });
		i++;}
    });
});