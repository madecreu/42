<?PHP

	include __DIR__."/backend/general.php";

	data_to_file(array(), __DIR__."/private/category");
	data_to_file(array(), __DIR__."/private/product");

	echo "DB effacée\n";
?>
