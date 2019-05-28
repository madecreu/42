<?php @session_start(); ?>
<html>
<body>
  <header>
	<div class="navbar">
	  <a class="active" href="/index.php">
			<ul class="ul_line">
				<li class="list_line"><img id="logo" src=/img/manette.jpg></li>
				<li class="list_line" id="brand">42-games</li>
			</ul>
		</a>
	    <?php
	    if (isset($_SESSION)) {
	        switch ($_SESSION['group']) {
	        case "admin":
	            echo '<a class="btn" style="float:right" href="/admin.php">'."Administrator".'</a>';
	            echo '<a class="btn" style="float:right" href="/api/logout.php">'.'Logout'.'</a>';
	            break;
	        case "client":
							if ($_SESSION['total'])
							{
	            	echo "<a class=\"btn\" style=\"float:right\" href=\"/panier.php\">
								<ul class=\"ul_line\">
									<li class=\"list_line\"><img id=\"basket\" src=\"/img/panier1.png\" height=\"20px\"></li>
									<li class=\"list_line\">Panier (".$_SESSION['total']." €)</li>
								</ul></a>";
							}
							else
							{
								echo "<a class=\"btn\" style=\"float:right\" href=\"/panier.php\">
								<ul class=\"ul_line\">
									<li class=\"list_line\"><img id=\"basket\" src=\"/img/panier1.png\" height=\"20px\"></li>
									<li class=\"list_line\">Panier (0 €)</li>
								</ul></a>";
							}
	            echo "<a class=\"btn\" style=\"float:right\" href=\"/user.php\">".$_SESSION['logged_on_user']."</a>";
	            echo '<a class="btn" style="float:right" href="/api/logout.php">'.'Logout'.'</a>';
	            break;
	        case "":
							if ($_SESSION['total'])
							{
								echo "<a class=\"btn\" style=\"float:right\" href=\"/panier.php\">
								<ul class=\"ul_line\">
									<li class=\"list_line\"><img id=\"basket\" src=\"/img/panier1.png\" height=\"20px\"></li>
									<li class=\"list_line\">Panier (".$_SESSION['total']." €)</li>
								</ul></a>";
							}
							else
							{
								echo "<a class=\"btn\" style=\"float:right\" href=\"/panier.php\">
								<ul class=\"ul_line\">
									<li class=\"list_line\"><img id=\"basket\" src=\"/img/panier1.png\" height=\"20px\"></li>
									<li class=\"list_line\">Panier (0 €)</li>
								</ul></a>";
							}
	            echo '<a class="btn" style="float:right" href="/login.php">'.'Se connecter'.'</a>';
	            echo '<a class="btn" style="float:right" href="/register.php">'."S'inscrire".'</a>';
	        }
	    }
	    ?>
	</div>
  </header>
</div>
  <script src="js/script.js"></script>
</body></html>
