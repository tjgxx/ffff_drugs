modded class Cooking {
    override void ProcessItemToCook(notnull ItemBase pItem, ItemBase cookingEquip, Param2<CookingMethodType, float> pCookingMethod, out Param2<bool, bool> pStateFlags)
    {
        super.ProcessItemToCook(pItem, cookingEquip, pCookingMethod, pStateFlags);

        if (pItem.IsKindOf("FFFF_Glow_Mushroom_Base") && pItem.GetTemperature() >= 70 && cookingEquip.GetQuantity() >= 900 && cookingEquip.GetTemperature() >= 200 && cookingEquip.GetLiquidType() == LIQUID_WATER)
        {

            cookingEquip.SetLiquidType(LIQUID_TEA);
            GetGame().ObjectDelete( pItem );
        }
    }
}