//
// Created by steve on 5/9/2021.
//

#ifndef ADSR_ENVELOPE_ENVELOPE_H
#define ADSR_ENVELOPE_ENVELOPE_H

#include "generator.h"
#include "adsr.h"

class Envelope : public Generator {
public:
    Envelope(double sampleRate);
    ~Envelope();

    void tick() override;

private:
    Adsr adsr;
};


#endif //ADSR_ENVELOPE_ENVELOPE_H
