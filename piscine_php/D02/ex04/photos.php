#!/usr/bin/php
<?PHP
if ($argc == 2)
{
	$curl = curl_init();
	curl_setopt($curl, CURLOPT_URL, $argv[1]);
	curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);
	$file = curl_exec($curl);
	curl_close($curl);
	$res = preg_split("#\n#", $file);
	foreach ($res as $elem) 
	{
		if (strstr($elem, "<img"))
			$tab_tmp[] = $elem;
	}
	if (empty($tab_tmp))
		exit();
	foreach ($tab_tmp as $elem)
	{
		$tab[] = explode('"', $elem);
	}
	foreach ($tab as $elem)
	{
		foreach ($elem as $exploded) 
		{
			if (strstr($exploded, "http"))
			{	
				if (strstr($exploded, "?"))
				{
					$tempory = explode("?", $exploded);
					$final_tab[] = $tempory[0];
				}
				else
				{
					$final_tab[] = $exploded;
				}
			}	
		}
	}
	$name = explode("/", $argv[1]);
	if (strstr($name[0], "http"))
		$name[0] = $name[2];
	if (!empty($final_tab))
	{
		if (!is_dir($name[0]))
		{
			echo $name[0] . "\n";
			mkdir("./$name[0]", 0700);
		}
		foreach ($final_tab as $elem) 
		{
			$name_file = preg_replace("#.*\/#", '', $elem);
			echo exec('curl ' . $elem . ' > ' . $name[0] . '/' . $name_file);
		}
	}
}
?>
