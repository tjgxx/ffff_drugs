class CocaineHighSymptom extends SymptomBase
{
    int m_Delay = 30;
    protected PPERequester_CocaineHigh m_RequesterCocaineHigh;
    private float m_Time = 0.0;

    override void OnInit()
    {
        m_SymptomType = SymptomTypes.SECONDARY;
        m_Priority = 50;
        m_ID = CustomSymptomIDs.SYMPTOM_COCAINE_HIGH;
        m_DestroyOnAnimFinish = true;
        m_IsPersistent = true;
        m_SyncToClient = true;

        if ( !GetGame().IsDedicatedServer() )
        {
            Class.CastTo( m_RequesterCocaineHigh, PPERequester_CocaineHigh.Cast( PPERequesterBank.GetRequester( PPERequester_CocaineHigh ) ) );
        }
    }

    override void OnUpdateClient( PlayerBase player, float deltatime )
    {
        m_Time += deltatime;

        m_RequesterCocaineHigh.activate();
    }

    override void OnGetDeactivatedClient( PlayerBase player )
    {
        m_RequesterCocaineHigh.deactivate();

    }

}