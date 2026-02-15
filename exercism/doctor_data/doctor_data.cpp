#include "doctor_data.h"


heaven::Vessel::Vessel(std::string name1, int num, star_map::System system) {
    generation = num;
    current_system = system;
    name = name1;
}

heaven::Vessel heaven::Vessel::replicate(std::string obj_name) {
    heaven::Vessel obj1{obj_name, generation + 1};
    return obj1;
}

void heaven::Vessel::make_buster() {
    ++busters;
}

bool heaven::Vessel::shoot_buster() {
    if (busters > 0) {
        --busters;
        return true;
    } else {
        return false;
    }
}

std::string heaven::get_older_bob(Vessel& obj1, Vessel& obj2) {
    if (obj1.name == "Bob" || obj2.name == "Bob")
        return "Bob";
    return "";
}

bool heaven::in_the_same_system(Vessel& obj1, Vessel& obj2) {
    if (obj1.current_system == obj2.current_system)
        return true;
    return false;
}
