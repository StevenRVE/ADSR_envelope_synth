//
// Created by steve on 5/9/2021.
//

#ifndef ADSR_ENVELOPE_SINE_H
#define ADSR_ENVELOPE_SINE_H

#include "oscillator.h"

class Sine : public Oscillator{
public:
    Sine(double sampleRate, double frequency);

    ~Sine();

    void tick() override;

};


#endif //ADSR_ENVELOPE_SINE_H
