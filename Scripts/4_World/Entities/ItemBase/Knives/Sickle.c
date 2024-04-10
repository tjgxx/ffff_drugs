modded class Sickle extends ToolBase
{
	
	override void SetActions()
	{
		super.SetActions();
		
		// AddAction(ActionUnrestrainTarget);
		// AddAction(ActionMineBush);
		// AddAction(ActionSkinning);
		// AddAction(ActionMineTreeBark);
		// AddAction(ActionDigWorms);
		// AddAction(ActionShaveTarget);
		// AddAction(ActionShave);
		// AddAction(ActionCraftBolts);
		AddAction(ActionHarvestMushroom);
	}
}