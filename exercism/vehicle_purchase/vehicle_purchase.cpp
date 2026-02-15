#include "vehicle_purchase.h"

namespace vehicle_purchase {

bool needs_license(std::string kind) {
    if (kind == "car" || kind == "truck")
        return true;
    else
        return false;
}

std::string choose_vehicle(std::string option1, std::string option2) {
    if (option1 > option2)
        return option2 + " is clearly the better choice.";
    else
        return option1 + " is clearly the better choice.";
}

double calculate_resell_price(double original_price, double age) {
    if (age < 3)
        return 0.8 * original_price;
    else if (age >= 10)
       return 0.5 * original_price;
    else
        return 0.7 * original_price;
}
}  // namespace vehicle_purchase
