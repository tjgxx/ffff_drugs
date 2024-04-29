class ActionConsumeDrugCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousQuantityEdible(UAQuantityConsumed.EAT_NORMAL,UATimeSpent.DEFAULT);
		
	}
};

class ActionConsumeDrug: ActionEatBig
{
	void ActionConsumeDrug()
	{
		m_CallbackClass = ActionConsumeDrugCB;
		m_Text = "#consume";
	}
			
	override void ApplyModifiers( ActionData action_data )
	{
		PlayerBase player = action_data.m_Player;
    	ItemBase item = ItemBase.Cast(action_data.m_MainItem);
		
		if (item.IsKindOf("FFFF_Glow_Mushroom_Base"))
		{
            action_data.m_Player.m_ModifiersManager.ActivateModifier(CustomModifiers.MDF_TRIPPING_MUSHROOM);
        }
	}
}
