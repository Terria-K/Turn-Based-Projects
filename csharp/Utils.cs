namespace TurnBaseCombat;

public static class Utils 
{
    private static Random random = new Random();

    public static int GenerateRandom(int max) 
    {
        return random.Next() % max;
    }
}
