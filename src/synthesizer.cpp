//
// Created by steve on 5/9/2021.
//

#include "synthesizer.h"
Synthesizer::Synthesizer(double sampleRate, double frequency) : Generator(sampleRate)
{
    envelope = new Envelope(sampleRate);
    oscillator = new Square(sampleRate, frequency);
}

Synthesizer::~Synthesizer() = default;

void Synthesizer::noteOn(double frequency)
{
    this->oscillator->setFrequency(frequency);
}

void Synthesizer::noteOff(double frequency)
{

}

void Synthesizer::tick()
{
    this->oscillator->tick();
}

void Synthesizer::setFrequency(double frequency) {
    this->oscillator->setFrequency(frequency);
}

double Synthesizer::getSample()
{
    return oscillator->getSample();
}