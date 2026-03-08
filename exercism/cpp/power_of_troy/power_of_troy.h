#pragma once

#include <future>
#include <string>
#include <memory>


namespace troy {

struct artifact {
    artifact(std::string name) : name(name) {}
    std::string name;
};

struct power {
    power(std::string effect) : effect(effect) {}
    std::string effect;
};

class human {
private:

public:
    std::unique_ptr<artifact> possession;
    std::shared_ptr<power> own_power;
    std::shared_ptr<power> influenced_by;

    human() : possession(nullptr), own_power(nullptr), influenced_by(nullptr) {}

};

void give_new_artifact(human& human, std::string name);

void exchange_artifacts(std::unique_ptr<artifact>& artifact1, std::unique_ptr<artifact>& artifact2);

void manifest_power(human& human, std::string power_name);

void use_power(human& caster, human& target);

int power_intensity(human& human);

}  // namespace troy
