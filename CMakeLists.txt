cmake_minimum_required(VERSION 3.19)
project(ADSR_Envelope)

include(FetchContent)
FetchContent_Declare(port_audio GIT_REPOSITORY "https://github.com/PortAudio/portaudio.git")
FetchContent_MakeAvailable(port_audio)

add_executable(ADSR_Envelope
        src/main.cpp src/generator.cpp src/generator.h src/oscillator.cpp src/oscillator.h
        src/sine.cpp src/sine.h src/synthesizer.cpp src/synthesizer.h src/voice.cpp src/voice.h src/envelope.cpp
        src/envelope.h src/saw.cpp src/saw.h src/square.cpp src/square.h src/adsr.h
        src/port_audio/port_audio.h src/port_audio/audioModuleAdapter.cpp src/port_audio/audioModuleAdapter.h)

target_link_libraries(ADSR_Envelope PRIVATE portaudio_static)
target_compile_features(ADSR_Envelope PRIVATE cxx_std_17)