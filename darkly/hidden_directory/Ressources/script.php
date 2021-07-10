<?php
function script($link) 
{
    static $array = [];
    $content = file_get_contents($link);
    preg_match_all('/<a href="(.+)">/', $content, $matches);
    $urls = $matches[1];
    foreach($urls as $url) {
        if ($url == '../')
            continue;
        if ($url == 'README') {
            $content = trim(file_get_contents($link . $url));
            if (!in_array($content, $array)) {
                $array[$content] = $content;
                echo $content . "\n";
            }
        } else {
            script($link . $url);
        }
    }
}
script('http://10.11.200.18/.hidden/');
