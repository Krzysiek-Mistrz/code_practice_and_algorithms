// Instructions
// You've been asked to do some more work on the network authentication system.
// In addition to the admin identity being hard-coded in the system during development the powers that be also want senior developers to be given the same treatment.
// The admin's details are as follows:
// Email	Eye Color	Philtrum Width	Name	Address 1	Address 2
// admin@ex.ism	green	0.9	Chanakya	Mumbai	India
// Implement the Authenticator.Admin property to return the system admin's identity details. The name and each part of the address should be in a separate element of the NameAndAddress list.
// var authenticator = new Authenticator();
// authenticator.Admin;
// // => {"admin@ex.ism", {"green", 0.9m}, ["Chanakya", "Mumbai", "India"]}
// Opens in a modal
// The developers' details are as follows:
// Email	Eye Color	Philtrum Width	Name	Address 1	Address 2
// bert@ex.ism	blue	0.8	Bertrand	Paris	France
// anders@ex.ism	brown	0.85	Anders	Redmond	USA
// Implement the Authenticator.Developers property to return the developers' identity details. The dictionary key is the developer's name.
// var authenticator = new Authenticator();
// authenticator.Developers;
// // => ["Bertrand"] = {"bert@ex.ism", {"blue", 0.8m}, ["Bertrand", "Paris", "France"]},
// // ["Anders"] = {"anders@ex.ism", {"brown", 0.85m}, ["Anders", "Redmond", "USA"]},



using System;
using System.Collections.Generic;


public class Authenticator
{
    // TODO: Implement the Authenticator.Admin property
    public Identity Admin => new Identity{
        Email = "admin@ex.ism", 
        FacialFeatures = new FacialFeatures{ EyeColor = "green", PhiltrumWidth = 0.9m }, 
        NameAndAddress = new List<string>{ "Chanakya", "Mumbai", "India" }
    };

    // TODO: Implement the Authenticator.Developers property
    public IDictionary<string, Identity> Developers => new Dictionary<string, Identity> {
        {
            "Bertrand", new Identity {
                Email = "bert@ex.ism",
                FacialFeatures = new FacialFeatures { EyeColor = "blue", PhiltrumWidth = 0.8m },
                NameAndAddress = new List<string> { "Bertrand", "Paris", "France" }
            }
        },
        {
            "Anders", new Identity {
                Email = "anders@ex.ism",
                FacialFeatures = new FacialFeatures { EyeColor = "brown", PhiltrumWidth = 0.85m },
                NameAndAddress = new List<string> { "Anders", "Redmond", "USA" }
            }
        }
    };
}

//**** please do not modify the FacialFeatures class ****
public class FacialFeatures
{
    public required string EyeColor { get; set; }
    public required decimal PhiltrumWidth { get; set; }
}

//**** please do not modify the Identity class ****
public class Identity
{
    public required string Email { get; set; }
    public required FacialFeatures FacialFeatures { get; set; }
    public required IList<string> NameAndAddress { get; set; }
}
