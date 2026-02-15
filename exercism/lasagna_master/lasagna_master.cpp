#include "lasagna_master.h"
#include <cstddef>


namespace lasagna_master {

    int preparationTime(const std::vector<std::string>& layers, const int preparation_time) {
        return layers.size() * preparation_time;
    }

    amount quantities(const std::vector<std::string>& layers) {
        int noodles{};
        double sauce{};

        for (const auto& layer : layers) {
            if (layer == "sauce")
                sauce += 0.2;
            if (layer == "noodles")
                noodles += 50;
        }

        amount am{noodles, sauce};

        return am;
    }

    void addSecretIngredient(std::vector<std::string>& my_ingredients, const std::vector<std::string>& friend_ingredients) {
        my_ingredients.at(my_ingredients.size() - 1) = friend_ingredients.at(friend_ingredients.size() - 1);
    }

    std::vector<double> scaleRecipe(const std::vector<double>& amounts, const int num_of_portions) {
        std::vector<double> scaled_amounts{amounts};
        
        for (size_t i{0}; i < amounts.size(); ++i)
            scaled_amounts.at(i) = amounts.at(i) * (num_of_portions / 2.0);

        return scaled_amounts;
    }

    void addSecretIngredient(std::vector<std::string>& my_ingredients, const std::string& aunt_ingredients) {
        my_ingredients.at(my_ingredients.size() - 1) = aunt_ingredients;
    }

}  // namespace lasagna_master
