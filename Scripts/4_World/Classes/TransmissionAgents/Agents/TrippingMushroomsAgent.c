class TrippingMushroomsAgent extends AgentBase
{
    override void Init()
    {
        m_Type = CustomAgents.TRIPPING_MUSHROOM;
        m_Invasibility = -0.9;
        m_Digestibility = 1.0;
        m_TransferabilityIn = 1;
        m_TransferabilityOut = 0;
        m_AntibioticsResistance = 0.0;
        m_MaxCount = 350.0;
        m_Potency = EStatLevels.GREAT;
        m_DieOffSpeed = 1.0;
    }
}