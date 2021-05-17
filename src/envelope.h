//
// Created by steve on 5/9/2021.
// based on Martin Finke's blog about envelopes: http://www.martin-finke.de/blog/articles/audio-plugins-011-envelopes/
//

#ifndef ADSR_ENVELOPE_ENVELOPE_H
#define ADSR_ENVELOPE_ENVELOPE_H

#include "generator.h"
#include "adsr.h"

class Envelope : public Generator {
public:
    Envelope(double sampleRate);
    ~Envelope();

    enum EnvelopeStage {
        off = 0,
        attack,
        decay,
        sustain,
        release,
        numEnvelopeStages
    };

    void enterStage(EnvelopeStage newStage);
    double getSample() override;
    inline EnvelopeStage getCurrentStage() const { return currentStage; }
    const double minimumLevel;

    void tick() override;

private:
    EnvelopeStage currentStage;

    double currentLevel;
    double multiplier;
    double stageValue[numEnvelopeStages];

    void calculateMultiplier(double startLevel, double endLevel, unsigned long long lengthInSamples);

    unsigned long long currentSampleIndex;
    unsigned long long nextStageSampleIndex;
};


#endif //ADSR_ENVELOPE_ENVELOPE_H
