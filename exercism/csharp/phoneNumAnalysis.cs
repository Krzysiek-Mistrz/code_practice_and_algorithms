public static class PhoneNumber
{
    public static (bool IsNewYork, bool IsFake, string LocalNumber) Analyze(string phoneNumber)
    {
        var parts = phoneNumber.Split('-');

        bool IsNewYork = parts[0] == "212";
        bool isFake = parts[1] == "555";
        string lastDigits = parts[2];

        return (IsNewYork, isFake, lastDigits); 
    }

    public static bool IsFake((bool IsNewYork, bool IsFake, string LocalNumber) phoneNumberInfo) => phoneNumberInfo.IsFake;
}
