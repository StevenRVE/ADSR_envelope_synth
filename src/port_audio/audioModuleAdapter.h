//
// PortAudio API wrapper by Wouter Ensink
//

#ifndef TRACOLOR_AUDIOMODULEADAPTER_H
#define TRACOLOR_AUDIOMODULEADAPTER_H

#include <iostream>
#include "port_audio.h"
#include "../synthesizer.h"


class AudioModuleAdapter : public AudioIODeviceCallback {
public:

    AudioModuleAdapter();

    ~AudioModuleAdapter();

    void prepareToPlay (int sampleRate, int blockSize) override;

    void process (float* input, float* output, int numSamples, int numChannels) override;

    void releaseResources() override;

    Synthesizer* synth;
    Clock ticker;
};

#endif //TRACOLOR_AUDIOMODULEADAPTER_H
