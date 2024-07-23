modded class PlayerBase extends ManBase
{
    bool m_IsOnShrooms;
    bool m_IsOnCocaine;

    override void Init()
    {
        super.Init();

        RegisterNetSyncVariableBool("m_IsOnShrooms");
        RegisterNetSyncVariableBool("m_IsOnCocaine");
    }
}