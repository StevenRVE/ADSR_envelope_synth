//
// Created by steve on 5/9/2021.
//

#ifndef ADSR_ENVELOPE_SYNTHESIZER_H
#define ADSR_ENVELOPE_SYNTHESIZER_H

#include "generator.h"
#include "sine.h"

class Synthesizer : public Generator {
public:
    Synthesizer(double sampleRate);

    ~Synthesizer();

    void noteOn(double frequency);

    void noteOff(double frequency);

protected:
    Sine sine;
};


#endif //ADSR_ENVELOPE_SYNTHESIZER_H
