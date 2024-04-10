class MushroomLightBlue extends PointLightBase
{
	private static float m_DefaultBrightness = 1.5;
    private static float m_TooDarkBrightnessOverride = 2.25;
    private static float m_WayTooDarkBrightnessOverride = 3;
	private static float m_DefaultRadius = 7.5;

	void MushroomLightBlue()
	{
		SetVisibleDuringDaylight(true);
		SetRadiusTo(m_DefaultRadius);
		SetCastShadow(false);
        SetDiffuseColor(0.3, 0.3, 1.0);
		SetAmbientColor(0.3, 0.3, 1.0);
	}

    override void OnFrameLightSource(IEntity other, float timeSlice)
	{
		int year, month, day, hour, minute;
		GetGame().GetWorld().GetDate( year, month, day, hour, minute );
		float hourOfDay = hour + ( (minute/100) / (60/100);

		if ((hourOfDay >= 7.0 && hourOfDay <= 8)  || (hourOfDay >= 15.5 && hourOfDay <= 16.5)) {
			SetBrightnessTo(m_WayTooDarkBrightnessOverride);
		} else if (hourOfDay > 8.0 && hourOfDay < 15.5)  {
            SetBrightnessTo(m_TooDarkBrightnessOverride);
        } else {
			SetBrightnessTo(m_DefaultBrightness);
		}
	}
}