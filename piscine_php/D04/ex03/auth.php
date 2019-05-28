<?PHP
	function auth($login, $passwd)
	{
		if (!$login || !$passwd)
			return false;
		$data = unserialize(file_get_contents('../../private/passwd'));
		if ($data)
		{
			foreach ($data as $key => $value)
			{
				if ($value['login'] === $login && $value['passwd'] === hash('sha512', $passwd))
					return true;
			}
		}
		return false;
	}
?>