<?php @session_start();

include_once ("./backend/general.php");
$_SESSION['current_page'] = "";
if ($_GET)
{
	if (($_GET['type'] === "category" || $_GET['type'] === "product") && $_GET['id'])
	{
		$type = $_GET['type'];
		if (($tmp = file_to_data("./private/category")) === false)
		{
			header("Location: /index.php");
			exit ;
		}
		$cat_list = array();
		foreach ($tmp as $key => $value)
			$cat_list[] = $key;
		if (!$cat_list || !in_array($_GET['id'], $cat_list) || !$tmp[$_GET['id']]['visible'])
		{
			header("Location: /index.php");
			exit ;
		}
		$id = $_GET['id'];
		$_SESSION['current_page'] = "?type=".$_GET['type']."&id=".$_GET['id'];
	}
	else
	{
		$_GET['type'] = "all";
	}
}
else
{
	$_GET['type'] = "all";
}
?>
<!DOCTYPE html>
<html lang="fr">
<head>
<meta charset="utf-8">
<title>42-Games</title>
<link rel="shortcut icon" href="img/manette_ico.ico">
<meta name="description" content="Boutique officielle de 42-games">
<meta name="author" content="42-games">
<link rel="stylesheet" href="./css/main.css">
<link rel="stylesheet" href="css/styles.css">
</head>
<body>
<div class="header">
<?php
include("./header.php");
?>
</div>
<div class="main-right-menu">
<?PHP
if ($_GET['type'] !== "all")
{
	echo "<ul class=\"menu-ul\">";
	echo "<a href=\"index.php\"><li class=\"category\">Voir les catégories</li></a>";
	echo "</ul>";
}
?>
<h2>Toutes les catégories</h2>
<ul class="menu-ul">
<?php
$type = "category";
include ("./backend/templates/list_of_categories.php");
?>
</ul>
<?PHP
if ($_GET['type'] === "all")
{
	echo "<ul class=\"menu-ul\">";
	$type = "product";
	include ("./backend/templates/list_of_categories.php");
	echo "</ul>";
}
else
{
	echo "<h2>".$_GET['id']." Games</h2>";
	echo "<ul class=\"menu-ul\">";
	$type = "product";
	include ("./backend/templates/list_of_categories.php");
	echo "</ul>";
}
?>
</div>
<div class="main-container">
<table>
<tr>
<td><center><img src="img/state_of_decay_2.jpg" alt="jeu_stateofdecay2" style="width:150px;height:250px;"></td>
<td><img src="img/farcry5.jpg" alt="jeu_farcry5" style="width:150px;height:250px;"></center></td>
<td><img src="img/battlefield 5.jpg" alt="logo_manette" style="width:150px;height:250px;"></td>
<td><img src="img/steep.jpeg" alt="logo_manette" style="width:150px;height:250px;"></td>
<td><img src="img/tropico 6.jpg" alt="logo_manette" style="width:150px;height:250px;"></td>
<td><img src="img/fornite.jpg" alt="logo_manette" style="width:150px;height:250px;"></td>
</tr>
<form action="api/add_to_basket.php" method="post">
<?PHP
if (($data = file_to_data("./private/product")) === false)
{
	header("Location: /index.php");
	exit ;
}
foreach ($data as $key => $value)
{
	echo("<td><center><input type=\"submit\" class=\"game_name\" name=\"" . preg_replace("#_#", " ", $key) . "\" value=\"" . preg_replace("#_#", " ", $key) . "\"/><center></td>");
}
?>
</form>
</table>
</div>

<div class="footer">
<h6>&copy 42-games 2018</h6>
</div>
</body>
</html>
