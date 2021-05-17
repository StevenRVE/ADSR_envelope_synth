//
// Created by steve on 5/9/2021.
//

#include "sine.h"
#include <iostream>
#include <cmath>

Sine::Sine(Clock* subject, double sampleRate, double frequency) : Oscillator(subject, sampleRate)
{
    this->setFrequency(frequency);
}

Sine::~Sine() = default;

void Sine::tick()
{
    phase += frequency / sampleRate;
    sample = sin(TWOPI * phase);
}