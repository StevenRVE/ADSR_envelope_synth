//
// Created by steve on 5/9/2021.
//

#include "generator.h"

Generator::Generator(Clock* subject, double sampleRate) : sampleRate(sampleRate), clock(subject)
{
    clock->attach(this);
}

Generator::~Generator() = default;

double Generator::getSample() {
    return sample;
}

void Generator::tick() {

}

void Generator::setFrequency(double frequency) {

}

double Generator::getFrequency() {
    return 0;
}
