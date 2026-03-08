#include "kindergarten_garden.h"


namespace kindergarten_garden {

std::array<Plants, 4> plants(std::string diagram, std::string name) {
    auto delimeter_pos = diagram.find('\n');
    std::string first_row = diagram.substr(0, delimeter_pos);
    std::string second_row = diagram.substr(delimeter_pos + 1);

    static const std::vector<std::string> students = {
        "Alice", "Bob", "Charlie", "David", "Eve", "Fred",
        "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"
    };
    
    int student_idx = 0;
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i] == name) {
            student_idx = i;
            break;
        }
    }

    auto to_plant = [](char c) {
        switch (c) {
            case 'C': 
                return Plants::clover; 
                break;
            case 'G':
                return Plants::grass;
                break;
            case 'R':
                return Plants::radishes;
                break;
            case 'V':
                return Plants::violets;
                break;
            default:
                return Plants::grass;
                break;
        }
    };

    int p = student_idx * 2;
    return {
        to_plant(first_row[p]), 
        to_plant(first_row[p + 1]), 
        to_plant(second_row[p]), 
        to_plant(second_row[p + 1])
    };
}

}  // namespace kindergarten_garden
