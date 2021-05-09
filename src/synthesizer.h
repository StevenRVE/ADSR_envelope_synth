//
// Created by steve on 5/9/2021.
//

#ifndef ADSR_ENVELOPE_SYNTHESIZER_H
#define ADSR_ENVELOPE_SYNTHESIZER_H

#include "generator.h"

class Synthesizer : public Generator {
public:
    Synthesizer(double sampleRate);

    ~Synthesizer();

    void noteOn();

    void noteOff();

protected:

};


#endif //ADSR_ENVELOPE_SYNTHESIZER_H
