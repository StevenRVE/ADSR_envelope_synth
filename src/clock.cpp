//
// Created by steve on 5/17/2021.
//

#include "clock.h"

void Clock::tick() {
    for (long unsigned int i = 0; i < observerList.size(); i++) {
        observerList[i]->tick();
    }
}

void Clock::attach(Generator* generator) {
    observerList.push_back(generator);
}
