//
// Created by steve on 5/9/2021.
//

#include "oscillator.h"

Oscillator::Oscillator()
{

}

Oscillator::~Oscillator()
{

}

double Oscillator::getFrequency()
{
    return frequency;
}

void Oscillator::setFrequency(double frequency)
{
    this->frequency = frequency;
}

