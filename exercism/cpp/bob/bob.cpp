#include "bob.h"


namespace bob {

bool is_shouting(const std::string& input) {
    bool has_letters = std::any_of(input.begin(), input.end(), [](unsigned char c) {
        return std::isalpha(c);
    });
    bool no_lowercase = std::none_of(input.begin(), input.end(), [](unsigned char c) {
        return std::islower(c);
    });

    return has_letters and no_lowercase;
}

std::string hey(std::string input) {
    const std::string whitespace = " \t\n\r\f\v";
    size_t first = input.find_first_not_of(whitespace);

    if (first == std::string::npos) {
        return "Fine. Be that way!";
    }

    size_t last = input.find_last_not_of(whitespace);
    std::string clean_input = input.substr(first, last - first + 1);
    bool shouting = is_shouting(clean_input);
    bool questioning = clean_input.back() == '?';

    if (questioning and shouting) {
        return "Calm down, I know what I'm doing!";
    } else if (questioning) {
        return "Sure.";
    } else if (shouting) {
        return "Whoa, chill out!";
    } else {
        return "Whatever.";
    }
}

}  // namespace bob