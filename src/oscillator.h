//
// Created by steve on 5/9/2021.
//

#ifndef ADSR_ENVELOPE_OSCILLATOR_H
#define ADSR_ENVELOPE_OSCILLATOR_H

#include "generator.h"
#include <cmath>

#define TWOPI 6.2831853071795864769252867665590

class Oscillator : public Generator{
public:
    Oscillator(Clock* subject, double sampleRate);
    ~Oscillator();

    double getFrequency() override;

    void setFrequency(double frequency) override;

protected:
    double frequency;
    double phase = 0;
};

#endif //ADSR_ENVELOPE_OSCILLATOR_H
