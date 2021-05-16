//
// Created by steve on 5/11/2021.
//

#include "saw.h"

Saw::Saw(double sampleRate, double frequency) : Oscillator(sampleRate)
{
    this->setFrequency(frequency);
}

Saw::~Saw() = default;

// TODO make amplitude different for different partials
void Saw::tick()
{
    phase += frequency / sampleRate;
    double y = 0;
    for(int i=1; i<100; i++){
        y += (sin(TWOPI * phase * i)/i);
    }
    sample = y * 0.5;
}