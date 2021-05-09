//
// Created by steve on 5/9/2021.
//

#include "oscillator.h"


Oscillator::Oscillator(double sampleRate) : Generator(sampleRate) {

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
