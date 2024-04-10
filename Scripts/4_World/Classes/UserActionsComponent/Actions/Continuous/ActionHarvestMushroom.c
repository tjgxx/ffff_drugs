class ActionHarvestMushroomCB : ActionContinuousBaseCB
{
    override void CreateActionComponent()
    {
        m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.SKIN)
    }
}

class ActionHarvestMushroom : ActionContinuousBase
{
    void ActionHarvestMushroom()
    {
        m_CallbackClass = ActionHarvestMushroomCB;
        m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_MEDIUM;

        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody = true;
        m_Text = "Harvest Mushroom";
    }

    override void CreateConditionComponents()
    {
        m_ConditionItem = new CCINonRuined();
        m_ConditionTarget = new CCTCursorNoRuinCheck();
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        Object targetObject = target.GetObject();

        if (targetObject.IsKindOf("FFFF_Glow_Mushrooms_Harvestable_Base"))
        {
            // EntityAI target_EAI;
			// if (Class.CastTo(target_EAI, targetObject) && target_EAI.CanBeHarvestedWith(item))
			return true;
        }

        return false;
    }

	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);
		
		Object targetObject = action_data.m_Target.GetObject();
		
		// Mark the body as skinned to forbid another skinning action on it
		EntityAI body = EntityAI.Cast(targetObject);

		SpawnItems(action_data);
		
		if (body)
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(GetGame().ObjectDelete,body);
		}
		
		MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, UADamageApplied.SKINNING);

		action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);
	}

	vector GetRandomPos(vector body_pos)
	{
		return body_pos + Vector(Math.RandomFloat01() - 0.5, 0, Math.RandomFloat01() - 0.5);
	}

	// Spawns an organ defined in the given config
	ItemBase CreateOrgan(PlayerBase player, vector body_pos, string item_to_spawn, string cfg_harvesting_mushroom_class, ItemBase tool)
	{
		// Create item from config
		ItemBase added_item;
		vector pos_rnd = GetRandomPos(body_pos);
		Class.CastTo(added_item,  GetGame().CreateObjectEx(item_to_spawn, pos_rnd, ECE_PLACE_ON_SURFACE));
		
		// Check if skinning is configured for this body
		if (!added_item)
			return null;
		
		// Set randomized position
		added_item.PlaceOnSurface();
		
		// Set item's quantity from config, if it's defined there.
		float item_quantity = 0;
		array<float> quant_min_max = new array<float>;
		array<float> quant_min_max_coef = new array<float>;
		
		GetGame().ConfigGetFloatArray(cfg_harvesting_mushroom_class + "quantityMinMax", quant_min_max);
		GetGame().ConfigGetFloatArray(cfg_harvesting_mushroom_class + "quantityMinMaxCoef", quant_min_max_coef);
		
		
		// Read config for quantity value
		if (quant_min_max.Count() > 0)
		{
			float soft_skill_manipulated_value = (quant_min_max.Get(0)+ quant_min_max.Get(1)) / 2;
			float min_quantity = player.GetSoftSkillsManager().AddSpecialtyBonus(soft_skill_manipulated_value, this.GetSpecialtyWeight());
			item_quantity = Math.RandomFloat(min_quantity, quant_min_max.Get(1));
		}
		
		if (quant_min_max_coef.Count() > 0)
		{
			float coef = Math.RandomFloat(quant_min_max_coef.Get(0), quant_min_max_coef.Get(1));
			item_quantity = added_item.GetQuantityMax() * coef;
		}
		
		if (GetGame().ConfigGetFloat(cfg_harvesting_mushroom_class + "quantity") > 0)
			item_quantity = g_Game.ConfigGetFloat(cfg_harvesting_mushroom_class + "quantity");
		
		if (GetGame().ConfigGetFloat(cfg_harvesting_mushroom_class + "quantityCoef") > 0)
		{
			float coef2 = g_Game.ConfigGetFloat(cfg_harvesting_mushroom_class + "quantityCoef");
			item_quantity = added_item.GetQuantityMax() * coef2;
		}
		
		if (item_quantity > 0)
		{
			item_quantity = Math.Round(item_quantity);
			added_item.SetQuantity(item_quantity, false);
		}
		
		// Transfer tool's damage to the item's condition
		float item_apply_tool_damage_coef = GetGame().ConfigGetFloat(cfg_harvesting_mushroom_class + "transferToolDamageCoef");
		
		if (item_apply_tool_damage_coef > 0)
		{
			float tool_dmg_coef = 1 - tool.GetHealth01();
			float organ_dmg_coef = tool_dmg_coef * item_apply_tool_damage_coef;
			added_item.DecreaseHealthCoef(organ_dmg_coef);
		}

		return added_item;
	}

	override void OnFinishProgressClient(ActionData action_data)
	{
		super.OnFinishProgressClient(action_data);
	}

	void SpawnItems(ActionData action_data)
	{
		EntityAI body = EntityAI.Cast(action_data.m_Target.GetObject());
		
		// Get config path to the animal
		string cfg_animal_class_path = "cfgVehicles " + body.GetType() + " " + "Harvesting ";
		vector bodyPosition = body.GetPosition();
		
		// Getting item type from the config
		int child_count = g_Game.ConfigGetChildrenCount(cfg_animal_class_path);
		
		string item_to_spawn;
		string cfg_harvesting_mushroom_class;
		// Parsing of the 'Skinning' class in the config of the dead body
		for (int i1 = 0; i1 < child_count; i1++)
		{
			// To make configuration as convenient as possible, all classes are parsed and parameters are read
			g_Game.ConfigGetChildName(cfg_animal_class_path, i1, cfg_harvesting_mushroom_class); // out cfg_harvesting_mushroom_class
			cfg_harvesting_mushroom_class = cfg_animal_class_path + cfg_harvesting_mushroom_class + " ";
			g_Game.ConfigGetText(cfg_harvesting_mushroom_class + "item", item_to_spawn); // out item_to_spawn
			
			if (item_to_spawn != "") // Makes sure to ignore incompatible parameters in the Skinning class of the agent
			{
				// Spawning items in action_data.m_Player's inventory
				int item_count = g_Game.ConfigGetInt(cfg_harvesting_mushroom_class + "count");
				
				array<string> itemZones = new array<string>;
				array<float> itemCount = new array<float>;
				float zoneDmg = 0;
				
				GetGame().ConfigGetTextArray(cfg_harvesting_mushroom_class + "itemZones", itemZones);
				GetGame().ConfigGetFloatArray(cfg_harvesting_mushroom_class + "countByZone", itemCount);
				
				if (itemCount.Count() > 0)
				{
					item_count = 0;
					for (int z = 0; z < itemZones.Count(); z++)
					{
						zoneDmg = body.GetHealth01(itemZones[z], "Health");
						zoneDmg *= itemCount[z]; //just re-using variable
						item_count += Math.Floor(zoneDmg);
					}
				}
				
				for (int i2 = 0; i2 < item_count; i2++)
				{
					ItemBase spawn_result = CreateOrgan(action_data.m_Player, bodyPosition, item_to_spawn, cfg_harvesting_mushroom_class, action_data.m_MainItem);
					
					//Damage pelts based on the average values on itemZones
					//It only works if the "quantityCoef" in the config is more than 0 
					float qtCoeff = GetGame().ConfigGetFloat(cfg_harvesting_mushroom_class + "quantityCoef");
					if (qtCoeff > 0)
					{
						float avgDmgZones = 0;
						for (int c2 = 0; c2 < itemZones.Count(); c2++)
						{
							avgDmgZones += body.GetHealth01(itemZones[c2], "Health");
						}
						
						avgDmgZones = avgDmgZones/itemZones.Count(); // Evaluate the average Health
						
						if (spawn_result)
							spawn_result.SetHealth01("","", avgDmgZones);
					}	
				}
			}
		}
	}
}