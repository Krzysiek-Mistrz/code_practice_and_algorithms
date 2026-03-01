#include "high_scores.h"


namespace arcade {

std::vector<int> HighScores::list_scores() {
    return scores;
}

int HighScores::latest_score() {
    return scores.back();
}

int HighScores::personal_best() {
    return *std::max_element(scores.begin(), scores.end());
}

std::vector<int> HighScores::top_three() {
    auto sorted_arr{scores};
    std::sort(sorted_arr.begin(), sorted_arr.end(), std::greater<int>());
    
    if (sorted_arr.size() < 3) {
        return sorted_arr;
    }

    return {sorted_arr[0], sorted_arr[1], sorted_arr[2]};
}

}  // namespace arcade
