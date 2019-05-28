<?php

//include(__DIR__ . "/general.php");
define("PASSWD", "/../private/passwd");
define("PRODUCT", "/../private/product");
define("CATEGORY", "/../private/category");
define("ORDER", "/../private/order");

function file_to_data2($file) {
	if (!file_exists($file))
		return FALSE;
	if (($content = @file_get_contents($file)) === FALSE)
		return FALSE;
	if (($data = @unserialize($content)) === FALSE)
		return FALSE;
	return $data;
}

function data_to_file2($data, $file) {
	if (($content = @serialize($data)) === FALSE)
		return FALSE;
	if (@file_put_contents($file, $content, LOCK_EX) === FALSE)
		return FALSE;
	return TRUE;
}




function add_user($login, $passwd, $group) {
	if (!$login || !$passwd || !$group)
		return FALSE;
	if (($data = file_to_data2(__DIR__ . PASSWD)) === FALSE || isset($data[$login]))
		return FALSE;
	$data[$login] = array();
	$data[$login]['passwd'] = hash("whirlpool", $passwd);
	$data[$login]['group'] = $group;
	if (data_to_file2($data, __DIR__ . PASSWD) === FALSE)
		return FALSE;

	return TRUE;
}

function auth($login, $passwd) {
	if ($login == "" || $passwd == "")
		return FALSE;
	if (($data = file_to_data2(__DIR__ . PASSWD)) === FALSE)
		return FALSE;
	$passwd = hash("whirlpool", $passwd);
	if ($data[$login]['passwd'] === $passwd)
		return TRUE;
	else
		return FALSE;
}

function remove_user($login) {
	if ($login == "")
		return FALSE;
	if (($data = file_to_data2(__DIR__ . PASSWD)) === FALSE)
		return FALSE;
	unset($data[$login]);
	if (data_to_file2($data, __DIR__ . PASSWD) === FALSE)
		return FALSE;
	return TRUE;
}

function modif_pwd($login, $oldpwd, $newpwd) {
	if ($login == "" || $oldpwd == "" || $newpwd == "")
		return FALSE;
	if (($data = file_to_data2(__DIR__ . PASSWD)) === FALSE || !isset($data[$login]) || !isset($data[$login]['passwd']))
		return FALSE;
	$oldpwd = hash("whirlpool", $oldpwd);
	if ($data[$login]['passwd'] !== $oldpwd)
		return FALSE;
	$data[$login]['passwd'] = hash("whirlpool", $newpwd);
	if (data_to_file2($data, __DIR__ . PASSWD) === FALSE)
		return FALSE;
	return TRUE;
}

function get_user_group($login) {
	if (!$login || $login == "") {
		return (null);
	}
	if (($data = file_to_data2(__DIR__ . PASSWD)) === FALSE)
		return FALSE;
	if (isset($data[$login]))
		return $data[$login]['group'];
	return FALSE;
}

?>
