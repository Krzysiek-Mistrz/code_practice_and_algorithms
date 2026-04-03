class RemoteControlCar
{
    private int _batteryPercentage = 100;
    private int _speed;
    private int _batteryDrain;
    private int _distanceDriven = 0;

    // TODO: define the constructor for the 'RemoteControlCar' class
    public RemoteControlCar(int speed, int batteryDrain)
    {
        _speed = speed;
        _batteryDrain = batteryDrain;
    }

    public bool BatteryDrained() => _batteryPercentage < _batteryDrain;

    public int DistanceDriven() => _distanceDriven;

    public void Drive()
    {
        if (!BatteryDrained())
        {
            _distanceDriven += _speed;
            _batteryPercentage -=  _batteryDrain;  
        }
    }

    public static RemoteControlCar Nitro()
    {
        var topSpeed = 50;
        var batteryDrain = 4;

        return new RemoteControlCar(topSpeed, batteryDrain);
    }
}

class RaceTrack
{
    private int _raceTrackDist;
    
    // TODO: define the constructor for the 'RaceTrack' class
    public RaceTrack(int raceTrackDist)
    {
        _raceTrackDist = raceTrackDist;
    }

    public bool TryFinishTrack(RemoteControlCar car)
    {
        while (car.DistanceDriven() < _raceTrackDist)
        {
            if (car.BatteryDrained())
                return false;
            
            car.Drive();
        }

        return true;
    }
}
