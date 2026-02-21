#pragma once

#include <unordered_set>
#include <string>
#include <map>


namespace allergies {

class Person {
private:
    std::unordered_set<std::string> allergies_names;

public:
    Person() = default;

    bool is_allergic_to(const std::string& allergy);

    const std::unordered_set<std::string>& get_allergies() const;

    void add_alergy(const std::string& allergy);

};

Person allergy_test(int score);
    
}  // namespace allergies
