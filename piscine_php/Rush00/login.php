<?php @session_start(); ?>


<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>Se connecter</title>
		<link rel="shortcut icon" href="img/manette_ico.ico">
		<link rel="stylesheet" type="text/css" href="css/styles.css"/>
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
				<h1>Se connecter</h1>
				<p>Bonjour,</p>
				<p>Heureux de vous revoir !</p>
				<br>
				<?php
				if ($_SESSION['error'])
					echo "<p>" . $_SESSION['error'] . "</p>\n";
				$_SESSION['error'] = "";
				?>
				<form class="login-form" method="post" action="api/login.php">
					<input type="text" placeholder="Identifiant" name="username" id="username" required/>
					<input type="password" placeholder="Mot de passe" name="password" id="password" required/>
					<button>S'identifier</button>
					<p class="message">Pas encore inscrit ? <a href="register.php">Créer un compte</a></p>
				</form>
			</div>
		</div>
	</body>
</html>
