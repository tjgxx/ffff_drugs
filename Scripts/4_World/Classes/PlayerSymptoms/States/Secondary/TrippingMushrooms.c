class TrippingMushrooms extends SymptomBase
{
    int m_Delay = 30;
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

    override void OnUpdateClient( PlayerBase player, float deltatime )
    {
        m_Time += deltatime;

        m_RequesterTrip_Peak.activate();
    }

    override void OnGetDeactivatedClient( PlayerBase player )
    {
        m_RequesterTrip_Peak.deactivate();

    }

}