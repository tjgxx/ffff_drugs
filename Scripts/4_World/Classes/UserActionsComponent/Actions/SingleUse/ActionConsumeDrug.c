class ActionConsumeDrugCB: ActionSingleUseBaseCB
{
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CASingleUseQuantityEdible(UAQuantityConsumed.DEFAULT);
	}
}
	
class ActionConsumeDrug : ActionSingleUseBase
{
    PlayerBase player;

    void ActionConsumeDrug()
    {
		m_CallbackClass = ActionConsumeDrugCB;
        m_Text = "#consume";
		m_CommandUID 		= DayZPlayerConstants.CMD_ACTIONMOD_LICKBATTERY;
		m_CommandUIDProne 	= DayZPlayerConstants.CMD_ACTIONFB_LICKBATTERY;
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{	
		if (player.m_IsOnShrooms) {
			return false;
		}

		return true;
	}

    override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

    override bool HasTarget()
	{
		return false;
	}

    override void OnEndServer( ActionData action_data )
	{
		PlayerBase player = action_data.m_Player;
		ItemBase item = ItemBase.Cast(action_data.m_MainItem);
		
		if (action_data.m_WasExecuted && item )
		{
            if (item.HasQuantity())
			{
				item.AddQuantity(-1, true);
			} else
			{
				item.Delete();
			}
		}

		action_data.m_Player.UpdateColdResistance(0.25);
        action_data.m_Player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_PAIN_LIGHT);
        action_data.m_Player.m_ModifiersManager.ActivateModifier(CustomModifiers.MDF_TRIPPING_MUSHROOM);
	}

}