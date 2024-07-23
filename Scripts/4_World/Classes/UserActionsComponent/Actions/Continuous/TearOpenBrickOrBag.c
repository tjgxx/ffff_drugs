modded class ActionCP_RipOpenBrickOrBag : ActionContinuousBase
{	

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{

		if (item.IsKindOf("FFFF_Glow_Mushrooms_Brick_Base") || item.IsKindOf("FFFF_Glow_Mushrooms_Bag_Base"))
		{
			return false;
		};

		return super.ActionCondition( player, target, item );

	};

};


