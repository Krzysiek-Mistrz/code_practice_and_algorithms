public static class LogAnalysis 
{
    // TODO: define the 'SubstringAfter()' extension method on the `string` type
    public static string SubstringAfter(this string str, string delimiter)
    {
        int index = str.IndexOf(delimiter);
        if (index == -1) return string.Empty;
        return str[(index + delimiter.Length)..];
    }

    // TODO: define the 'SubstringBetween()' extension method on the `string` type
    public static string SubstringBetween(this string str, string firstDel, string secondDel)
    {
        int start = str.IndexOf(firstDel) + firstDel.Length;
        int end = str.IndexOf(secondDel, start); // Szukamy drugiego separatora PO pierwszym
        
        return str[start..end];
    }

    // TODO: define the 'Message()' extension method on the `string` type
    public static string Message(this string str) => str.Split(':')[1].Trim();

    // TODO: define the 'LogLevel()' extension method on the `string` type
    public static string LogLevel(this string str) => str.SubstringBetween("[", "]");
}