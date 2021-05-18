//
// Created by steve on 5/9/2021.
//

#ifndef ADSR_ENVELOPE_SYNTHESIZER_H
#define ADSR_ENVELOPE_SYNTHESIZER_H

#include "generator.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "envelope.h"

class Synthesizer : public Generator {
public:
    Synthesizer(Clock* subject, double sampleRate, double frequency);

    ~Synthesizer();

    void noteOn(double frequency);

    void noteOff();

    void tick() override;

    void setFrequency(double frequency) override;

    double getSample() override;

    void setAdsrValues(double att, double dec, double sus, double rel);

protected:
    Sine oscillator;
    Envelope envelope;
};


#endif //ADSR_ENVELOPE_SYNTHESIZER_H
