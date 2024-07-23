class MushroomLight extends PointLightBase
{
	private static float m_DefaultBrightness = 1.5;
	private static float m_DefaultRadius = 7.5;

	void MushroomLightGreen()
	{
		SetVisibleDuringDaylight(false);
		SetRadiusTo(m_DefaultRadius);
		SetBrightnessTo(m_DefaultBrightness);
		SetCastShadow(false);
		FadeIn(1);
		SetFlareVisible(false);
		SetAmbientColor(0.3, 1.0, 0.2);
		SetDiffuseColor(0.3, 1.0, 0.2);
	}

	void SetColorToPurple()
	{
		SetDiffuseColor(0.5, 0.2, 0.6);
    	SetAmbientColor(0.5, 0.2, 0.6);
	}
	
	void SetColorToGreen()
	{
		SetAmbientColor(0.3, 1.0, 0.2);
		SetDiffuseColor(0.3, 1.0, 0.2);
	}
	
	void SetColorToBlue()
	{
		SetAmbientColor(0.3, 0.3, 1.0);
		SetDiffuseColor(0.3, 0.3, 1.0);
	}
}


