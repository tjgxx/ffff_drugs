
modded class PluginRecipesManager 
{
	override void RegisterRecipies()
    {
      super.RegisterRecipies();
	
	RegisterRecipe(new FFFF_CraftCigsGlowMushrooms);
	RegisterRecipe(new FFFF_CraftGlowMushroomsBag);
	RegisterRecipe(new FFFF_CraftGlowMushroomsBrick);
	RegisterRecipe(new FFFF_CraftGlowMushroomsCigarettePackEmpty);
	RegisterRecipe(new FFFF_CraftGlowMushroomsCigarettePack);
	RegisterRecipe(new FFFF_DeCraftGlowMushroomsBrick);
	RegisterRecipe(new FFFF_DeCraftGlowMushroomsBag);
    }
}