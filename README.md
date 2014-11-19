# Modus

Small Arduino library for mode control.

**Tested on an Arduino Due only.**

## Instructions

Include the library in your sketch:

    #include <Modus.h>

### Constrctor

Just created a Modus object with the number of modes you need.

This creates 4 Modes, plus Mode 0, which is the default mode on start-up.

    Modus modes(4);

### Functions

Modus has 4 functions.

#### mode()

Returns the current mode, you can compare modes using the corresponding numbers or set some #defines like in the examples.

    modes.mode() == 4 // true if the current mode is Mode number 4, false otherwise.

#### set(mode)

Defines the current mode, you can change to any valid Mode, invalid Modes will be ignored.

    modes.set(10); // is ignored since there's only Modes 0 to 4.
    modes.set(2); // Changes to Mode 2.
    modes.set(10) == 10; // Returns false since the change wasn't accepted.
    modes.set(4) == 4; // Changes to Mode 4 and returns true.

#### status(mode)

Compares the function parameter to the current Mode, returns true if they are the same, false otherwise.

    modes.status(1); // Returns true if 1 is the current active Mode.

#### state(mode)

The same as status(mode), but returns HIGH/LOW instead of true/false.

    modes.status(1); // Returns HIGH if 1 is the current active Mode.
