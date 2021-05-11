//
// Created by steve on 5/11/2021.
//

#ifndef ADSR_ENVELOPE_SAW_H
#define ADSR_ENVELOPE_SAW_H

#include "oscillator.h"
#include <cmath>

class Saw : public Oscillator{
public:
    Saw(double sampleRate);

    ~Saw();

    void tick() override;
};


#endif //ADSR_ENVELOPE_SAW_H
