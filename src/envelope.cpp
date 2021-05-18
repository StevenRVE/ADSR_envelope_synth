//
// Created by steve on 5/9/2021.
// based on Martin Finke's blog about envelopes: http://www.martin-finke.de/blog/articles/audio-plugins-011-envelopes/
//

#include "envelope.h"

Envelope::Envelope(Clock* subject, double sampleRate) :
Generator(subject, sampleRate),
minimumLevel(0.0001),
currentStage(off),
currentLevel(minimumLevel),
multiplier(1.0),
currentSampleIndex(0),
nextStageSampleIndex(0)
{
    stageValue[off] = 0.0;
    stageValue[attack] = 1.2;
    stageValue[decay] = 2.0;
    stageValue[sustain] = 0.4;
    stageValue[release] = 0.8;
}

Envelope::~Envelope() = default;

void Envelope::tick()
{
    if (currentStage != off && currentStage != sustain)
    {
        currentSampleIndex++;
    }

}

void Envelope::enterStage(Envelope::Adsr newStage)
{
    currentStage = newStage;
    currentSampleIndex = 0;
    if (currentStage == off || currentStage == sustain)
    {
        nextStageSampleIndex = 0;
    }
    else
    {
        nextStageSampleIndex = stageValue[currentStage] * sampleRate;
    }
    switch (newStage) {
        case off:
            currentLevel = 0.0;
            multiplier = 1.0;
            std::cout << "Adsr: off\n";
            break;
        case attack:
            currentLevel = minimumLevel;
            calculateMultiplier(currentLevel, 1.0, nextStageSampleIndex);
            std::cout << "Adsr: attack\n";
            break;
        case decay:
            currentLevel = 1.0;
            calculateMultiplier(currentLevel, fmax(stageValue[sustain], minimumLevel), nextStageSampleIndex);
            std::cout << "Adsr: decay\n";
            break;
        case sustain:
            currentLevel = stageValue[sustain];
            multiplier = 1.0;
            std::cout << "Adsr: sustain\n";
            break;
        case release:
            calculateMultiplier(currentLevel, minimumLevel, nextStageSampleIndex);
            std::cout << "Adsr: release\n";
            break;
        default:
            break;
    }
}

// while in attack, decay or release stage, this function checks if the currentSampleIndex is equal to
// nextStageSampleIndex and if not is ticks to the next index. If it is equal, we go to the next Adsr
double Envelope::getSample()
{
    if (currentStage != off && currentStage != sustain)
    {
        if (currentSampleIndex == nextStageSampleIndex)
        {
            Adsr newStage;
            newStage = static_cast<Adsr>((currentStage + 1) % numEnvelopeStages);
            enterStage(newStage);
        }
        currentLevel *= multiplier;
    }
    return currentLevel;
}

// multiplier to make the currentLevel exponential so we hear it linear
// based on https://www.musicdsp.org/en/latest/Synthesis/189-fast-exponential-envelope-generator.html
// and http://www.martin-finke.de/blog/articles/audio-plugins-011-envelopes/
void Envelope::calculateMultiplier(double startLevel, double endLevel, unsigned long long int lengthInSamples) {
    multiplier = 1.0 + (log(endLevel) - log(startLevel)) / (lengthInSamples);
}


