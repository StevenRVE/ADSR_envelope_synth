//
// Created by steve on 5/9/2021.
//

#ifndef ADSR_ENVELOPE_GENERATOR_H
#define ADSR_ENVELOPE_GENERATOR_H


class Generator {
public:
    Generator();
    ~Generator();

    double getSample();
    virtual void tick();
private:
    double sample;
};


#endif //ADSR_ENVELOPE_GENERATOR_H
