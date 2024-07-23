class FFFF_HeroinSyringe : ItemBase
{
    override void SetActions()
	{
		super.SetActions();
		AddAction(ActionInjectDrugSelf);
	}
}