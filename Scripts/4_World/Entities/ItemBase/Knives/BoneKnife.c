modded class BoneKnife extends ToolBase
{
	
	override void SetActions()
	{
		super.SetActions();
		
		// AddAction(ActionUnrestrainTarget);
		// AddAction(ActionSkinning);
		// AddAction(ActionMineBush);
		// AddAction(ActionMineTreeBark);
		// AddAction(ActionDigWorms);
		// AddAction(ActionCraftBolts);
		AddAction(ActionHarvestMushroom);
	}
}