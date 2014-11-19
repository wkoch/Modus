/*
  Modus - v1.0 - November 10, 2014.
  Arduino library for mode control.
  Created by William Koch.
  Released into the public domain.
*/

#ifndef Modus_h
#define Modus_h

#include "Arduino.h"

class Modus {
  public:
    // Creates n modes.
    // USAGE: Modus Name(number);
    Modus(byte modes);

    byte mode();
    byte set(byte mode);
    boolean status(byte mode);
    byte state(byte mode);
  private:
    byte _modes, _mode;
    boolean _active;
};

#endif
