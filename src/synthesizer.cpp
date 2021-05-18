//
// Created by steve on 5/9/2021.
//

#include "synthesizer.h"
Synthesizer::Synthesizer(Clock* subject, double sampleRate, double frequency) :
Generator(subject, sampleRate),
envelope(subject, sampleRate)
{
    oscillator = new Sine(subject, sampleRate, frequency);
}

Synthesizer::~Synthesizer() = default;

void Synthesizer::noteOn(double frequency)
{
    this->oscillator->setFrequency(frequency);
    envelope.enterStage(Envelope::Adsr::attack);

}

void Synthesizer::noteOff()
{
    envelope.enterStage(Envelope::Adsr::release);
}

void Synthesizer::tick()
{
    this->oscillator->tick();
//    std::cout << "Synth::tick() is being ticked! \n";
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