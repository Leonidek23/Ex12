// Copyright Leonidek23 2021
#include "TimedDoor.h"
#include <iostream>


int main() {
    TimedDoor tDoor(5);
    time_t start = time(nullptr);
    time_t finish;
    try {
        tDoor.unlock();
    }
    catch(std::string message) {
        finish = time(nullptr);
        int delta = finish - start;
        std::cout<<delta;
    }
    return 0;
}
