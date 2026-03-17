class RemoteControlCar
{
    private int _distance;
    private int _batteryPercentage = 100;

    public static RemoteControlCar Buy() => new RemoteControlCar();

    public string DistanceDisplay() => $"Driven {_distance} meters";

    public string BatteryDisplay() => _batteryPercentage > 0 
        ? $"Battery at {_batteryPercentage}%" 
        : "Battery empty";

    public void Drive() {
        if (_batteryPercentage > 0)
        {
            _distance += 20;
            _batteryPercentage -= 1;
        }
    }
}
