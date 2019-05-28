#!/usr/bin/php
<?PHP
function ft_split($str)
{
	$tab = array_filter(explode(' ', $str));
	sort($tab);
	return $tab;
}

if ($argc > 1)
{
	$tab = array();
	foreach ($argv as $elem)
	{
		if ($elem != $argv[0])
			$tab = array_merge($tab, ft_split($elem));
	}
	sort($tab);
	foreach ($tab as $elem)
		echo $elem . "\n";
}
?>