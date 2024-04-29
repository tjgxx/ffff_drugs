modded class PPEGlow
{
  override void RegisterMaterialParameters()
	{
        super.RegisterMaterialParameters();
        RegisterParameterScalarFloat(PARAM_BLOOMSTEEPNESS,"BloomSteepness",1,0,20);		
		RegisterParameterScalarFloat(PARAM_BLOOMINTENSITY,"BloomIntensity",1,0,20);
        RegisterParameterScalarFloat(PARAM_BLOOMTHRESHOLD,"BloomThreshold",0.5,0,20);
        RegisterParameterScalarFloatEx(PARAM_SATURATION,"Saturation",1,0,20,PPEMatClassParameterFloatSaturation);
    }
};

modded class PPEGodRays
{
	
	override void RegisterMaterialParameters()
	{
        super.RegisterMaterialParameters();
		RegisterParameterScalarFloat(PARAM_INTENSITY,"Intensity",0.8,0,5);
		RegisterParameterScalarFloat(PARAM_SUNVISIBLE,"SunVisible",1.0,0,1);
		RegisterParameterScalarFloat(PARAM_OVERBURNINTENSITY,"OverBurnIntensity",0.25,0,5);
		RegisterParameterScalarFloat(PARAM_OVERBURNSTART,"OverBurnStart",0.025,0,5);
		RegisterParameterScalarFloat(PARAM_OVERBURNEND,"OverBurnEnd",0.175,0,5);
		
		//TODO
		//SunMaskMat - DECLARE_RESOURCE_NAME
	}
}

// modded class PPERotBlur
// {
//     override void RegisterMaterialParameters()
// 	{
// 		RegisterParameterScalarFloat(PARAM_POWER,"Power",0.0,0.0,4);
// 		RegisterParameterScalarFloat(PARAM_MINANGLEPERSEC,"MinAnglePerSec",10.0,0.0,180.0);
// 		RegisterParameterScalarFloat(PARAM_MAXANGLEPERSEC,"MaxAnglePerSec",100.0,0.0,180.0);
// 		RegisterParameterScalarFloat(PARAM_MINDEPTH,"MinDepth",2.5,0.0,5.0);
// 		RegisterParameterScalarFloat(PARAM_MAXDEPTH,"MaxDepth",4.5,0.0,50.0);
// 	}
// }