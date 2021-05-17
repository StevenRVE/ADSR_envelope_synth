//
// Created by steve on 5/9/2021.
//

#ifndef ADSR_ENVELOPE_GENERATOR_H
#define ADSR_ENVELOPE_GENERATOR_H

#include "clock.h"

class Generator {
public:
    Generator(class Clock* clock, double sampleRate);
    ~Generator();

    virtual double getSample();

    virtual void tick();

    virtual void setFrequency(double frequency);

    virtual double getFrequency();

protected:
    class Clock* clock;

    double sample{};
    double sampleRate;
};


#endif //ADSR_ENVELOPE_GENERATOR_H
