#pragma once

#include <array>
#include <string>
#include <vector>


namespace kindergarten_garden {

enum class Plants {
    clover,
    grass,
    radishes,
    violets
};

std::array<Plants, 4> plants(std::string diagram, std::string name);

}  // namespace kindergarten_garden
