<?php
include_once(__DIR__ . "/backend/general.php");
@session_start();
if ($_SESSION['group'] === "admin") {
	header("Location: admin.php");
}
?>
<!doctype html>
<html lang="en">
	<head>
		<meta charset="utf-8">
		<title>42-games</title>
		<link rel="shortcut icon" href="img/manette_ico.ico">
		<meta name="description" content="42-Games">
		<meta name="author" content="42">
		<link rel="stylesheet" href="/css/styles.css">
		<link rel="stylesheet" href="/css/main.css">
	</head>
	<body>
		<div class="header">
			<?php include("./header.php"); ?>
		</div>
		<div class="man-box center-box">
			<?php
			$product = file_to_data(__DIR__ . "/private/product");
			echo '<h2> Panier </h2>';
			echo '<hr><br>';
			if (!empty($_SESSION['basket'])) {
				foreach ($_SESSION['basket'] as $p => $val) {
					if (!isset($product[$p]) || $val == 0) continue;
					echo "<div class=\"textbox\">";
					echo "<div class=\"left\">Jeu: <strong>".$p."</strong></div>";
					echo "<div class=\"right\">Quantité: ".$_SESSION['basket'][$p] ." </div><br>";
					echo "<div class=\"right\">Prix: <i>".$product[$p]['price'] * $val ."</i> €</div><br>";
					echo "</div><br>";
				}
			} else {
				echo '<p>Votre panier est vide</p>';
			}
			echo '<br><hr>';
			echo '<center>Total: '.$_SESSION['total'].'€<center>';
			?>

			<div class="">
				<ul class="ul_line">
					<li class="list_line">
						<form action="/api/place_order.php" method="post" id="buy">
							<input class="over-pointer valid_btn" type="submit" name="submit" value="Acheter">
						</form>
					</li>
					<li class="list_line">
						<form action="/api/cancel_basket.php" method="post" id="buy">
							<input class="over-pointer clear_btn" type="submit" name="submit" value="Supprimer le panier">
						</form>
					</li>
				</ul>
			</div>
		</div>
	</body>
</html>
