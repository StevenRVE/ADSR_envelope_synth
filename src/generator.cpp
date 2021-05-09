//
// Created by steve on 5/9/2021.
//

#include "generator.h"

Generator::Generator(double sampleRate) : sampleRate(sampleRate)
{

}

Generator::~Generator() = default;

double Generator::getSample() {
    return sample;
}

void Generator::tick() {

}
