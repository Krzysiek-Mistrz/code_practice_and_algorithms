#include <iostream>


int ovenTime() {
    return 40;
}

int remainingOvenTime(int actualMinutesInOven) {
    int remainingTime = ovenTime() - actualMinutesInOven;
    return remainingTime;
}

int preparationTime(int numberOfLayers) {
    int preparationTime = numberOfLayers * 2;
    return preparationTime;
}

int elapsedTime(int numberOfLayers, int actualMinutesInOven) {
    return actualMinutesInOven + preparationTime(numberOfLayers);
}