#include "alphametics.h"
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>


namespace alphametics {

std::optional<std::map<char, int>> solve(std::string equation) {
    std::map<char, long long> weights;
    std::set<char> leading;
    std::vector<std::string> words;
    std::string current_word;

    auto process_side = [&](std::string side, int sign) {
        std::string word;
        for (auto i = 0u; i <= side.length(); ++i) {
            if (i == side.length() || side[i] == ' ' || side[i] == '+') {
                if (!word.empty()) {
                    if (word.length() > 1) leading.insert(word[0]);
                    long long multiplier = sign;
                    for (int j = word.length() - 1; j >= 0; --j) {
                        weights[word[j]] += multiplier;
                        multiplier *= 10;
                    }
                    word = "";
                }
            } else {
                word += side[i];
            }
        }
    };

    auto eq_pos = equation.find(" == ");
    process_side(equation.substr(0, eq_pos), 1);
    process_side(equation.substr(eq_pos + 4), -1);

    std::vector<LetterInfo> letters;
    for (auto const& [c, w] : weights) {
        letters.push_back({c, w, leading.find(c) == leading.end()});
    }

    std::sort(letters.begin(), letters.end(), [](const auto& a, const auto& b) {
        return std::abs(a.weight) > std::abs(b.weight);
    });

    std::map<char, int> solution;
    std::vector<bool> used(10, false);

    auto backtrack = [&](auto self, size_t idx, long long current_sum) -> bool {
        if (idx == letters.size()) {
            return current_sum == 0;
        }

        const auto& info = letters[idx];
        for (int digit = 0; digit <= 9; ++digit) {
            if (!used[digit]) {
                if (digit == 0 && !info.can_be_zero) continue;

                used[digit] = true;
                solution[info.c] = digit;
                if (self(self, idx + 1, current_sum + digit * info.weight)) return true;
                used[digit] = false;
            }
        }
        return false;
    };

    if (backtrack(backtrack, 0, 0)) return solution;
    return std::nullopt;
}

}  // namespace alphametics