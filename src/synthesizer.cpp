//
// Created by steve on 5/9/2021.
//

#include "synthesizer.h"
Synthesizer::Synthesizer(Clock* subject, double sampleRate, double frequency) :
Generator(subject, sampleRate),
envelope(subject, sampleRate),
oscillator(subject, sampleRate, frequency)
{

}

Synthesizer::~Synthesizer() = default;

void Synthesizer::noteOn(double frequency)
{
    this->oscillator.setFrequency(frequency);
    envelope.enterState(Envelope::Adsr::attack);
}

void Synthesizer::noteOff()
{
    envelope.enterState(Envelope::Adsr::release);
}

void Synthesizer::tick()
{
    this->oscillator.tick();
//    std::cout << "Synth::tick() is being ticked! \n";
}

void Synthesizer::setFrequency(double frequency) {
    this->oscillator.setFrequency(frequency);
}

double Synthesizer::getSample()
{
    double sample;
    sample = oscillator.getSample() * envelope.getSample();
    return sample;
}

void Synthesizer::setAdsrValues(double att, double dec, double sus, double rel) {
    envelope.setAttack(att);
    envelope.setDecay(dec);
    envelope.setSustain(sus);
    envelope.setRelease(rel);
}
