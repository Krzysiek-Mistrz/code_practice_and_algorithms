using System;


public class RemoteControlCar
{
    public string CurrentSponsor { get; private set; }
    private Speed currentSpeed;
    public TelemetryPanel Telemetry { get; }

    public RemoteControlCar()
    {
        Telemetry = new TelemetryPanel(this);
    }

    public string GetSpeed()
    {
        return currentSpeed.ToString();
    }

    public void SetSpeed(Speed speed)
    {
        currentSpeed = speed;
    }

    private void SetSponsor(string sponsorName)
    {
        CurrentSponsor = sponsorName;
    }

    public class TelemetryPanel
    {
        private readonly RemoteControlCar _car;

        internal TelemetryPanel(RemoteControlCar car)
        {
            _car = car;
        }

        public void Calibrate()
        {

        }

        public bool SelfTest() => true;

        public void ShowSponsor(string sponsorName)
        {
            _car.SetSponsor(sponsorName);
        }

        public void SetSpeed(decimal amount, string unitsString)
        {
            SpeedUnits speedUnits = SpeedUnits.MetersPerSecond;
            if (unitsString == "cps")
            {
                speedUnits = SpeedUnits.CentimetersPerSecond;
            }

            _car.SetSpeed(new Speed(amount, speedUnits));
        }
    }
}

public enum SpeedUnits
{
    MetersPerSecond,
    CentimetersPerSecond
}

public struct Speed
{
    public decimal Amount { get; }
    public SpeedUnits SpeedUnits { get; }

    public Speed(decimal amount, SpeedUnits speedUnits)
    {
        Amount = amount;
        SpeedUnits = speedUnits;
    }

    public override string ToString()
    {
        string unitsString = "meters per second";
        if (SpeedUnits == SpeedUnits.CentimetersPerSecond)
        {
            unitsString = "centimeters per second";
        }

        return Amount + " " + unitsString;
    }
}
