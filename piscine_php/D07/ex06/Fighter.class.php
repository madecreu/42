<?php
class Fighter
{
	protected $type;

	protected function __construct($arg)
	{
		$this->type = $arg;
	}
	public function getType()
	{
		return ($this->type);
	}
}
?>