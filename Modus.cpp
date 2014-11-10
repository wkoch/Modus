/*
  Modus.cpp - v1.0 - November 10, 2014.
  Arduino library for mode control.
  Created by William Koch.
  Released into the public domain.
*/

#include "Modus.h"

#define BETWEEN(x, a, b)  ((a) <= (x) && (x) <= (b))

// Creates n modes.
Modus::Modus(byte modes) {
  _modes = modes;
  _mode = 0;
  _active = false;
}

// Returns the current mode.
byte Modus::mode() {
  return _mode;
}

byte Modus::set(byte mode) {
  if (BETWEEN(mode, 0, _modes)) {
    _mode = mode;
  }
  return _mode;
}

boolean Modus::status(byte mode) {
  if (_mode == mode) {
    return true;
  } else {
    return false;
  }
}

byte Modus::state(byte mode) {
  if (_mode == mode) {
    return HIGH;
  } else {
    return LOW;
  }
}
