enum CustomModifierSyncIDs : eModifierSyncIDs
{
    MODIFIER_SYNC_TRIPPING_MUSHROOM = 0x00001000,
    MODIFIER_SYNC_COCAINE_HIGH = 0x00001001,
}

modded class ModifiersManager
{
    override void Init()
    {
        super.Init();

        AddModifier( new TrippingMushroomsMdfr );
        AddModifier( new CocaineHighMdfr );
    }
}