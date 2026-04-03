class BirdCount
{
    static private int[] _birdsPerDay;

    public BirdCount(int[] birdsPerDay) {
        _birdsPerDay = birdsPerDay;
    }

    public static int[] LastWeek() => new int[] { 0, 2, 5, 3, 7, 8, 4 };

    public int Today() => _birdsPerDay[_birdsPerDay.Length - 1];

    public void IncrementTodaysCount()
    {
        _birdsPerDay[_birdsPerDay.Length - 1]++;
    }

    public bool HasDayWithoutBirds()
    {
        var visited = false;

        foreach (var elem in _birdsPerDay)
            if (elem == 0)
                visited = true;

        return visited;
    }

    public int CountForFirstDays(int numberOfDays)
    {
        var sum = 0;

        for (int i = 0; i < numberOfDays; i++)
        {
            sum += _birdsPerDay[i];
        }

        return sum;
    }

    public int BusyDays()
    {
        var numOfDays = 0;

        foreach (var elem in _birdsPerDay)
        {
            if (elem >= 5) numOfDays++; // Czytelniejszy standardowy if
        }

        return numOfDays;
    }
}
