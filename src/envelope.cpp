//
// Created by steve on 5/9/2021.
//

#include "envelope.h"

Envelope::Envelope(double sampleRate) : Generator(sampleRate)
{

}

double Envelope::ADSR() {
    return 0;
}

Envelope::~Envelope() = default;