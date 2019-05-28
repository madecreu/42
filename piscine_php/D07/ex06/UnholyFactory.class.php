<?php
class UnholyFactory
{
	public $army = array();
	public function absorb($arg)
	{
		if (get_parent_class($arg) == "Fighter")
		{
			if(!array_key_exists($arg->getType(), $this->army))
			{
				$this->army[$arg->getType()] = $arg;
				print("(Factory absorbed a fighter of type " . $arg->getType() . ")" . PHP_EOL);
			}
			else
			{
				print("(Factory already absorbed a fighter of type " . $arg->getType() . ")" . PHP_EOL);
			}
		}
		else
			print("(Factory can't absorb this, it's not a fighter)" . PHP_EOL);
	}
	public function fabricate($arg)
	{
		if (array_key_exists($arg, $this->army))
		{
			print("(Factory fabricates a fighter of type " . $arg . ")" . PHP_EOL);
			return $this->army[$arg];
		}
		else
			print("(Factory hasn't absorbed any fighter of type " . $arg . ")" . PHP_EOL);
	}
}
?>