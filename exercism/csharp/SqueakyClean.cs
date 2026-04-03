using System;
using System.Text;


public static class Identifier
{
    public static string Clean(string identifier)
    {
        var sb = new StringBuilder();

        for (int i = 0; i < identifier.Length; i++)
        {
            char ch = identifier[i];

            if (ch == ' ')
            {
                sb.Append('_');
            }
            else if (char.IsControl(ch))
            {
                sb.Append("CTRL");
            }
            else if (ch == '-')
            {
                if ((i + 1) < identifier.Length)
                {
                    i++;
                    sb.Append(char.ToUpper(identifier[i]));
                }
            }
            else if (ch >= 'α' && ch <= 'ω')
            {
                continue;
            }
            else if (char.IsLetter(ch))
            {
                sb.Append(ch);
            }
        }

        return sb.ToString();
    }
}
