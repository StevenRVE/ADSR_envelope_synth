//
// Created by steve on 5/9/2021.
//

#include "oscillator.h"


Oscillator::Oscillator(Clock* subject, double sampleRate) : Generator(subject, sampleRate) {

}

Oscillator::~Oscillator() = default;

double Oscillator::getFrequency()
{
    return frequency;
}

void Oscillator::setFrequency(double frequency)
{
    this->frequency = frequency;
}
