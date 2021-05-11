//
// Created by steve on 5/9/2021.
//

#include "sine.h"

Sine::Sine(double sampleRate) : Oscillator(sampleRate)
{

}

Sine::~Sine() = default;

void Sine::tick()
{
    phase += frequency / sampleRate;
    sample = sin(TWOPI * phase);
}