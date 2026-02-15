#include "power_of_troy.h"


namespace troy {

void give_new_artifact(human& human, std::string name) {
    human.possession = std::make_unique<artifact>(name);
}

void exchange_artifacts(std::unique_ptr<artifact>& artifact1, std::unique_ptr<artifact>& artifact2) {
    artifact1.swap(artifact2);
}

void manifest_power(human& human, std::string power_name) {
    human.own_power = std::make_shared<power>(power_name);
}

void use_power(human& caster, human& target) {
    target.influenced_by = caster.own_power;
}

int power_intensity(human& human) {
    if (human.own_power == nullptr) {
        return 0;
    } else {
        return human.own_power.use_count();
    }
}

}