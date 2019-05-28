<?PHP
	if ($_POST['submit'] == "OK")
	{
		if (file_exists("../../private") === false)
		{
			mkdir("../../private");
		}
		if (file_exists("../../private/passwd") === false)
		{
			if ($_POST['login'] != "" && $_POST['passwd'] != "")
			{
				$data = array(array("login" => $_POST['login'], "passwd" => hash("sha512", $_POST['passwd'])));
				file_put_contents("../../private/passwd", serialize($data));
				echo "OK\n";
			}
			else
				echo ("ERROR\n");
		}
		else
		{
			if ($_POST['login'] != "" && $_POST['passwd'] != "")
			{
				$exist = -1;
				$data = unserialize(file_get_contents("../../private/passwd"));
				foreach ($data as $elem)
				{
					if ($elem['login'] == $_POST['login'])
						$exist = 1;
				}
				if ($exist == -1)
				{
					$data[] = array("login" => $_POST['login'], "passwd" => hash("sha512", $_POST['passwd']));
					file_put_contents("../../private/passwd", serialize($data));
					echo "OK\n";
				}
				else
					echo "ERROR\n";
			}
			else
				echo "ERROR\n";
		}
	}
	else
		echo ("ERROR\n");
?>