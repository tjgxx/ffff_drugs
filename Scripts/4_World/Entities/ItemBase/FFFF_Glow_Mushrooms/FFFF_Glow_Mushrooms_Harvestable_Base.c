class FFFF_Glow_Mushrooms_Harvestable_Base : ItemBase {};

class FFFF_Glow_Mushrooms_Harvestable_Green : FFFF_Glow_Mushrooms_Harvestable_Base
{
    MushroomLightGreen m_Light;
    Particle m_ParticleEfx;

    void FFFF_Glow_Mushrooms_Harvestable_Green()
    {
        if (GetGame().IsClient() || !GetGame().IsMultiplayer())
        {
            m_Light = MushroomLightGreen.Cast( ScriptedLightBase.CreateLight(MushroomLightGreen, "0 0 0", 0.08) );
            m_Light.AttachOnMemoryPoint(this, "lightPoint");
            m_ParticleEfx = Particle.PlayOnObject(ParticleList.FFFF_Glow_Mushroom_Particle_Green, this);
        }
    }

    void ~FFFF_Glow_Mushrooms_Harvestable_Green()
    {
        if (m_ParticleEfx) {
            m_ParticleEfx.Stop();
        }

        if (m_Light) 
        { 
            m_Light.FadeOut();
        }
        
        m_Light = NULL;
    }
    
    bool CanBeHarvested()
    {
        return true;
    }

    override bool CanPutIntoHands(EntityAI parent)
    {
        return false;
    }

    override bool CanPutInCargo(EntityAI parent)
    {
        return false;
    }

};

class FFFF_Glow_Mushrooms_Harvestable_Blue : FFFF_Glow_Mushrooms_Harvestable_Base
{
    MushroomLightBlue m_Light;
    Particle m_ParticleEfx;

    void FFFF_Glow_Mushrooms_Harvestable_Blue()
    {
        if (GetGame().IsClient() || !GetGame().IsMultiplayer())
        {
            m_Light = MushroomLightBlue.Cast( ScriptedLightBase.CreateLight(MushroomLightBlue, "0 0 0", 0.08) );
            m_Light.AttachOnMemoryPoint(this, "lightPoint");
            m_ParticleEfx = Particle.PlayOnObject(ParticleList.FFFF_Glow_Mushroom_Particle_Blue, this);
        }
    }

    void ~FFFF_Glow_Mushrooms_Harvestable_Blue()
    {
        m_ParticleEfx.Stop();

        if (m_Light) 
        { 
            m_Light.FadeOut();
        }
        
        m_Light = NULL;
    }
    
    bool CanBeHarvested()
    {
        return true;
    }

    override bool CanPutIntoHands(EntityAI parent)
    {
        return false;
    }

    override bool CanPutInCargo(EntityAI parent)
    {
        return false;
    }

};

class FFFF_Glow_Mushrooms_Harvestable_Purple : FFFF_Glow_Mushrooms_Harvestable_Base
{
    MushroomLightPurple m_Light;
    Particle m_ParticleEfx;

    void FFFF_Glow_Mushrooms_Harvestable_Purple()
    {
        if (GetGame().IsClient() || !GetGame().IsMultiplayer())
        {
            m_Light = MushroomLightPurple.Cast( ScriptedLightBase.CreateLight(MushroomLightPurple, "0 0 0", 0.08) );
            m_Light.AttachOnMemoryPoint(this, "lightPoint");
            m_ParticleEfx = Particle.PlayOnObject(ParticleList.FFFF_Glow_Mushroom_Particle_Purple, this);
        }
    }

    void ~FFFF_Glow_Mushrooms_Harvestable_Purple()
    {
        m_ParticleEfx.Stop();
        
        if (m_Light) 
        { 
            m_Light.FadeOut();
        }
        
        m_Light = NULL;
    }
    
    bool CanBeHarvested()
    {
        return true;
    }

    override bool CanPutIntoHands(EntityAI parent)
    {
        return false;
    }

    override bool CanPutInCargo(EntityAI parent)
    {
        return false;
    }

};
