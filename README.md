# ADSR Envelope Synth by Steven van Esch


This is my synthesizer with ADSR envelope.

## How it works:

### Envelop:
This envelope generator is a finite state machine. It has 5 states: off, attack, decay, sustain and release.
This means that it is always in one of these 5 states. To keep track of these states I've used an enum with all the 
envelope states. These states by itself don't do a lot yet, but they all have an integer value (off=0, attack=1, 
decay=2, sustain=4, release=5). For the actual values of each state we make an array (adsrValues[]). We have 4 important 
methods:

###### enterState():
Uses a switch to go through all the states one by one. When we enter a new state, this method resets the counter value
to zero and sets the switch to the next state. Every switch state corresponds to one of the enum states and has its own 
implementation. In the off state, the currentAmplitude is 0.0. In the other states we use a minimum level because we use 
this level for calculating the multiplier, it can't be zero. When we enter a new state, we calculate the new multiplier 
for that state.

###### calculateMultiplier():
I've used the calculateMultiplier() method by Martin Finke (which is based on Christian Schoenebeck's Fast Exponential 
Envelope Generator). Multiplier is used to increase or decrease the currentAmplitude. We calculate which multiplier we 
need to go from a startLevel to an endLevel in a given number of steps (e.g. attack time in sec * sample rate). 

###### getSample():
This functions simply checks if the envelope is in attack, decay or release mode and then returns the currentLevel. If
the sampleIndex is at the end of its state, it calls the enterState() method so we go to the next state.

###### tick():
Go to the next sample.

The envelope is triggered by the noteOn and noteOff messages from the synthesizer.

### Observer design pattern:

"The observer pattern is a software design pattern in which an object, named the subject, maintains a list of its 
dependents, called observers, and notifies them automatically of any state changes, usually by calling one of their 
methods." The observer pattern has one subject(Clock class), and many observers(generator/derived generator classes). 
The subject has a list of observers, a method for adding observers to this list and a method for notifying all the 
observers in the list. Every observer gets linked to the subject when it's made, by receiving a subject object. 
The observer's constructor then uses the attach() method from the subject to put itself in the observers list. 
When the subject is changing state (going to the next sample), it will notify all the observers in the list. This happens
for every sample at sample rate.

The reason we use the observer design pattern is, because we want al of the different modules to go to the next sample 
(using the tick()) at the same time. This way we don't have to tick all the observers individually. This is especially
useful because going to the next sample is time based. It is also useful because it makes the synthesizer modular. If we 
decide make an extra voice for the synthesizer, it will automatically be added to the observer list and work as intended.

### Sources:

##### Audio plugins: envelopes by Martin Finke:
http://www.martin-finke.de/blog/articles/audio-plugins-011-envelopes/

##### Fast exponential envelope generator by Christian Schoenebeck:
https://www.musicdsp.org/en/latest/Synthesis/189-fast-exponential-envelope-generator.html

##### static_cast:
https://en.cppreference.com/w/cpp/language/static_cast

##### enum:
- https://en.cppreference.com/w/cpp/language/enum
- https://www.youtube.com/watch?v=x55jfOd5PEE
- https://www.youtube.com/watch?v=Pxvvr5FAWxg

##### fmax:
https://www.cplusplus.com/reference/cmath/fmax/

##### switch:
https://en.cppreference.com/w/cpp/language/switch

##### Observer design pattern:
- https://sourcemaking.com/design_patterns/observer/cpp/3
- https://www.youtube.com/watch?v=_BpmfnqjgzQ&t=3s