class PPERequester_MushroomTrip : SPPEffectAnimated
{
	SColor color;
	private static float startValue = 0;
    private static float endValue = 0.05;
    private static float lerpDuration = 3; // Duration of the lerp in seconds
    private static float currentLerpTime = 0;
    private static float currentValue;
	
	override void onInit() 
	{
		setMotionBlurPower(1);
        setChromAber(0.025);
        setGodrays(1, 1, 1, 1, 1, 0, 0, 0);
        setRadialBlur(0, 0);
	};
	
	override void onAnimate(float deltaTime) 
	{
		currentLerpTime += deltaTime;	

        if (currentLerpTime > lerpDuration)
        {
            // Swap start and end values
            float temp = startValue;
            startValue = endValue;
            endValue = temp;

            // Reset lerp time
            currentLerpTime = 0;
        }

        // Calculate the lerp value
        float t = currentLerpTime / lerpDuration;
		currentValue = Lerp(startValue, endValue, t);
		setChromAber(currentValue);
        setRadialBlur(currentValue, currentValue, 0, 0);
		setSaturation(4);
	};
	
	float Lerp(float start, float end, float t)
	{
		return start + (end - start) * t;
	};
	
};
/*
		if (timeSpentActive > 1)
		{
			chromAberValue = LerpValues(0.0, 0.03, 3, deltaTime);
		}
		
		if (timeSpentActive > 0.5)
		{
			motBlurMinAngle = LerpValues(10.0, 100.0, 5, deltaTime);
			motBlurMaxAngle = LerpValues(100.0, 150.0, 5, deltaTime);
		}
		
		if (timeSpentActive > 2.5)
		{
			motBlurMinDepth = LerpValues(2.5, 5.0, 5, deltaTime);
			motBlurMaxDepth = LerpValues(4.5, 30.0, 5, deltaTime);
		}
		
		if (timeSpentActive > 4.5)
		{
			radBlurPowX = LerpValues(0.001, 0.05, 3, deltaTime);
			radBlurPowY = LerpValues(0.001, 0.05, 3, deltaTime);
		}
		
		if (timeSpentActive > 2.5)
		{
			radBlurOffX = LerpValues(0.5, 2, 5, deltaTime);
			radBlurOffY = LerpValues(0.5, 3, 4, deltaTime);
		}
*/