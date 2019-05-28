#!/usr/bin/php
<?PHP
	if ($argc > 2)
	{
		$tab = array();
		foreach ($argv as $elem) 
		{
			if ($elem != $argv[0] && $elem != $argv[1])
			{
				$tmp = explode(":", $elem);
				if (count($tmp) == 2)
					$tab[$tmp[0]] = $tmp[1];
				unset($tmp); 
			}
		}
		if (array_key_exists($argv[1], $tab))
			echo $tab[$argv[1]] . "\n";
	}
?>