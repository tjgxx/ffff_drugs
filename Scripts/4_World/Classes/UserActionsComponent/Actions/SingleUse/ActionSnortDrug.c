class ActionSnortDrugCB: ActionSingleUseBaseCB
{
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CASingleUseQuantityEdible(UAQuantityConsumed.DEFAULT);
	}
}
	
class ActionSnortDrug : ActionSingleUseBase
{
    PlayerBase player;

    void ActionSnortDrug()
    {
		m_CallbackClass = ActionSnortDrugCB;
        m_Text = "#snort";
		m_CommandUID 		= DayZPlayerConstants.CMD_ACTIONMOD_LICKBATTERY;
		m_CommandUIDProne 	= DayZPlayerConstants.CMD_ACTIONFB_LICKBATTERY;
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{	
		if (player.m_IsOnCocaine) {
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

    override void OnStartClient(ActionData action_data)
    {
        EffectSound sound = SEffectManager.PlaySound("CocaineSnort_SoundSet", action_data.m_Target.GetObject().GetPosition());
        sound.SetAutodestroy( true );
		
    }

    override void OnEndServer( ActionData action_data )
	{
		action_data.m_Player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_PAIN_LIGHT);
        action_data.m_Player.m_ModifiersManager.ActivateModifier(CustomModifiers.MDF_COCAINE_HIGH);

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
	}
}