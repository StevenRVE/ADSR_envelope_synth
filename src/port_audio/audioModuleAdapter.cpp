//
// PortAudio API wrapper made by Wouter Ensink
// Altered by Steven van Esch
//

#include "audioModuleAdapter.h"

#include <utility>

AudioModuleAdapter::AudioModuleAdapter() = default;

AudioModuleAdapter::~AudioModuleAdapter() = default;

void AudioModuleAdapter::prepareToPlay (int sampleRate, int blockSize)
{
    std::cout << "starting callback\n";
    synth = new Synthesizer(&ticker, sampleRate, 440);
}

// both channels are added together in the input buffer and mixed with the synthesizer class
void AudioModuleAdapter::process (float* input, float* output, int numSamples, int numChannels)
{
    for (auto sample = 0; sample < numSamples; ++sample)
    {
        // input
        auto left = input[sample * numChannels];
        auto right = input[sample * numChannels + 1];
        auto in = (left + right) / 2;
        // output
        auto out = synth->getSample() * 0.5;
        ticker.tick();

        output[sample * numChannels] = out;
        output[sample * numChannels + 1] = out;
    }
}

void AudioModuleAdapter::releaseResources()
{
    std::cout << "stopping callback\n";
}


