class TrippingMushrooms extends SymptomBase
{

    protected PPERequester_MushroomTrip m_RequesterTrip_Peak;
    private float m_Time = 0.0;

    override void OnInit()
    {
        m_SymptomType = SymptomTypes.SECONDARY;
        m_Priority = 50;
        m_ID = CustomSymptomIDs.SYMPTOM_TRIPPING_MUSHROOMS;
        m_DestroyOnAnimFinish = true;
        m_IsPersistent = true;
        m_SyncToClient = true;

        if ( !GetGame().IsDedicatedServer() )
        {
            Class.CastTo( m_RequesterTrip_Peak, PPERequester_MushroomTrip.Cast( PPERequesterBank.GetRequester( PPERequester_MushroomTrip ) ) );
        }
    }

    override void OnGetActivatedClient( PlayerBase player )
    {
        m_Time = 0.0;

        if (LogManager.IsSymptomLogEnable()) Debug.SymptomLog("n/a", this.ToString(), "n/a", "OnGetActivated", m_Player.ToString());
    }

    override void OnUpdateClient( PlayerBase player, float deltatime )
    {
        m_Time += deltatime;
        
        if (m_Time > 30)
        {
            m_RequesterTrip_Peak.activate();
        }
		
    }

    override void OnGetDeactivatedClient( PlayerBase player )
    {
        m_RequesterTrip_Peak.deactivate();

        if (LogManager.IsSymptomLogEnable()) Debug.SymptomLog("n/a", this.ToString(), "n/a", "OnGetDeactivated", m_Player.ToString());
    }

    	//!gets called once on an Symptom which is being activated
	override void OnGetActivatedServer(PlayerBase player)
	{
		if (LogManager.IsSymptomLogEnable()) 
			Debug.SymptomLog("n/a", this.ToString(), "n/a", "OnGetActivated", m_Player.ToString());
		

		//player.AddHealth("","Shock",-10);
	}
	//!only gets called once on an active Symptom that is being deactivated
	override void OnGetDeactivatedServer(PlayerBase player)
	{
		if (LogManager.IsSymptomLogEnable()) Debug.SymptomLog("n/a", this.ToString(), "n/a", "OnGetDeactivated", m_Player.ToString());
	}


}