enum CustomSymptomIDs : SymptomIDs
{
    SYMPTOM_TRIPPING_MUSHROOMS = 500;
    SYMPTOM_COCAINE_HIGH = 501;
}

modded class SymptomManager
{
    override void Init()
    {
        super.Init();

        RegisterSymptom( new TrippingMushrooms );
        RegisterSymptom( new CocaineHighSymptom );
    }
}