modded class ActionConstructor
{
    override void RegisterActions( TTypenameArray actions )
    {
        super.RegisterActions( actions );

        actions.Insert(ActionHarvestMushroom);
        actions.Insert(ActionConsumeDrug);
        actions.Insert(ActionInjectDrugSelf);
        actions.Insert(ActionSnortDrug);

        // actions.RemoveItem(ActionCPUseBagger);
    }
}