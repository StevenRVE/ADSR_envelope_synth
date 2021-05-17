//
// Created by steve on 5/11/2021.
//

#ifndef ADSR_ENVELOPE_SQUARE_H
#define ADSR_ENVELOPE_SQUARE_H

#include "oscillator.h"

class Square : public Oscillator{
public:
    Square(Clock* subject, double sampleRate, double frequency);

    ~Square();

    void tick() override;
};


#endif //ADSR_ENVELOPE_SQUARE_H
