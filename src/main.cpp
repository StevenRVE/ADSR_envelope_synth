#include <iostream>
#include "port_audio/port_audio.h"
#include "port_audio/audioModuleAdapter.h"


int main() {
    auto sampleRate = 44100;
    auto blockSize = 64;

    AudioModuleAdapter audioProcess;

    PortAudio portAudio { audioProcess };
    portAudio.setup(sampleRate, blockSize);

    std::cout << "Press 'q' to quit the program.\n";
    bool running = true;
    while (running)
    {
        switch(std::cin.get())
        {
            case 'q':
                running = false;
                portAudio.teardown();
                break;
            case 'a':
                audioProcess.synth->noteOn(500);
            case 'z':
                audioProcess.synth->noteOff();
        }
    }

    return 0;
}
