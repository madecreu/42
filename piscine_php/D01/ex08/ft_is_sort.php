#!/usr/bin/php
<?PHP
function ft_is_sort($tab)
{
	$sort = $tab;
	sort($sort);
	$rsort = $tab;
	rsort($rsort);
	$res1 = array_diff_assoc($tab, $sort);
	$res2 = array_diff_assoc($tab, $rsort);
	return (empty($res1) || empty($res2) ? true : false);
}
?>
