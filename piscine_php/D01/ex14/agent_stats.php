#!/usr/bin/php
<?php

if (posix_isatty(STDIN))
	exit();
if ($argc == 2)
{
    $userTab = [];
    $stdin = fopen('php://stdin', 'r');
    fgets($stdin);
    while ($stdin && !feof($stdin))
    {
        $tmp = explode(";", fgets($stdin));
        if (count($tmp) == 4)
        {
            $line[] = $tmp;
            if (!array_key_exists($tmp[0], $userTab))
            {
                $userTab[$tmp[0]] = null;
                $userTab[$tmp[0]]['totalNotes'] = 0;
                $userTab[$tmp[0]]['nbNotes'] = 0;
                $userTab[$tmp[0]]['moulinette'] = 0;
            }
        }
    }
    ksort($userTab);
    if ($argv[1] === "moyenne")
    {
        $totalNotes = 0;
        $nbNotes = 0;
        foreach ($line as $elem)
        {
            if ($elem[2] !== "moulinette" && $elem[1] !== '')
            {
                $nbNotes++;
                $totalNotes += $elem[1];
            }
        }
        echo ($totalNotes / $nbNotes) . "\n";
    }
    else if ($argv[1] === "moyenne_user" || $argv[1] === "ecart_moulinette")
    {
        foreach ($line as $elem)
        {
            if ($elem[1] !== '' && $elem[2] !== "moulinette")
            {
                $userTab[$elem[0]]['nbNotes'] += 1;
                $userTab[$elem[0]]['totalNotes'] += $elem[1];
            }
            else if ($elem[1] != '' && $elem[2] === "moulinette")
                $userTab[$elem[0]]['moulinette'] = $elem[1];
        }
        foreach ($userTab as $k => $elem)
        {
            if ($argv[1] === "ecart_moulinette")
                echo $k . ":" . (($elem['totalNotes'] / $elem['nbNotes']) - $elem['moulinette']) . "\n";
            else
                echo $k . ":" . ($elem['totalNotes'] / $elem['nbNotes']) . "\n";
        }
    }
}
?>
