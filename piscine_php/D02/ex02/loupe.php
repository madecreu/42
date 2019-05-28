#!/usr/bin/php
<?PHP
if ($argc == 2)
{
	$stdin = fopen($argv[1], 'r');
	while ($stdin && !feof($stdin))
	{
		$file = $file . fgets($stdin, 4096);
	}
	fclose($stdin);
	$res = preg_replace_callback("#(title).*?a>#", 
		function ($matches) {
            return preg_replace_callback("#[\"'].*?<#",
            	function ($matche) {
            		return strtoupper($matche[0]);
            	},
            	$matches[0]);
        },
        $file);
	$res = preg_replace_callback("#<a.*>[<\\n]#", 
		function ($matches) {
            return preg_replace_callback("#>.*?<#",
            	function ($matche) {
            		return strtoupper($matche[0]);
            	},
            	$matches[0]);
        },
        $res);
	echo $res . "\n";
}
?>