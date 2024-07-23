class CocaineHighMdfr: ModifierBase
{
    int m_Lifetime = 120;
    static const int AGENT_THRESHOLD_ACTIVATE = 150;

	private float m_TimeSinceLastEvent = 0.0;
	private float m_NextEvent;
    private int m_RandomSymptomChance;
	
    static const float EVENT_INTERVAL_MIN = 24;
	static const float EVENT_INTERVAL_MAX = 36;

	private float m_EnergyAtStart;
	private float m_WaterAtStart;

	override void Init()
	{
		m_TrackActivatedTime = true;
		m_IsPersistent = true;
		m_ID 					= CustomModifiers.MDF_COCAINE_HIGH;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE_SHORT;
		m_SyncID				= CustomModifierSyncIDs.MODIFIER_SYNC_COCAINE_HIGH;
        DisableActivateCheck();
	}
	
    override bool ActivateCondition(PlayerBase player)
	{
		return true;
	}

    override string GetDebugText()
	{
		return (m_Lifetime - GetAttachedTime()).ToString();
	}

	bool SecondarySymptomIsInQueue(PlayerBase player, int symptom_id)
	{
		for (int i = 0; i < player.GetSymptomManager().m_SymptomQueueSecondary.Count();i++)
		{
			if ( player.GetSymptomManager().m_SymptomQueueSecondary.Get(i) && player.GetSymptomManager().m_SymptomQueueSecondary.Get(i).GetType() == symptom_id )
			{
				return true;
			}
		}

		return false;
	}

    override void OnTick(PlayerBase player, float deltaTime)
    {
		if (!SecondarySymptomIsInQueue(player, CustomSymptomIDs.SYMPTOM_COCAINE_HIGH))
		{
			if (player.GetModifiersManager().IsModifierActive(CustomModifiers.MDF_COCAINE_HIGH)) {
				player.GetSymptomManager().RemoveSecondarySymptom(CustomSymptomIDs.SYMPTOM_COCAINE_HIGH);
			}
			player.GetSymptomManager().QueueUpSecondarySymptom(CustomSymptomIDs.SYMPTOM_COCAINE_HIGH);
		}

		m_Player.GetStatWater().Set(m_WaterAtStart);
		m_Player.GetStatEnergy().Set(m_EnergyAtStart);

        SymptomBase shivers = player.GetSymptomManager().QueueUpSecondarySymptomEx( SymptomIDs.SYMPTOM_HAND_SHIVER );
        if ( shivers )
        {
            CachedObjectsParams.PARAM1_INT.param1 = 5;
            shivers.SetParam( CachedObjectsParams.PARAM1_INT );
        }

		m_TimeSinceLastEvent += deltaT;

		if ( m_TimeSinceLastEvent >= m_NextEvent )
		{
			m_TimeSinceLastEvent = 0;
			m_NextEvent = Math.RandomFloatInclusive( EVENT_INTERVAL_MIN, EVENT_INTERVAL_MAX );
			
			m_RandomSymptomChance = Math.RandomInt( 0, 10 );

			if (m_RandomSymptomChance >= 0 && m_RandomSymptomChance < 5)
			{
				player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_PAIN_LIGHT);
			} 
			else if (m_RandomSymptomChance >= 5 && m_RandomSymptomChance <= 9)
			{
				player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_HOT);
			}
		}
    }
	
	override void OnReconnect(PlayerBase player)
	{
		this.OnActivate(player);
	}

	override void OnActivate(PlayerBase player)
	{
		m_EnergyAtStart = m_Player.GetStatEnergy().Get();
		m_WaterAtStart = m_Player.GetStatWater().Get();
		player.m_IsOnCocaine = true;
		player.IncreaseHealingsCount();
		player.GiveShock(100);
		player.GetStaminaHandler().SetStamina(100);
		player.GetStaminaHandler().ActivateDepletionModifier(EStaminaMultiplierTypes.EPINEPHRINE);
	}

	override void OnDeactivate(PlayerBase player)
	{
		player.m_IsOnCocaine = false;
		if (m_Player.GetStatEnergy().Get() - (m_EnergyAtStart / 3) > 0) {
			m_Player.GetStatEnergy().Set(m_EnergyAtStart / 3);
		} else {
			m_Player.GetStatWater().Set(0);
		}

		if (m_Player.GetStatWater().Get() - (m_WaterAtStart / 3) > 0) {
			m_Player.GetStatWater().Set(m_WaterAtStart / 3);
		} else {
			m_Player.GetStatWater().Set(0);
		}

		player.GetSymptomManager().RemoveSecondarySymptom(CustomSymptomIDs.SYMPTOM_COCAINE_HIGH);
		player.DecreaseHealingsCount();
		player.GetStaminaHandler().DeactivateDepletionModifier(EStaminaMultiplierTypes.EPINEPHRINE);
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		if ( GetAttachedTime() >= m_Lifetime )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
