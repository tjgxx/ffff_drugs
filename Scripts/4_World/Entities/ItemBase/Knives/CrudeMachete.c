modded class CrudeMachete extends ToolBase
{
	
	override void SetActions()
	{
		super.SetActions();
		// AddAction(ActionUnrestrainTarget);
		// AddAction(ActionBurnSewTarget);
		// AddAction(ActionSkinning);
		// AddAction(ActionMineBush);
		// AddAction(ActionMineTreeBark);
		// AddAction(ActionBurnSewSelf);
		// AddAction(ActionDigWorms);
		// AddAction(ActionCraftBolts);
		AddAction(ActionHarvestMushroom);
	}
}