enum CustomSymptomIDs : SymptomIDs
{
    SYMPTOM_TRIPPING_MUSHROOMS = 500
}

modded class SymptomManager
{
    override void Init()
    {
        super.Init();

        RegisterSymptom( new TrippingMushrooms );
    }
}