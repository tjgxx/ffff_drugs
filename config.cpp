class CfgPatches
{
	class ffff_drugs
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts",			
			"DZ_Gear_Food",
			"DZ_Gear_Medical",
			"ffff_item_overrides",
			"DZ_Gear_Cultivation",
			"CannabisPlus",
			"CP_Seeds",
			"CP_Bricks",
			"CP_Cigarettepacks",
			"CP_Fruits",
			"CP_Dry_Post",
			"CP_Plants",
			"CP_Bags",
			"CannabisPlus_Joint",
			"sVisual",
			"CJ_Materials"
		};
	};
};
class CfgMods
{
	class ffff_drugs
	{	
		dir = "ffff_drugs";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "ffff_drugs";
		author = "Rowan";
		version = "1";
		extra = 0;
		type = "mod";
		dependencies[]={"Game", "World"};
		
		class defs
		{
			class gameScriptModule
            {
                value = "";
                files[] = {"ffff_drugs/Scripts/3_Game"};
			};
            class worldScriptModule
            {
                value = "";
                files[] = {"ffff_drugs/Scripts/4_World"};
			};
		};
	};
};
class FoodAnimationSources;
class MushroomsStageTransitions;
class CfgVehicles
{
	class Inventory_Base;

	/*
	
		CANNABIS
	
	*/

	class CP_CannabisBags;
	class CP_CannabisSeedsSkunk;
	class CP_CannabisSeedsPackSkunk;
	class CP_CannabisBrickSkunk;
	class CP_CigarettePack_CannabisSkunk;
	class CP_CannabisSkunk;
	class CP_RawSkunkCannabisPlant;
	class CP_CannabisBagSkunk;
	class CP_JointSkunk;

	class FFFF_Cannabis_Seed : CP_CannabisSeedsSkunk
    {
		displayName="Cannabis Seeds";
		descriptionShort="A handful of cannabis seeds.";
		class Horticulture
		{
			PlantType="FFFF_Raw_Cannabis_Plant";
		};
	};
	class  FFFF_Cannabis_Seed_Pack: CP_CannabisSeedsPackSkunk
	{
		displayName="Packed Cannabis Seeds";
		descriptionShort="A package of cannabis seeds.";
		class Horticulture
		{
			ContainsSeedsType="FFFF_Cannabis_Seed";
		};
	};
	class FFFF_Cannabis_Brick: CP_CannabisBrickSkunk
	{
		displayName="Brick of Weed";
		descriptionShort="One pound of weed.";
		class Resources
		{
			class FFFF_Cannabis_Bag
			{
				value=16;
				variable="quantity";
			};
		};
	};
	class FFFF_Cannabis_Cigarette_Pack: CP_CigarettePack_CannabisSkunk
	{
		displayName="Joints";
		descriptionShort="A pack of joints.";
		cpCheckPack="FFFF_Cannabis_Joint";
	};
	class FFFF_Cannabis: CP_CannabisSkunk
	{
		displayName="Weed";
		descriptionShort="Some cannabis bud.";
		cpStepUpToBag="FFFF_Cannabis_Bag";
		cpStepUpToJoint="FFFF_Cannabis_Joint";
	};
	class FFFF_Raw_Cannabis_Plant : CP_RawSkunkCannabisPlant
    {
		displayName = "Raw Plant";
		descriptionShort = "A raw plant";
    };
	class FFFF_Cannabis_Bag: CP_CannabisBagSkunk
	{
		displayName="Bag of Weed";
		descriptionShort="About an ounce of weed.";
		class Resources
		{
			class FFFF_Cannabis
			{
				value=2;
				variable="quantity";
			};
		};
	};
	class FFFF_Cannabis_Joint: CP_JointSkunk
	{
		displayName="Joint";
		descriptionShort="A joint made out of finest weed";
		cpPackJoint="FFFF_Cannabis_Cigarette_Pack";
		cpCheckJoint="FFFF_Cannabis_Joint";
	};

	/*
	
		MUSHROOMS
	
	*/

