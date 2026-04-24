using System;
using System.Collections.Generic;
using System.Linq;


public struct Coord
{
    public Coord(ushort x, ushort y)
    {
        X = x;
        Y = y;
    }

    public ushort X { get; }
    public ushort Y { get; }
}


public struct Plot
{
    public Coord Coord1 { get; }
    public Coord Coord2 { get; }
    public Coord Coord3 { get; }
    public Coord Coord4 { get; }

    public Plot(Coord c1, Coord c2, Coord c3, Coord c4)
    {
        Coord1 = c1;
        Coord2 = c2;
        Coord3 = c3;
        Coord4 = c4;
    }

    // Pomocnicza metoda do obliczenia najdłuższego boku prostokąta
    public ushort GetLongestSide()
    {
        // Ponieważ działki są prostokątne i przyległe, boki to różnice między współrzędnymi.
        // Sprawdzamy wszystkie możliwe odległości między X i Y wewnątrz jednej działki.
        ushort side1 = (ushort)Math.Abs(Coord1.X - Coord2.X);
        ushort side2 = (ushort)Math.Abs(Coord2.X - Coord3.X); // Wystarczy sprawdzić sąsiednie
        ushort side3 = (ushort)Math.Abs(Coord1.Y - Coord3.Y);
        ushort side4 = (ushort)Math.Abs(Coord1.Y - Coord2.Y);

        return Math.Max(Math.Max(side1, side2), Math.Max(side3, side4));
    }
}


public class ClaimsHandler
{
    private readonly HashSet<Plot> _claims = new HashSet<Plot>();
    private Plot _lastClaim;

    public void StakeClaim(Plot plot)
    {
        _claims.Add(plot);
        _lastClaim = plot;
    }

    public bool IsClaimStaked(Plot plot) => _claims.Contains(plot);

    public bool IsLastClaim(Plot plot) => plot.Equals(_lastClaim);

    public Plot GetClaimWithLongestSide()
    {
        Plot longestPlot = default;
        ushort maxSide = 0;

        foreach (var plot in _claims)
        {
            ushort currentMax = plot.GetLongestSide();
            if (currentMax > maxSide)
            {
                maxSide = currentMax;
                longestPlot = plot;
            }
        }

        return longestPlot;
    }
}