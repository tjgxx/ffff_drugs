class FFFF_Glow_Mushroom_Base : Edible_Base
{
	void FFFF_Glow_Mushroom_Base()
	{
	
	}
	
	override bool CanBeCooked()
	{
		return false;
	}		
	
	override bool CanBeCookedOnStick()
	{
		return false;
	}
	
	override bool IsMeat()
	{
		return false;
	}
	
	override bool CanDecay()
	{
		return false;
	}

	override void OnConsume(float amount, PlayerBase consumer)
	{
		consumer.GetModifiersManager().ActivateModifier(CustomModifiers.MDF_TRIPPING_MUSHROOM);
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionEatBig);
		AddAction(ActionForceFeed);
	}
}