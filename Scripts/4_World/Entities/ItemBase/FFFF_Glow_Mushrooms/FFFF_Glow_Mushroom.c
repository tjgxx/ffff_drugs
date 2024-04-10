class FFFF_Glow_Mushroom_Base : MushroomBase
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionCreateIndoorFireplace);
		AddAction(ActionCreateIndoorOven);
	}
}