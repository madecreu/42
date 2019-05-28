#!/usr/bin/php
<?PHP
if ($argc == 2)
	echo (trim(preg_replace('/\s\s+/', ' ', $argv[1])) . "\n");
?>