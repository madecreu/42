<?PHP
	include_once __DIR__.'/database.php';

	add_product("State of Decay 2", 20, 5, "../img/state_of_decay_2.jpg", true, true);
	add_product("Far cry 5", 20, 5, "../img/farcry5.jpg", true, true);
	add_product("Battlefield 5", 20, 5, "../img/battlefield 5.jpg", true, true);
	add_product("Steep", 20, 5, "../img/steep.jpeg", true, true);
	add_product("Tropico 6", 20, 5, "../img/tropico 6.jpg", true, true);
	add_product("Fornite", 20, 5, "../img/fornite.jpg", true, true);

	echo "6 produits créés\n";

	add_product_to_category("Action", "State of Decay 2");
	add_product_to_category("Action", "Far cry 5");
	add_product_to_category("Action", "Battlefield 5");
	add_product_to_category("Sport", "Steep");
	add_product_to_category("Gestion", "Tropico 6");
	add_product_to_category("BattleRoyal", "Fornite");

	echo "Produits ajoutés aux catégories\n";
?>
