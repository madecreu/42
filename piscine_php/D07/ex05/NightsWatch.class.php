<?php
Class NightsWatch
{
	private $fighters = array();
	public function recruit($arg)
	{
		$this->fighters[] = $arg;
	}
	public function fight()
	{
		foreach($this->fighters as $elem)
			if (method_exists($elem, 'fight'))
				$elem->fight();
	}
}
?>