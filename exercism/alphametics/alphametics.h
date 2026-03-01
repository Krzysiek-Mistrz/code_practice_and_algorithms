#pragma once

#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <optional>
#include <string>


namespace alphametics {

struct LetterInfo {
    char c;
    long long weight = 0;
    bool can_be_zero = true;
};

std::optional<std::map<char, int>> solve(std::string equation);

}  // namespace alphametics