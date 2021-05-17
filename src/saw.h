//
// Created by steve on 5/11/2021.
//

#ifndef ADSR_ENVELOPE_SAW_H
#define ADSR_ENVELOPE_SAW_H

#include "oscillator.h"

class Saw : public Oscillator{
public:
    Saw(Clock* subject, double sampleRate, double frequency);

    ~Saw();

    void tick() override;
};


#endif //ADSR_ENVELOPE_SAW_H
