using System;

public class Player
{
    private Random _rand = new Random();

    public int RollDie()
    {        
        return _rand.Next(1, 19);
    }

    public double GenerateSpellStrength()
    {
        return _rand.NextDouble() * 100;
    }
}
