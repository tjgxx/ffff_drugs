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

	// override void OnFrameLightSource(IEntity other, float timeSlice)
	// {
	// 	int year, month, day, hour, minute;
	// 	GetGame().GetWorld().GetDate( year, month, day, hour, minute );
	// 	float hourOfDay = hour + ( (minute/100) / (60/100);

	// 	if (  hourOfDay >= 0.0 && hourOfDay <= 6.25  || hourOfDay >= 18.25 && hourOfDay <= 23.99  ) {
	// 		SetBrightnessTo(0.001);
	// 	} else {
	// 		SetBrightnessTo(0.1);
	// 	}
	// }

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


