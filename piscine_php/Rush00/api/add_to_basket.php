<?php

@session_start();
include_once(__DIR__ . "/../backend/general.php");

if (!isset($_SESSION) || !isset($_POST)) {
	header("Location: ../index.php");
	exit();
}
if (($data = file_to_data(__DIR__ . PRODUCT)) === FALSE){
	header("Location: ../index.php" . $_SESSION['current_page']);
	exit();
}
if (!isset($_SESSION['basket']) || !isset($_SESSION['total'])) {
	$_SESSION['total'] = 0;
	foreach ($data as $key => $value) {
		$_SESSION['basket'][preg_replace("#_#", " ", $key)] = 0;
	}
}
/*if (!isset($data[$_POST['product']])) {
	echo $_POST['product']."\n";
	header("Location: ../index.php" . $_SESSION['current_page']);
	exit();
}*/
foreach ($_POST as $key => $value)
{
		$_SESSION['basket'][preg_replace("#_#", " ", $key)]++;;
		$_SESSION['total'] += $data[preg_replace("#_#", " ", $key)]['price'];
}
/*while ($_POST['quantity'] && $data[$_POST['product']]['quantity']) {
	array_push ($_SESSION['basket'], $_POST['product']);
	$_POST['quantity']--;
	$_SESSION['total'] += $data[$_POST['product']]['price'];
	$data[$_POST['product']]['quantity']--;
}*/
/*header("Location: ../index.php" . $_SESSION['current_page']);*/
header("Location: ../index.php" . $_SESSION['current_page']);
?>
