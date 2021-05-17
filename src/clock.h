//
// Created by steve on 5/17/2021.
//

#ifndef ADSR_ENVELOPE_CLOCK_H
#define ADSR_ENVELOPE_CLOCK_H
#include <vector>
#include "generator.h"


// subject
class Clock {
public:
    void tick();

    void attach(class Generator* generator);

private:
    std::vector<class Generator*> observerList;

};

#endif //ADSR_ENVELOPE_CLOCK_H
