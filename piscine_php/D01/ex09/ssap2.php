#!/usr/bin/php
<?PHP
function ft_split($str)
{
	$tab = array_filter(explode(' ', $str));
	sort($tab);
	return $tab;
}

function my_sort($a, $b)
{
	$i = 0;
	$max = (strlen($a) > strlen($b) ? strlen($a) : strlen($b));
	$a = strtolower($a);
	$b = strtolower($b);
	while ($i < $max)
	{
		if ($a[$i] == $b[$i])
			$i++;
		else if (ctype_alpha($a[$i]) && ctype_alpha($b[$i]))
			return ($a[$i] < $b[$i] ? -1 : 1);
		else if (ctype_alpha($a[$i]))
			return (-1);
		else if (ctype_alpha($b[$i]))
			return 1;
		else if (is_numeric($a[$i]) && is_numeric($b[$i]))
			return ($a[$i] - $b[$i]);
		else if (is_numeric($a[$i]))
			return (-1);
		else if (is_numeric($b[$i]))
			return 1;
		else
			return ($a[$i] - $b[$i]);
	}
	return (0);
}

if ($argc > 1)
{
	$tab = array();
	foreach ($argv as $elem)
	{
		if ($elem != $argv[0])
			$tab = array_merge($tab, ft_split($elem));
	}
	usort($tab, "my_sort");
	foreach ($tab as $elem) 
		echo($elem . "\n");
}
?>