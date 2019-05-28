#!/usr/bin/php
<?PHP
	date_default_timezone_set('Europe/Paris');
	if ($f = fopen("/var/run/utmpx", "r")) {
    $users = [];
    while ($line = fread($f, 628))
    {
        $tab = unpack("a256/a4id/a32line/ipid/itype/I2time", $line);
        if($tab['type'] == 7)
        	$users[] = $tab;
   }
   foreach ($users as $elem)
   {
   		echo $elem['1'] . " " . $elem['line'] . "  " . date('M d G:i', $elem['time1']) . "\n";
   }
}
?>