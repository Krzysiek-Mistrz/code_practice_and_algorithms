#include <array>
#include <string>
#include <vector>
#include <algorithm>


std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> scores;
    
    for (int i = 0; i < student_scores.size(); i++) {
        scores.emplace_back(static_cast<int>(student_scores[i]));
    }

    return scores;
}

int count_failed_students(std::vector<int> student_scores) {
    int count = 0;

    for (int i = 0; i < student_scores.size(); i++)
        if (student_scores.at(i) <= 40)
            ++count;

    return count;
}

std::array<int, 4> letter_grades(int highest_score) {
    int interval = (highest_score - 40) / 4;
    std::array<int, 4> arr {41, 41 + interval, 41 + 2 * interval, 41 + 3 * interval};

    return arr;
}

std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> ranking;

    for (int i{0}; i < student_scores.size(); i++) {
        ranking.emplace_back(std::to_string(i + 1) + ". " + student_names.at(i) + ": " + std::to_string(student_scores.at(i)));
    }

    return ranking;
}

std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
    auto perfect_ind = std::find(student_scores.begin(), student_scores.end(), 100);

    if (perfect_ind != student_scores.end()) {
        int interval = perfect_ind - student_scores.begin();
        return student_names.at(interval);
    } else {
        return "";
    }
}
