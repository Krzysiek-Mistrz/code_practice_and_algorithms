using System;
using System.Collections.Generic;

public class FacialFeatures
{
    public string EyeColor { get; }
    public decimal PhiltrumWidth { get; }

    public FacialFeatures(string eyeColor, decimal philtrumWidth)
    {
        EyeColor = eyeColor;
        PhiltrumWidth = philtrumWidth;
    }

    public override bool Equals(object obj)
    {
        if (obj is FacialFeatures other)
        {
            return EyeColor == other.EyeColor && PhiltrumWidth == other.PhiltrumWidth;
        }
        return false;
    }

    public override int GetHashCode() => HashCode.Combine(EyeColor, PhiltrumWidth);
}

public class Identity
{
    public string Email { get; }
    public FacialFeatures FacialFeatures { get; }

    public Identity(string email, FacialFeatures facialFeatures)
    {
        Email = email;
        FacialFeatures = facialFeatures;
    }

    public override bool Equals(object obj)
    {
        if (obj is Identity other)
        {
            // Identity jest równe, gdy email i cechy twarzy są takie same
            return Email == other.Email && FacialFeatures.Equals(other.FacialFeatures);
        }
        return false;
    }

    public override int GetHashCode() => HashCode.Combine(Email, FacialFeatures);
}

public class Authenticator
{
    private readonly HashSet<Identity> _registeredIdentities = new HashSet<Identity>();

    public static bool AreSameFace(FacialFeatures faceA, FacialFeatures faceB) => faceA.Equals(faceB);

    public bool IsAdmin(Identity identity)
    {
        var adminFeatures = new FacialFeatures("green", 0.9m);
        var adminIdentity = new Identity("admin@exerc.ism", adminFeatures);
        return adminIdentity.Equals(identity);
    }

    public bool Register(Identity identity)
    {
        // HashSet.Add zwraca false, jeśli element już istnieje
        return _registeredIdentities.Add(identity);
    }

    public bool IsRegistered(Identity identity) => _registeredIdentities.Contains(identity);

    public static bool AreSameObject(Identity identityA, Identity identityB) => ReferenceEquals(identityA, identityB);
}