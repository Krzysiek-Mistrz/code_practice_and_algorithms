#include "eliuds_eggs.h"


namespace chicken_coop {

int positions_to_quantity(int eggs) {
    int count{0};

    while (eggs > 0) {
        count += eggs % 2;
        eggs /= 2;
    }

    return count;
}

}  // namespace chicken_coop
