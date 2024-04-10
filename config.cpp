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
			"ffff_item_overrides",
			"DZ_Gear_Cultivation",
			"CP_Seeds",
			"CP_Bricks",
			"CP_Cigarettepacks",
			"CP_Fruits",
			"CP_Dry_Post",
			"CP_Plants",
			"CP_Bags",
			"CannabisPlus_Joint",
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
		dependencies[]={"World"};
		
		class defs
		{
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

	class ffff_cannabis_seeds : CP_CannabisSeedsSkunk
    {
		displayName="Cannabis Seeds";
		descriptionShort="A handful of cannabis seeds.";
	};
	class ffff_cannabis_seed_pack: CP_CannabisSeedsPackSkunk
	{
		displayName="Packed Cannabis Seeds";
		descriptionShort="A package of cannabis seeds.";
	};
	class ffff_cannabis_brick: CP_CannabisBrickSkunk
	{
		displayName="Brick of Weed";
		descriptionShort="One pound of weed.";
	};
	class ffff_cannabis_cigarette_pack: CP_CigarettePack_CannabisSkunk
	{
		displayName="Joints";
		descriptionShort="A pack of joints.";
	};
	class ffff_cannabis: CP_CannabisSkunk
	{
		displayName="Weed";
		descriptionShort="Some cannabis bud.";
	};
	class ffff_raw_cannabis_plant : CP_RawSkunkCannabisPlant
    {
		displayName = "Raw Plant";
		descriptionShort = "A raw plant";
    };
	class ffff_cannabis_bag: CP_CannabisBagSkunk
	{
		displayName="Bag of Weed";
		descriptionShort="About an ounce of weed.";
	};
	class ffff_cannabis_joint: CP_JointSkunk
	{
		displayName="Joint";
		descriptionShort="A joint made out of finest weed";
	};

	/*
	
		MUSHROOMS
	
	*/

	// cannabisplus overrides
	class FFFF_Glow_Mushrooms_Bag : ffff_cannabis_bag
	{
		scope=2;
		displayName="Bag of Glow Mushrooms";
		descriptionShort="About an ounce of Glow Mushrooms.";
		hiddenSelectionsTextures[]=
		{
			"ffff_drugs\Data\Textures\CP_Overrides\GlowMushroom_Bag_Co.paa"
		};
	};
	
	class FFFF_Glow_Mushrooms_Brick: ffff_cannabis_brick
	{
		scope=2;
		displayName="Brick of Glow Mushrooms";
		descriptionShort="One pound of Glow Mushrooms.";
		hiddenSelectionsTextures[]=
		{
			"ffff_drugs\Data\Textures\CP_Overrides\GlowMushroom_Brick_Co.paa"
		};
	};
	class FFFF_Glow_Mushrooms_Cigarette_Pack: ffff_cannabis_cigarette_pack
	{
		displayName="Glow Mushroom Cigarettes";
		descriptionShort="A pack of Glow Mushroom Cigarettes.";
		hiddenSelectionsTextures[]=
		{
			"ffff_drugs\Data\Textures\CP_Overrides\GlowMushroom_CigarettePack_Co.paa",
			"ffff_drugs\Data\Textures\CP_Overrides\GlowMushroom_CigarettePack_Co.paa"
		};
	};
	class FFFF_Glow_Mushrooms_Joint: ffff_cannabis_joint
	{
		displayName="Glow Mushroom Joint";
		descriptionShort="A joint made out of finest Glow Mushrooms";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"ffff_drugs\Data\Textures\CP_Overrides\GlowMushroom_Joint_Co.paa"
		};
	};

	// custom mushrooms
	class AgaricusMushroom;
	class FFFF_Glow_Mushroom_Base : AgaricusMushroom
	{
		scope=2;
		displayName="Glowing Mushroom";
		descriptionShort="Some sort of mutated fungus...";
		model="ffff_drugs\Data\Single\FFFF_Glow_Mushroom_Single.p3d";
		weight=0;
		itemSize[]={1,2};
		varQuantityInit=150;
		varQuantityMin=0;
		varQuantityMax=150;
		stackedUnit="";
		inventorySlot[]=
		{
			"Ingredient",
			"DirectCookingA",
			"DirectCookingB",
			"DirectCookingC",
			"SmokingA",
			"SmokingB",
			"SmokingC",
			"SmokingD"
		};
		hiddenSelections[]=
		{
			"cs_raw",
			"cs_dried"
		};
		hiddenSelectionsTextures[]=
		{
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_raw_co.paa",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_baked_co.paa",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_boiled_co.paa",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_dried_co.paa",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_burnt_co.paa"
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
		class AnimationSources: FoodAnimationSources {};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[]={0,0,0};
					nutrition_properties[]={2.5,120,195,1,0};
					cooking_properties[]={0,0};
				};
				class Rotten
				{
					visual_properties[]={-1,-1,5};
					nutrition_properties[]={2,90,105,1,0,16};
					cooking_properties[]={0,0};
				};
				class Baked
				{
					visual_properties[]={0,1,1};
					nutrition_properties[]={1.75,300,500,1,0};
					cooking_properties[]={70,35};
				};
				class Boiled
				{
					visual_properties[]={0,2,2};
					nutrition_properties[]={1.5,250,600,1,0};
					cooking_properties[]={70,45};
				};
				class Dried
				{
					visual_properties[]={1,3,3};
					nutrition_properties[]={0.75,250,105,1,0};
					cooking_properties[]={70,30,80};
				};
				class Burned
				{
					visual_properties[]={0,4,4};
					nutrition_properties[]={2,90,90,1,0};
					cooking_properties[]={100,20};
				};
			};
			class FoodStageTransitions: MushroomsStageTransitions {};
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
		hiddenSelectionsMaterials[]=
		{
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_green.rvmat",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_baked.rvmat",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_boiled.rvmat",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_dried.rvmat",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_burnt.rvmat",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_rotten.rvmat"
		};
	};

	
	class FFFF_Glow_Mushroom_Blue : FFFF_Glow_Mushroom_Base
	{
		hiddenSelectionsMaterials[]=
		{
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_blue.rvmat",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_baked.rvmat",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_boiled.rvmat",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_dried.rvmat",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_burnt.rvmat",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_rotten.rvmat"
		};
	};

	
	class FFFF_Glow_Mushroom_Purple : FFFF_Glow_Mushroom_Base
	{
		hiddenSelectionsMaterials[]=
		{
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_purple.rvmat",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_baked.rvmat",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_boiled.rvmat",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_dried.rvmat",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_burnt.rvmat",
			"ffff_drugs\Data\Textures\ffff_glow_mushroom_rotten.rvmat"
		};
	};

	class FFFF_Glow_Mushrooms_Harvestable_Base: Inventory_Base
	{
		displayName="Glowing Mushroom";
		descriptionShort="Some sort of mutated fungus...";
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
	
};
