#pragma once

#include <string>
#include <vector>


namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(const std::vector<std::string>& layers, const int preparation_time = 2);
amount quantities(const std::vector<std::string>& layers);
void addSecretIngredient(std::vector<std::string>& my_ingredients, const std::vector<std::string>& friend_ingredients);
std::vector<double> scaleRecipe(const std::vector<double>& amounts, const int num_of_portions);
void addSecretIngredient(std::vector<std::string>& my_ingredients, const std::string& aunt_ingredients);

}  // namespace lasagna_master
