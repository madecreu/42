#!/usr/bin/php
<?PHP
if ($argc != 2)
	echo ("Incorrect Parameters\n");
else
{
	$argv[1] = preg_replace('/\s+/', '', $argv[1]);
	if (strpos($argv[1], "+") != false)
	{
		$tab = preg_split("/[+]+/", $argv[1]);;
		if (count($tab) != 2 || is_numeric($tab[0]) == false || is_numeric($tab[1]) == false)
			echo("Syntax Error\n");
		else
			echo (($tab[0] + $tab[1]) . "\n");
	}
	else if (strpos($argv[1], "-", 1) != false)
	{
		$tab = preg_split("/[\-]+/", $argv[1]);
		if (count($tab) == 3)
		{
			$useless = array_shift($tab);
			$tab[0] *= -1;
		}
		if (count($tab) != 2 || is_numeric($tab[0]) == false || is_numeric($tab[1]) == false)
			echo("Syntax Error\n");
		else
			echo (($tab[0] - $tab[1]) . "\n");
	}
	else if (strpos($argv[1], "*") != false)
	{
		$tab = preg_split("/[*]+/", $argv[1]);
		if (count($tab) != 2 || is_numeric($tab[0]) == false || is_numeric($tab[1]) == false)
			echo("Syntax Error\n");
		else
			echo (($tab[0] * $tab[1]) . "\n");
	}
	else if (strpos($argv[1], "/") != false)
	{
		$tab = preg_split("/[\/]+/", $argv[1]);
		if (count($tab) != 2 || is_numeric($tab[0]) == false || is_numeric($tab[1]) == false)
			echo("Syntax Error\n");
		else if ($tab[1] == 0)
			echo "Calcul Error : Divide by 0\n";
		else
			echo (($tab[0] / $tab[1]) . "\n");
	}
	else if (strpos($argv[1], "%") != false)
	{
		$tab = preg_split("/[\%]+/", $argv[1]);
		if (count($tab) != 2 || is_numeric($tab[0]) == false || is_numeric($tab[1]) == false)
			echo("Syntax Error\n");
		else if ($tab[1] == 0)
			echo "Calcul Error : Divide by 0\n";
		else
			echo (($tab[0] % $tab[1]) . "\n");
	}
	else
		echo("Syntax Error\n");
}
?>
