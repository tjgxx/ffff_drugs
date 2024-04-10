/* 
    DayZplayercfgBase
    Added to Register Animations for Items.
*/
modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
		super.RegisterOneHanded(pType, pBehavior);

        pType.AddItemInHandsProfileIK("FFFF_Glow_Mushroom_Green", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/mushroom_psilocybe.anm");
    };
};