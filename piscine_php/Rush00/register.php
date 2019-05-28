<?php @session_start(); ?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>S'inscrire</title>
		<link rel="shortcut icon" href="img/manette_ico.ico">
		<link rel="stylesheet" type="text/css" href="./css/styles.css"/>
		<link rel="stylesheet" href="./css/main.css">
	</head>
	<body>
		<div class="header">
			<?php
			  include("./header.php");
			?>
		</div>
		<div class="login-page">
			<div class="form">
				<center><img src="img/manette2.png" alt="logo_manette" style="width:120px;height:100px;"></center>
				<h1>Créer un compte</h1>
				<p>Bienvenue sur 42-games</p>
				<br>
				<?php

				if ($_SESSION['error'])
					echo "<p>" . $_SESSION['error'] . "</p>\n";
				$_SESSION['error'] = "";

				?>
				<form class="login-form" method="post" action="api/register.php">
					<input type="text" placeholder="Identifiant" name="username" id="username" required/>
					<input type="password" placeholder="Mot de passe" name="password" id="password" required/>
					<button>S'inscrire</button>
					<p class="message"> <a href="login.php">Déjà inscrit ?</a></p>
				</form>
			</div>
		</div>
	</body>
</html>