	// cannabisplus overrides
	class FFFF_Glow_Mushrooms_Bag_Base : FFFF_Cannabis_Bag
	{
		scope=0;
		displayName="Bag of Glow Mushrooms";
		descriptionShort="About an ounce of Glow Mushrooms.";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"ffff_drugs\Data\Textures\CP_Overrides\GlowMushroom_Bag_Green_Co.paa"
		};
	};

	class FFFF_Glow_Mushrooms_Bag_Green : FFFF_Glow_Mushrooms_Bag_Base
	{
		scope=2;
		displayName="Bag of Green Mushrooms";
		cpStepUpToBrick="FFFF_Glow_Mushrooms_Brick_Green";
		cpStepDownToBud="FFFF_Glow_Mushroom_Green";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"ffff_drugs\Data\Textures\CP_Overrides\GlowMushroom_Bag_Green_Co.paa"
		};
		class Resources
		{
			class FFFF_Glow_Mushroom_Green
			{
				value=2;
				variable="quantity";
			};
		};
	};

	class FFFF_Glow_Mushrooms_Bag_Blue : FFFF_Glow_Mushrooms_Bag_Base
	{
		scope=2;
		displayName="Bag of Blue Mushrooms";
		cpStepUpToBrick="FFFF_Glow_Mushrooms_Brick_Blue";
		cpStepDownToBud="FFFF_Glow_Mushroom_Blue";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"ffff_drugs\Data\Textures\CP_Overrides\GlowMushroom_Bag_Blue_Co.paa"
		};
		class Resources
		{
			class FFFF_Glow_Mushroom_Blue
			{
				value=2;
				variable="quantity";
			};
		};
	};

	class FFFF_Glow_Mushrooms_Bag_Purple : FFFF_Glow_Mushrooms_Bag_Base
	{
		scope=2;
		displayName="Bag of Purple Mushrooms";
		cpStepUpToBrick="FFFF_Glow_Mushrooms_Brick_Purple";
		cpStepDownToBud="FFFF_Glow_Mushroom_Purple";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"ffff_drugs\Data\Textures\CP_Overrides\GlowMushroom_Bag_Purple_Co.paa"
		};
		class Resources
		{
			class FFFF_Glow_Mushroom_Purple
			{
				value=2;
				variable="quantity";
			};
		};
	};
	
	class FFFF_Glow_Mushrooms_Brick_Base: FFFF_Cannabis_Brick
	{
		scope=0;
		displayName="Brick of Glow Mushrooms";
		descriptionShort="One pound of Glow Mushrooms.";
		hiddenSelections[]=
		{
			"SeedPack",
			"Brick"
		};
		hiddenSelectionsTextures[]=
		{
			"ffff_drugs\Data\Textures\CP_Overrides\FFFF_Glow_Mushroom_Pack_Green.paa",
			"ffff_drugs\Data\Textures\CP_Overrides\FFFF_Glow_Mushrooms_Brick_Green_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"ffff_drugs\Data\Textures\CP_Overrides\Mushroom_Pack.rvmat",
			"ffff_drugs\Data\Textures\CP_Overrides\brick.rvmat"
		};
	};

	class FFFF_Glow_Mushrooms_Brick_Green : FFFF_Glow_Mushrooms_Brick_Base
	{
		scope=2;
		displayName="Brick of Green Mushrooms";
		cpStepDownToBag="FFFF_Glow_Mushrooms_Bag_Green";
		hiddenSelectionsTextures[]=
		{
			"ffff_drugs\Data\Textures\CP_Overrides\FFFF_Glow_Mushroom_Pack_Green.paa",
			"ffff_drugs\Data\Textures\CP_Overrides\FFFF_Glow_Mushrooms_Brick_Green_co.paa"
		};
		class Resources
		{
			class FFFF_Glow_Mushrooms_Bag_Green
			{
				value=16;
				variable="quantity";
			};
		};

	};

	class FFFF_Glow_Mushrooms_Brick_Blue : FFFF_Glow_Mushrooms_Brick_Base
	{
		scope=2;
		displayName="Brick of Blue Mushrooms";
		cpStepDownToBag="FFFF_Glow_Mushrooms_Bag_Blue";
		hiddenSelectionsTextures[]=
		{
			"ffff_drugs\Data\Textures\CP_Overrides\FFFF_Glow_Mushroom_Pack_Blue.paa",
			"ffff_drugs\Data\Textures\CP_Overrides\FFFF_Glow_Mushrooms_Brick_Blue_co.paa"
		};
		class Resources
		{
			class FFFF_Glow_Mushrooms_Bag_Blue
			{
				value=16;
				variable="quantity";
			};
		};

	};

	class FFFF_Glow_Mushrooms_Brick_Purple : FFFF_Glow_Mushrooms_Brick_Base
	{
		scope=2;
		displayName="Brick of Purple Mushrooms";
		cpStepDownToBag="FFFF_Glow_Mushrooms_Bag_Purple";
		hiddenSelectionsTextures[]=
		{
			"ffff_drugs\Data\Textures\CP_Overrides\FFFF_Glow_Mushroom_Pack_Purple.paa",
			"ffff_drugs\Data\Textures\CP_Overrides\FFFF_Glow_Mushrooms_Brick_Purple_co.paa"
		};
		class Resources
		{
			class FFFF_Glow_Mushrooms_Bag_Purple
			{
				value=16;
				variable="quantity";
			};
		};

	};

	// custom mushrooms
	class Edible_Base;
	class FFFF_Glow_Mushroom_Base : Inventory_Base
	{
		scope=0;
		displayName="Glowing Mushroom";
		descriptionShort="Some sort of mutated fungus... it's glowing!";
		model="ffff_drugs\Data\Single\FFFF_Glow_Mushroom_Single.p3d";
		weight=14;
		itemSize[]={1,2};
		canBeSplit=1;
		varQuantityInit=2;
		varQuantityMin=0;
		varQuantityMax=100;
		varStackMax=2;
		stackedUnit="";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3"
		};
		hiddenSelectionsTextures[]=
		{
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_raw_co.paa",
		};
		class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=10;
                    healthLevels[]={{1, {}}, {0.7, {}}, {0.5, {}}, {0.3, {}}, {0, {}}};
                };
            };
        };
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class Eating_TakeFood
				{
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_BoxOpen
				{
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake
				{
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd
				{
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
			};
		};
	};

	class FFFF_Glow_Mushroom_Green : FFFF_Glow_Mushroom_Base
	{
		displayName="Glowing Green Mushroom";
		scope=2;
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsMaterials[]=
		{
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_green.rvmat",
		};
	};

	
	class FFFF_Glow_Mushroom_Blue : FFFF_Glow_Mushroom_Base
	{
		displayName="Glowing Blue Mushroom";
		scope=2;
		hiddenSelections[]=
		{
			"camo2"
		};
		hiddenSelectionsMaterials[]=
		{
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_blue.rvmat",
		};
	};

	
	class FFFF_Glow_Mushroom_Purple : FFFF_Glow_Mushroom_Base
	{
		displayName="Glowing Purple Mushroom";
		scope=2;
		hiddenSelections[]=
		{
			"camo3"
		};
		hiddenSelectionsMaterials[]=
		{
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_purple.rvmat",
		};
	};

	class FFFF_Glow_Mushrooms_Harvestable_Base: Inventory_Base
	{
		displayName="Glowing Mushroom";
		descriptionShort="Some sort of mutated fungus... it's glowing!";
		scope=0;
		model="ffff_drugs\Data\Cluster\FFFF_Glow_Mushroom_Cluster.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3"
		};
		hiddenSelectionsTextures[]=
		{
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_raw_co.paa"
		};
	};

	class FFFF_Glow_Mushrooms_Harvestable_Green : FFFF_Glow_Mushrooms_Harvestable_Base
	{
		scope=2;
		displayName="Glowing Green Mushroom";
		class Harvesting
        {
            class ObtainedMushrooms
            {
                item="FFFF_Glow_Mushroom_Green";
                count=5;
                quantityMinMaxCoef[]={0.5, 1};
            };
        };
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsMaterials[]=
		{
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_green.rvmat",
		};
	};

	class FFFF_Glow_Mushrooms_Harvestable_Blue : FFFF_Glow_Mushrooms_Harvestable_Base
	{
		scope=2;
		displayName="Glowing Blue Mushroom";
		class Harvesting
        {
            class ObtainedMushrooms
            {
                item="FFFF_Glow_Mushroom_Blue";
                count=5;
                quantityMinMaxCoef[]={0.5, 1};
            };
        };
		hiddenSelections[]=
		{
			"camo2"
		};
		hiddenSelectionsMaterials[]=
		{
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_blue.rvmat",
		};
	};

	class FFFF_Glow_Mushrooms_Harvestable_Purple : FFFF_Glow_Mushrooms_Harvestable_Base
	{
		scope=2;
		displayName="Glowing Purple Mushroom";
		class Harvesting
        {
            class ObtainedMushrooms
            {
                item="FFFF_Glow_Mushroom_Purple";
                count=5;
                quantityMinMaxCoef[]={0.5, 1};
            };
        };
		hiddenSelections[]=
		{
			"camo3"
		};
		hiddenSelectionsMaterials[]=
		{
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_purple.rvmat",
		};
	};

	class FFFF_Cocaine : Inventory_Base
	{
		scope=2;
		displayName="Cocaine";
		descriptionShort="Cocaine";
		model="CJ_Materials\Sulfur\Sulfur2.p3d";
		itemSize[]={1,1};
		hiddenSelections[]=
		{
			"Powder"
		};
		hiddenSelectionsTextures[]=
		{
			"ffff_drugs\Data\Textures\cocaine_co.paa";
		};
		weight=200;
	}

	class FFFF_Heroin : Inventory_Base
	{
		scope=2;
		displayName="Heroin";
		descriptionShort="Heroin";
		model="CJ_Materials\Sulfur\Sulfur2.p3d";
		itemSize[]={1,1};
		hiddenSelections[]=
		{
			"Powder"
		};
		hiddenSelectionsTextures[]=
		{
			"ffff_drugs\Data\Textures\heroin_co.paa";
		};
		weight=200;
	}

	class FFFF_HeroinSyringe : Inventory_Base
	{
		scope=2;
		displayName="Syringe of Heroin";
		descriptionShort="Syringe of Heroin";
		model="\dz\gear\medical\syringe_Full.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"\dz\gear\medical\data\syringefluid_co.paa"
		};
		rotationFlags=17;
		weight=110;
		itemSize[]={1,2};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=20;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\Syringe.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\Syringe.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\Syringe_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\Syringe_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\Syringe_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Syringe_out
				{
					soundSet="Syringe_out_SoundSet";
					id=201;
				};
				class Syringe_spear
				{
					soundSet="Syringe_spear_SoundSet";
					id=202;
				};
				class Syringe_splash
				{
					soundSet="Syringe_splash_SoundSet";
					id=203;
				};
			};
		};
	};

	class Epinephrine;

	class Syringe : Epinephrine
	{
		displayName="Empty Syringe";
	};
};

class CfgSoundShaders
{
    class Custom_SoundShader_Base
    {
        range = 30;
    };

	class CocaineSnort_SoundShader : Custom_SoundShader_Base
	{
		samples[] =
		{
			{
				"ffff_drugs\Data\Sounds\snort_1.ogg", 1
			},
			{
				"ffff_drugs\Data\Sounds\snort_2.ogg", 2
			},
			{
				"ffff_drugs\Data\Sounds\snort_3.ogg", 3
			},
			{
				"ffff_drugs\Data\Sounds\snort_4.ogg", 4
			},
			{
				"ffff_drugs\Data\Sounds\snort_5.ogg", 5
			},
			{
				"ffff_drugs\Data\Sounds\snort_6.ogg", 6
			}
		};
		volume = 2; 
	};
};

class CfgSoundSets
{
	class Custom_SoundSet_Base
	{
		sound3DProcessingType = "character3DProcessingType";
        volumeCurve = "characterAttenuationCurve";
        spatial = 1;
        doppler = 0;
        loop = 0;
	};

	class CocaineSnort_SoundSet : Custom_SoundSet_Base
	{
		soundShaders[] =
		{
			"CocaineSnort_SoundShader"
		};

        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 2;
	};
};