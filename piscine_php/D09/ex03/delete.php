
<?php
$handle = fopen("list.csv", "r");
$data = array();
while (($line = fgetcsv($handle)) !== FALSE)
{
	array_push($data ,$line);
} 
$id = $_GET['id'];
unset($data[$id]);
print_r($data);
$file = file_get_contents("list.csv");
$i = 0;
$op = fopen("list.csv", "w");
if (substr_count($file, PHP_EOL) != 1)
{
$handle = "list.csv";
foreach ($data as $key => $value) {
	foreach ($value as $elem)
	{
		print($elem);  
		$var = explode(";", $elem);
		if (!($var[0] == $id))
		{                                                                                                                                                                                           
		file_put_contents($handle, $elem, FILE_APPEND);
		file_put_contents($handle, "\n", FILE_APPEND);
	}	}
}
	$i++;
}
?>
