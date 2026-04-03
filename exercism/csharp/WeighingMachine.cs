class WeighingMachine
{
    public int Precision { get; }

    public WeighingMachine(int precision)
    {
        Precision = precision;
    }

    private double weight;
    public double Weight { 
        get => weight; 
        set {
            if (value < 0)
            {
                throw new ArgumentOutOfRangeException(nameof(value), "Weight cannot be negative.");
            }        
            weight = value;
        }
    }

    public double TareAdjustment { get; set; } = 5;

    public string DisplayWeight
    {
        get
        {
            double displayedAmount = Weight - TareAdjustment;
            
            return $"{displayedAmount.ToString("f" + Precision)} kg";
        }
    }
}
