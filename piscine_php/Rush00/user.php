<?php
include_once(__DIR__ . "/backend/general.php");
@session_start();
if ($_SESSION['group'] === "admin") {
	header("Location: admin.php");
}
?>
<!doctype html>
<html lang="fr">
	<head>
		<meta charset="utf-8">
		<title>42-games</title>
		<link rel="shortcut icon" href="img/manette_ico.ico">
		<meta name="description" content="42-games">
		<meta name="author" content="42">
		<link rel="stylesheet" href="css/styles.css">
		<link rel="stylesheet" href="css/main.css">
	</head>
	<body>
		<div class="header">
			<?php include("./header.php"); ?>
		</div>
		<div class="man-box center-box">
			<h1>Editer les informations</h1>
			<form action="api/update_infos.php" method="post" id="update">
				<?php echo "<h3>Account: ".$_SESSION['logged_on_user']."</h3>"?>
				<ul class="ul_line">
					<li class="list_line">
						<input type="text" name="new_pseudo" placeholder="Nouveau pseudo"required>
					</li>
					<li class="list_line">
						<input type="password" name="new_password" placeholder="Nouveau mot de passe"required>
					</li>
					<li>
						<input class="over-pointer valid_btn" type="submit" name="submit" value="Update Informations">
					</li>
				</ul>
			</form>
			<form action="api/delete_own_account.php" method="post">
				<input class="over-pointer clear_btn" type="submit" name="submit" value="Delete My Account">
			</form>
		</div>
	</body>
</html>
