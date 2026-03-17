static class LogLine
{
    public static string Message(string logLine)
    {
        return logLine.Split(':')[1].Trim();
    }

    public static string LogLevel(string logLine)
    {
        var start = logLine.IndexOf('[') + 1;
        var end = logLine.IndexOf(']');
        return logLine[start..end].ToLower();
    }

    public static string Reformat(string logLine)
    {
        var logLevel = LogLevel(logLine);
        var message = Message(logLine);
        return $"{message} ({logLevel})";
    }
}