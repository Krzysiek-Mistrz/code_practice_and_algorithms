using System;
using System.Reflection.Metadata.Ecma335;

static class Appointment
{
    public static DateTime Schedule(string appointmentDateDescription)
    {
        return DateTime.Parse(appointmentDateDescription);
    }

    public static bool HasPassed(DateTime appointmentDate)
    {
        return appointmentDate < DateTime.Now ? true : false;
    }

    public static bool IsAfternoonAppointment(DateTime appointmentDate) => (appointmentDate.Hour >= 12 && appointmentDate.Hour < 18);

    public static string Description(DateTime appointmentDate)
    {
        if (appointmentDate.Hour > 12)
            return $"You have an appointment on {appointmentDate:M/d/yyyy h:mm:ss} PM.";
        else
            return $"You have an appointment on {appointmentDate:M/d/yyyy h:mm:ss} AM.";
    }

    public static DateTime AnniversaryDate()
    {
        return new DateTime(DateTime.Now.Year, 9, 15, 0, 0, 0);
    }
}
