using System;
using System.Globalization;

public static class HighSchoolSweethearts
{
    public static string DisplaySingleLine(string studentA, string studentB)
    {
        string text = $"{studentA} ♡ {studentB}";
        int spacesNeededBefore = 30 - text.IndexOf('♡');
        
        return text.PadLeft(spacesNeededBefore + text.Length).PadRight(61);
    }

    public static string DisplayBanner(string studentA, string studentB) =>
        $@"
     ******       ******
   **      **   **      **
 **         ** **         **
**            *            **
**                         **
**     {studentA.Trim()}  +  {studentB.Trim()}     **
 **                       **
   **                   **
     **               **
       **           **
         **       **
           **   **
             ***
              *
        ";

    public static string DisplayGermanExchangeStudents(string studentA, string studentB, DateTime start, float hours)
    {
        var culture = CultureInfo.GetCultureInfo("de-DE");
        
        return $"{studentA} and {studentB} have been dating since {start.ToString("d", culture)} - that's {hours.ToString("N2", culture)} hours";
    }
}