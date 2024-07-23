class ActionInjectDrugSelfCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.COLLECT_SAMPLE);
	}
};

class ActionInjectDrugSelf: ActionContinuousBase
{
	void ActionInjectDrugSelf()
	{
		m_CallbackClass = ActionInjectDrugSelfCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_COLLECTBLOODSELF;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_MEDIUM;
		m_Text = "Inject";
	}
	
	override void CreateConditionComponents()  
	{		
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}

	override bool HasTarget()
	{
		return false;
	}

    override void OnEndAnimationLoopServer( ActionData action_data )
	{
		if ( action_data.m_MainItem.IsKindOf("FFFF_HeroinSyringe") )
		{
			SyringeLambda lambda = new SyringeLambda(action_data.m_MainItem, "Syringe", action_data.m_Player);
			MiscGameplayFunctions.TurnItemIntoItemEx(action_data.m_Player, lambda);
		}
		
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
	

	override void OnFinishProgressServer( ActionData action_data )
	{
		action_data.m_Player.SetHealth("","Shock",70);
	}
};
