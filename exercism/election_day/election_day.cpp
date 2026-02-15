#include <cstddef>
#include <string>
#include <vector>


namespace election {

struct ElectionResult {
    std::string name{};
    int votes{};
};

int vote_count(ElectionResult& er) {
    return er.votes;
}

void increment_vote_count(ElectionResult& er, int num_of_votes) {
    er.votes += num_of_votes;
}

ElectionResult& determine_result(std::vector<ElectionResult>& results) {
    int winner_ind{0};

    for (size_t i{0}; i < results.size(); ++i) {
        if (results[i].votes > results[winner_ind].votes) {
            winner_ind = i;
        }
    }

    results[winner_ind].name = "President " + results[winner_ind].name;

    return results[winner_ind];
}

}  // namespace election
