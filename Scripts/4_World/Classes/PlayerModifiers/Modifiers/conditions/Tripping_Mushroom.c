class TrippingMushroomsMdfr: ModifierBase
{
	int m_Delay = 30;
    int m_Lifetime = 600;
    static const int AGENT_THRESHOLD_ACTIVATE = 150;

	private float m_TimeSinceLastEvent = 0.0;
	private float m_NextEvent;
    private int m_RandomSymptomChance;
    
    static const float EVENT_INTERVAL_MIN = 24;
	static const float EVENT_INTERVAL_MAX = 36;

    // static const int YAWN_OCCURRENCES_PER_HOUR_MIN = 60;
	// static const int YAWN_OCCURRENCES_PER_HOUR_MAX = 120;

	override void Init()
	{
		m_TrackActivatedTime = true;
		m_IsPersistent = true;
		m_ID 					= CustomModifiers.MDF_TRIPPING_MUSHROOM;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE_SHORT;
        DisableActivateCheck();
	}

    override bool ActivateCondition(PlayerBase player)
	{
		if	(player.GetSingleAgentCount(CustomAgents.TRIPPING_MUSHROOM) >= AGENT_THRESHOLD_ACTIVATE) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

    override string GetDebugText()
	{
		return (m_Lifetime - GetAttachedTime()).ToString();
	}
	
	override void OnActivate(PlayerBase player)
	{
        if (player.GetModifiersManager().IsModifierActive(CustomModifiers.MDF_TRIPPING_MUSHROOM)) {
		   player.GetSymptomManager().RemoveSecondarySymptom(CustomSymptomIDs.SYMPTOM_TRIPPING_MUSHROOMS);
        }
		player.GetSymptomManager().QueueUpSecondarySymptom(CustomSymptomIDs.SYMPTOM_TRIPPING_MUSHROOMS);
	}

    override void OnTick(PlayerBase player, float deltaTime)
    {
		float m_TimeSpentHighMinusDelay = GetAttachedTime() - m_Delay;

		if (m_TimeSpentHighMinusDelay >= m_Delay)
		{
			m_TimeSinceLastEvent += deltaT;
	
			if ( m_TimeSinceLastEvent >= m_NextEvent )
			{
				m_TimeSinceLastEvent = 0;
				m_NextEvent = Math.RandomFloatInclusive( EVENT_INTERVAL_MIN, EVENT_INTERVAL_MAX );
				
				m_RandomSymptomChance = Math.RandomInt( 0, 10 );

				if (m_RandomSymptomChance >= 0 && m_RandomSymptomChance < 3)
				{
					player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_LAUGHTER);
				} 
				else if (m_RandomSymptomChance >= 3 && m_RandomSymptomChance < 7)
				{
					player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_HOT);
				} 
				else if (m_RandomSymptomChance >= 7 && m_RandomSymptomChance < 9)
				{
					player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_FREEZE);
				}
			}
		}
    }
	
	override void OnReconnect(PlayerBase player)
	{
		this.OnActivate(player);
	}
	
	override void OnDeactivate(PlayerBase player)
	{
		player.GetSymptomManager().RemoveSecondarySymptom(CustomSymptomIDs.SYMPTOM_TRIPPING_MUSHROOMS);
	}

	override bool DeactivateCondition(PlayerBase player)
	{
        float m_TimeSpentHighMinusDelay = GetAttachedTime() - m_Delay;
		if ( m_TimeSpentHighMinusDelay >= m_Lifetime )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
