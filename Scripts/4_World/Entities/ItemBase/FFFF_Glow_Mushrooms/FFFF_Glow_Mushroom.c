class FFFF_Glow_Mushroom_Base : ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionConsumeDrug);
	}
}