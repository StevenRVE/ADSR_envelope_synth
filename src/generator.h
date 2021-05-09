//
// Created by steve on 5/9/2021.
//

#ifndef ADSR_ENVELOPE_GENERATOR_H
#define ADSR_ENVELOPE_GENERATOR_H



class Generator {
public:
    Generator(double sampleRate);
    ~Generator();

    double getSample();

    virtual void tick();

protected:
    double sample{};
    double sampleRate;
};


#endif //ADSR_ENVELOPE_GENERATOR_H
