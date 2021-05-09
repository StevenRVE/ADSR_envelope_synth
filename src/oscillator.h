//
// Created by steve on 5/9/2021.
//

#ifndef ADSR_ENVELOPE_OSCILLATOR_H
#define ADSR_ENVELOPE_OSCILLATOR_H

#include "generator.h"

class Oscillator : public Generator{
public:
    Oscillator();
    ~Oscillator();

    double getFrequency();

    void setFrequency(double frequency);

protected:
    double frequency;
};


#endif //ADSR_ENVELOPE_OSCILLATOR_H
