class PPERequester_CocaineHigh : SPPEffectAnimated
{
	SColor color;
	private static float startValue = 0;
    private static float endValue = 0.025;
    private static float lerpDuration = 0.5; // Duration of the lerp in seconds
    private static float currentLerpTime = 0;
    private static float currentValue;
	
	override void onInit() 
	{
		setMotionBlurPower(1);
        setRadialBlur(0, 0);
        setGodrays(1, 1, 1, 1, 1, 0, 0, 0);
        setSaturation(2);
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
        setRadialBlur(currentValue, currentValue, 0, 0);
	};
	
	float Lerp(float start, float end, float t)
	{
		return start + (end - start) * t;
	};
	
};
