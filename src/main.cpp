#include <iostream>
#include <vector>
#include "port_audio/port_audio.h"
#include "port_audio/audioModuleAdapter.h"

// TODO add voice class for polyphony

int main() {
    auto sampleRate = 44100;
    auto blockSize = 64;

    AudioModuleAdapter audioProcess;

    PortAudio portAudio { audioProcess };
    portAudio.setup(sampleRate, blockSize);

    audioProcess.synth->setAdsrValues(0.1, 0.4, 0.5, 1.0);

    std::cout << "Try the following input messages:\n";
    std::cout << "Press 'a','s','d','f','g','h','j' to trigger noteOn\n";
    std::cout << "Press 'z','x','c','v','b','n','m' to trigger noteOff\n";
    std::cout << "Press 'q' to quit the program.\n";

    // TODO make better system for capturing keyPressed or use virtual midi keyboard or midi keyboard input
    bool running = true;
    while (running)
    {
        switch(std::cin.get())
        {
            case 'q':
                running = false;
                portAudio.teardown();
                break;
            // Key: C
            case 'a':
                audioProcess.synth->noteOn(130.81);
                break;
            case 'z':
                audioProcess.synth->noteOff();
                break;
            // Key: D
            case 's':
                audioProcess.synth->noteOn(146.83);
                break;
            case 'x':
                audioProcess.synth->noteOff();
                break;
            // Key: E
            case 'd':
                audioProcess.synth->noteOn(164.81);
                break;
            case 'c':
                audioProcess.synth->noteOff();
                break;
            // Key: F
            case 'f':
                audioProcess.synth->noteOn(	174.61);
                break;
            case 'v':
                audioProcess.synth->noteOff();
                break;
            // Key: G
            case 'g':
                audioProcess.synth->noteOn(	196.00);
                break;
            case 'b':
                audioProcess.synth->noteOff();
                break;
            // Key: A
            case 'h':
                audioProcess.synth->noteOn(	220.00);
                break;
            case 'n':
                audioProcess.synth->noteOff();
                break;
            // Key: B
            case 'j':
                audioProcess.synth->noteOn(	246.94);
                break;
            case 'm':
                audioProcess.synth->noteOff();
                break;
        }
    }

    return 0;
}
