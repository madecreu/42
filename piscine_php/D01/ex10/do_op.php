#!/usr/bin/php
<?PHP
if ($argc != 4)
	echo ("Incorrect Parameters\n");
else
{
	$argv[2] = trim($argv[2]);
	$argv[1] = trim($argv[1]);
	$argv[3] = trim($argv[3]);
	if ($argv[2] == "+")
		$res = $argv[1] + $argv[3];
	else if ($argv[2] == "-")
		$res = $argv[1] - $argv[3];
	else if ($argv[2] == "*")
		$res = $argv[1] * $argv[3];
	else if ($argv[2] == "/")
		$res = $argv[1] / $argv[3];
	else if ($argv[2] == "%")
		$res = $argv[1] % $argv[3];
	echo ($res . "\n");
}
?>