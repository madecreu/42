<?PHP
	if ($_POST['login'] && $_POST['oldpw'] && $_POST['newpw'] && $_POST['submit'] && $_POST['submit'] === "OK")
	{
		$data = unserialize(file_get_contents('../../private/passwd'));
		if ($data)
		{
			$exist = false;
			foreach ($data as $key => $value)
			{
				if ($value['login'] === $_POST['login'] && $value['passwd'] === hash('sha512', $_POST['oldpw']))
				{
					$exist = true;
					$data[$key]['passwd'] =  hash('sha512', $_POST['newpw']);
				}
			}
			if ($exist === true)
			{
				file_put_contents('../../private/passwd', serialize($data));
				echo "OK\n";
			}
			else
				echo "ERROR\n";
		}
		else
			echo "ERROR\n";
	} 
	else
		echo "ERROR\n";
?>