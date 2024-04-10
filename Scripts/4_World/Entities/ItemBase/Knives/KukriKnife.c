modded class KukriKnife extends ToolBase
{
	
	override void SetActions()
	{
		super.SetActions();
		
		// AddAction(ActionBurnSewTarget);
		// AddAction(ActionUnrestrainTarget);
		// AddAction(ActionSkinning);
		// AddAction(ActionMineBush);
		// AddAction(ActionMineTreeBark);
		// AddAction(ActionBurnSewSelf);
		// AddAction(ActionDigWorms);
		// AddAction(ActionShaveTarget);
		// AddAction(ActionShave);
		// AddAction(ActionCraftBolts);
		AddAction(ActionHarvestMushroom);
	}
}