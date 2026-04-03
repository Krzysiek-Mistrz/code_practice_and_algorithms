using System;
using System.Globalization;
using System.Runtime.InteropServices;

public enum Location
{
    NewYork,
    London,
    Paris
}

public enum AlertLevel
{
    Early,
    Standard,
    Late
}

public static class Appointment
{
    public static DateTime ShowLocalTime(DateTime dtUtc) => dtUtc.ToLocalTime();

    public static DateTime Schedule(string appointmentDateDescription, Location location)
    {
        string tzId = GetTimeZoneId(location);
        TimeZoneInfo tz = TimeZoneInfo.FindSystemTimeZoneById(tzId);
        DateTime localTime = DateTime.Parse(appointmentDateDescription);

        return TimeZoneInfo.ConvertTimeToUtc(localTime, tz);
    }

    public static DateTime GetAlertTime(DateTime appointment, AlertLevel alertLevel)
    {
        return alertLevel switch
        {
            AlertLevel.Early => appointment.AddDays(-1),
            AlertLevel.Standard => appointment.AddHours(-1).AddMinutes(-45),
            AlertLevel.Late => appointment.AddMinutes(-30),
            _ => appointment
        };
    }

    public static bool HasDaylightSavingChanged(DateTime dt, Location location)
    {
        TimeZoneInfo tz = TimeZoneInfo.FindSystemTimeZoneById(GetTimeZoneId(location));
        bool isCurrentlyDst = tz.IsDaylightSavingTime(dt);
        bool wasDstSevenDaysAgo = tz.IsDaylightSavingTime(dt.AddDays(-7));

        return isCurrentlyDst != wasDstSevenDaysAgo;
    }

    public static DateTime NormalizeDateTime(string dtStr, Location location)
    {
        string cultureName = location switch
        {
            Location.NewYork => "en-US",
            Location.London => "en-GB",
            Location.Paris => "fr-FR",
            _ => "en-US"
        };

        if (DateTime.TryParse(dtStr, new CultureInfo(cultureName), DateTimeStyles.None, out DateTime result))
        {
            return result;
        }

        return new DateTime(1, 1, 1);
    }
    
    private static string GetTimeZoneId(Location location)
    {
        bool isWindows = RuntimeInformation.IsOSPlatform(OSPlatform.Windows);

        return location switch
        {
            Location.NewYork => isWindows ? "Eastern Standard Time" : "America/New_York",
            Location.London => isWindows ? "GMT Standard Time" : "Europe/London",
            Location.Paris => isWindows ? "W. Europe Standard Time" : "Europe/Paris",
            _ => throw new ArgumentException("Unknown location")
        };
    }
}
