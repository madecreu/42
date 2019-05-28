#!/usr/bin/php
<?PHP
if ($argc > 1)
{
	$str = trim(preg_replace('/\s\s+/', ' ', $argv[1]));
	$tab = explode(' ', $str);
	foreach ($tab as $elem)
	{
		if ($elem != $tab[0])
			echo ($elem . " ");
	}
	echo ($tab[0] . "\n");
}
?>