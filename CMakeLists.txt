cmake_minimum_required(VERSION 3.19)
project(ADSR_Envelope)

set(CMAKE_CXX_STANDARD 14)

add_executable(ADSR_Envelope src/main.cpp src/generator.cpp src/generator.h src/oscillator.cpp src/oscillator.h src/sine.cpp src/sine.h src/synthesizer.cpp src/synthesizer.h)