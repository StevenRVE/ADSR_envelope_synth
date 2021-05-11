//
// Created by steve on 5/9/2021.
//

#include "envelope.h"

Envelope::Envelope(double sampleRate) : Generator(sampleRate), adsr()
{

}

Envelope::~Envelope() = default;

void Envelope::tick() {

}