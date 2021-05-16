//
// Created by steve on 5/11/2021.
//

#include "square.h"

Square::Square(double sampleRate, double frequency) : Oscillator(sampleRate)
{
    this->setFrequency(frequency);
}

Square::~Square() = default;

// TODO make amplitude different for different partials
void Square::tick()
{
    phase += frequency / sampleRate;
    double y = 0;
    for(int i=1; i<50; i = i+2){
        y += (sin(TWOPI * phase * i)/i);
    }
    sample = y * 0.5;
}
