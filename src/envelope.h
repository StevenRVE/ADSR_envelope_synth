//
// Created by steve on 5/9/2021.
// based on Martin Finke's blog about envelopes: http://www.martin-finke.de/blog/articles/audio-plugins-011-envelopes/
//

#ifndef ADSR_ENVELOPE_ENVELOPE_H
#define ADSR_ENVELOPE_ENVELOPE_H

#include "generator.h"
#include <iostream>

class Envelope : public Generator {
public:
    Envelope(Clock* subject, double sampleRate);
    ~Envelope();

    enum Adsr {
        off = 0,
        attack,
        decay,
        sustain,
        release,
        numEnvelopeStates
    };

    void enterState(Adsr newState);

    double getSample() override;

    void tick() override;

    void setAttack(double att);

    void setDecay(double dec);

    void setSustain(double sus);

    void setRelease(double rel);

private:
    Adsr currentState;

    const double minimumLevel;

    double currentAmplitude;
    double multiplier;
    double adsrValue[numEnvelopeStates];

    void calculateMultiplier(double startLevel, double endLevel, unsigned long long lengthInSamples);

    unsigned int currentSampleIndex;
    unsigned int nextStateSampleIndex;
};


#endif //ADSR_ENVELOPE_ENVELOPE_H
