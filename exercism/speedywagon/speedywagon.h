#pragma once

#include <string>
#include <vector>


namespace speedywagon {

struct pillar_men_sensor {
    int activity{};
    std::string location{};
    std::vector<int> data{};
};

bool connection_check(pillar_men_sensor* pt);
int activity_counter(const pillar_men_sensor* arr, int size);
bool alarm_control(pillar_men_sensor* pt);
bool uv_alarm(std::vector<int> vec, pillar_men_sensor* pt);
int uv_light_heuristic(std::vector<int>* data_array);

}  // namespace speedywagon
