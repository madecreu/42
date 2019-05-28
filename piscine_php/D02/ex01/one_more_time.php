#!/usr/bin/php
<?PHP
function month($str)
{
	if ($str == "janvier")
		return 1;
	else if ($str == "fevrier" || $str == "février")
		return 2;
	else if ($str == "mars")
		return 3;
	else if ($str == "avril")
		return 4;
	else if ($str == "mai")
		return 5;
	else if ($str == "juin")
		return 6;
	else if ($str == "juillet")
		return 7;
	else if ($str == "aout" || $str == "août")
		return 8;
	else if ($str == "septembre")
		return 9;
	else if ($str == "octobre")
		return 10;
	else if ($str == "novembre")
		return 11;
	else
		return 12;
}

if ($argc == 2)
{
	if (preg_match("#(?<!\s)([lL]undi|[Mm]ardi|[Mm]ercredi|[Jj]eudi|[Vv]endredi|[Ss]amedi|[Dd]imanche) [0-9]{1,2} ([Jj]anvier|[Ff][ée]vrier|[Mm]ars|[Aa]vril|[Mm]ai|[Jj]uin|[Jj]uillet|[Aa]o[uû]t|[Ss]eptembre|[Oo]ctobre|[Nn]ovembre|[Dd][ée]cembre) [0-9]{4} ([0-9]{2}:){2}[0-9]{2}(?!\s)#", $argv[1]))
	{
		date_default_timezone_set('Europe/Paris');
		$tab_date = preg_replace("#\:+#", " ", $argv[1]);
		$tab_date = explode(" ", $tab_date);
		$month = month(strtolower($tab_date[2]));
		echo (mktime(intval($tab_date[4]), intval($tab_date[5]), intval($tab_date[6]), $month, intval($tab_date[1]), intval($tab_date[3])) . "\n");
	}
	else
		echo "Wrong Format\n";
}
?>
