#include "allergies.h"


namespace allergies {

bool Person::is_allergic_to(const std::string& allergy) {
    if (allergy.empty()) {
        return false;
    } else {
        return allergies_names.find(allergy) != allergies_names.end();
    }
}

const std::unordered_set<std::string>& Person::get_allergies() const {
    return allergies_names;
}

void Person::add_alergy(const std::string& allergy) {
    allergies_names.emplace(allergy);
}

Person allergy_test(int score) {
    Person p;

    static const std::map<int, std::string> table {
        {1, "eggs"}, {2, "peanuts"}, {4, "shellfish"}, {8, "strawberries"},
        {16, "tomatoes"}, {32, "chocolate"}, {64, "pollen"}, {128, "cats"}
    };

    for (const auto& item : table) {
        if ((score & item.first) != 0)
            p.add_alergy(item.second);
    }

    return p;
}

}  // namespace allergies
