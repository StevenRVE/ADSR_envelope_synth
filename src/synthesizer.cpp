//
// Created by steve on 5/9/2021.
//

#include "synthesizer.h"
Synthesizer::Synthesizer(double sampleRate) : Generator(sampleRate), sine(sampleRate)
{

}

void Synthesizer::noteOn(double frequency) {
    sine.setFrequency(frequency);
}

void Synthesizer::noteOff(double frequency) {

}

Synthesizer::~Synthesizer() = default;