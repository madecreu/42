#!/usr/bin/php
<?PHP
echo "Entrez un nombre: ";
while ($res = fgets(STDIN))
{
	$res = substr($res, 0, strlen($res)-1);
	if (is_numeric($res))
	{
		if ($res % 2 == 0)
			echo "Le chiffre " . $res . " est Pair\n";
		else
			echo "Le chiffre " . $res . " est Impair\n";
	}
	else
		echo "'$res' n'est pas un chiffre\n";
	echo "Entrez un nombre: ";
}
?>
