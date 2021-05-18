//
// based on Martin Finke's blog about envelopes: http://www.martin-finke.de/blog/articles/audio-plugins-011-envelopes/
// altered by Steven van Esch
//

#include "envelope.h"

Envelope::Envelope(Clock* subject, double sampleRate) :
        Generator(subject, sampleRate),
        minimumLevel(0.0001),
        currentState(off),
        currentAmplitude(minimumLevel),
        multiplier(1.0),
        currentSampleIndex(0),
        nextStateSampleIndex(0)
{
    adsrValue[off] = 0.0;
    adsrValue[attack] = 0.1;
    adsrValue[decay] = 0.5;
    adsrValue[sustain] = 0.4;
    adsrValue[release] = 0.3;
}

Envelope::~Envelope() = default;

void Envelope::tick()
{
    if (currentState != off && currentState != sustain)
    {
        currentSampleIndex++;
    }
}

void Envelope::enterState(Envelope::Adsr newState)
{
    currentState = newState;
    currentSampleIndex = 0;
    if (currentState == off || currentState == sustain)
    {
        nextStateSampleIndex = 0;
    }
    else
    {
        nextStateSampleIndex = adsrValue[currentState] * sampleRate;
    }
    switch (newState) {
        case off:
            currentAmplitude = 0.0;
            multiplier = 1.0;
            break;
        case attack:
            currentAmplitude = minimumLevel;
            calculateMultiplier(currentAmplitude, 1.0, nextStateSampleIndex);
            break;
        case decay:
            currentAmplitude = 1.0;
            calculateMultiplier(currentAmplitude, fmax(adsrValue[sustain], minimumLevel), nextStateSampleIndex);
            break;
        case sustain:
            currentAmplitude = adsrValue[sustain];
            multiplier = 1.0;
            break;
        case release:
            calculateMultiplier(currentAmplitude, minimumLevel, nextStateSampleIndex);
            break;
        default:
            break;
    }
}

// while in attack, decay or release stage, this function checks if the currentSampleIndex is equal to
// nextStateSampleIndex and if not is ticks to the next index. If it is equal, we go to the next Adsr state
double Envelope::getSample()
{
    if (currentState != off && currentState != sustain)
    {
        if (currentSampleIndex == nextStateSampleIndex)
        {
            Adsr newState;
            newState = static_cast<Adsr>((currentState + 1) % numEnvelopeStates);
            enterState(newState);
        }
        currentAmplitude *= multiplier;
    }
    return currentAmplitude;
}

// multiplier to make the currentAmplitude exponential so we hear it linear
// based on https://www.musicdsp.org/en/latest/Synthesis/189-fast-exponential-envelope-generator.html
// and http://www.martin-finke.de/blog/articles/audio-plugins-011-envelopes/
void Envelope::calculateMultiplier(double startLevel, double endLevel, unsigned long long int lengthInSamples) {
    multiplier = 1.0 + (log(endLevel) - log(startLevel)) / (lengthInSamples);
}

void Envelope::setAttack(double att) {
    adsrValue[attack] = att;
}

void Envelope::setDecay(double dec) {
    adsrValue[decay] = dec;
}

void Envelope::setSustain(double sus) {
    adsrValue[sustain] = sus;
}

void Envelope::setRelease(double rel) {
    adsrValue[release] = rel;
}

