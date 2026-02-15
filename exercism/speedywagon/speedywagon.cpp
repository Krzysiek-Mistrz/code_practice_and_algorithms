#include "speedywagon.h"
#include <array>
#include <cstddef>
#include <vector>

namespace speedywagon {

bool connection_check(pillar_men_sensor* pt) {
    if (pt == nullptr) {
        return false;
    }
    return true;
}

int activity_counter(const pillar_men_sensor* arr, int size) {
    int total_activity{0};

    for (int i{0}; i < size; i++) {
        total_activity += (arr + i) -> activity;
    }

    return total_activity;
}

bool alarm_control(pillar_men_sensor* pt) {
    if (pt == nullptr) {
        return false;
    } else if (pt -> activity > 0) {
        return true;
    } else {
        return false;
    }
}

bool uv_alarm(pillar_men_sensor* pt) {
    if (pt == nullptr) {
        return false;
    }

    if (uv_light_heuristic(&(pt->data)) > pt -> activity)
        return true;
    else
        return false;
}

int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    
    for (auto element : *data_array) {
        avg += element;
    }

    avg /= data_array->size();
    int uv_index{};

    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    
    return uv_index;
}

}  // namespace speedywagon
