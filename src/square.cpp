//
// Created by steve on 5/11/2021.
//

#include "square.h"

Square::Square(double sampleRate) : Oscillator(sampleRate) {

}

Square::~Square() {

}

// TODO make amplitude different for different partials
void Square::tick() {
    double y = 0;
    for(int i=1; i<50; i = i+2){
        y += (sin(TWOPI * phase * i)/i);
    }
    sample = y * 0.5;
}
