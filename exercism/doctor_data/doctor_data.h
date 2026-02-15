#pragma once

#include <string>


namespace star_map {

    enum class System {
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };

}

namespace heaven {

class Vessel {
    private:

    public:
        Vessel(std::string name1, int num, star_map::System system = star_map::System::Sol);

        Vessel replicate(std::string obj);
        void make_buster();
        bool shoot_buster();

        star_map::System current_system{star_map::System::Sol};
        int generation{0};
        int busters{0};
        std::string name{""};
};

std::string get_older_bob(Vessel& obj1, Vessel& obj2);
bool in_the_same_system(Vessel& obj1, Vessel& obj2);

}   // heaven