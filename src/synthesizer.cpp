//
// Created by steve on 5/9/2021.
//

#include "synthesizer.h"
Synthesizer::Synthesizer(double sampleRate, double frequency) :
Generator(sampleRate),
envelope(sampleRate)
{
    oscillator = new Square(sampleRate, frequency);
}

Synthesizer::~Synthesizer() = default;

void Synthesizer::noteOn(double frequency)
{
    this->oscillator->setFrequency(frequency);
    if (envelope.getCurrentStage() == Envelope::EnvelopeStage::off) {
        envelope.enterStage(Envelope::EnvelopeStage::attack);
    }
}

void Synthesizer::noteOff()
{
    if (envelope.getCurrentStage() == Envelope::EnvelopeStage::sustain) {
        envelope.enterStage(Envelope::EnvelopeStage::release);
    }
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
    double sample;
    sample = oscillator->getSample() * envelope.getSample();
    return sample;
}