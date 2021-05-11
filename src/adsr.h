//
// Created by steve on 5/11/2021.
//

#ifndef ADSR_ENVELOPE_ADSR_H
#define ADSR_ENVELOPE_ADSR_H

#include <iostream>

struct Adsr
{
    Adsr() = default;

    Adsr(int attack, int decay, int release) : attack(attack), decay(decay), release(release)
    {
        std::cout << "ADR - constructor\n";
    }

    Adsr(int attack, int decay, double sustain, int release) : attack(attack), decay(decay), sustain(sustain), release(release)
    {
        std::cout << "ADSR - constructor\n";
    }

    ~Adsr();

    int attack = 200;
    int decay = 100;
    double sustain = 0.5;
    int release = 100;
};

#endif //ADSR_ENVELOPE_ADSR_H
