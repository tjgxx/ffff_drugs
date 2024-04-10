modded class HuntingKnife extends ToolBase
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
		// AddAction(ActionDisarmMine);
		// AddAction(ActionDisarmExplosive);
		// AddAction(ActionShave);
		// AddAction(ActionCraftBolts);
		AddAction(ActionHarvestMushroom);
	}
}