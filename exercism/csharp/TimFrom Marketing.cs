using System.Data.Common;

static class Badge
{
    public static string Print(int? id, string name, string? department)
    {
        string idPart = id == null ? "" : $"[{id}] - ";
        string deptPart = (department ?? "OWNER").ToUpper();

        return $"{idPart}{name} - {deptPart}";
    }
}