public struct CurrencyAmount
{
    private decimal amount;
    private string currency;

    public CurrencyAmount(decimal amount, string currency)
    {
        this.amount = amount;
        this.currency = currency;
    }

    private static void EnsureSameCurrency(CurrencyAmount a, CurrencyAmount b)
    {
        if (a.currency != b.currency)
        {
            throw new ArgumentException("Currencies do not match.");
        }
    }

    // === OPERATORY RÓWNOŚCI ===
    public static bool operator ==(CurrencyAmount left, CurrencyAmount right)
    {
        EnsureSameCurrency(left, right);
        return left.amount == right.amount;
    }

    public static bool operator !=(CurrencyAmount left, CurrencyAmount right)
    {
        return !(left == right);
    }

    public override bool Equals(object obj) => obj is CurrencyAmount other && this == other;
    public override int GetHashCode() => HashCode.Combine(amount, currency);

    public static bool operator >(CurrencyAmount left, CurrencyAmount right)
    {
        EnsureSameCurrency(left, right);
        return left.amount > right.amount;
    }

    public static bool operator <(CurrencyAmount left, CurrencyAmount right)
    {
        EnsureSameCurrency(left, right);
        return left.amount < right.amount;
    }

    public static CurrencyAmount operator +(CurrencyAmount left, CurrencyAmount right)
    {
        EnsureSameCurrency(left, right);
        return new CurrencyAmount(left.amount + right.amount, left.currency);
    }

    public static CurrencyAmount operator -(CurrencyAmount left, CurrencyAmount right)
    {
        EnsureSameCurrency(left, right);
        return new CurrencyAmount(left.amount - right.amount, left.currency);
    }

    public static CurrencyAmount operator *(CurrencyAmount left, decimal factor)
    {
        return new CurrencyAmount(left.amount * factor, left.currency);
    }

    public static CurrencyAmount operator /(CurrencyAmount left, decimal factor)
    {
        return new CurrencyAmount(left.amount / factor, left.currency);
    }

    public static explicit operator double(CurrencyAmount amount) => (double)amount.amount;

    public static implicit operator decimal(CurrencyAmount amount) => amount.amount;
}
