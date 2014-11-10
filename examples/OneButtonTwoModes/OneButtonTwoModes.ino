#include <Modus.h>

#define NONE  0 // You can use Mode 0 too if you want.
#define LAZY  1 // You can choose any name and any order.
#define WORK  2 // Don't go redefining language names, like pinMode or void

// When the button is HIGH, led1 is ON.
// When the button is LOW, Led2 is ON.

Modus mode(2); // Creates 2 modes + Mode 0 which will always exist.
byte button = 22;
byte led1 = 23;
byte led2 = 25;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // Automatically starts into mode 0 (None).

  if (digitalRead(button) == HIGH) {
    mode.set(WORK); // Enters into Work mode (Mode 2).
  } else {
    mode.set(LAZY); // Enters into Lazy mode (Mode 1).
  }

  digitalWrite(led1, mode.state(WORK));

  if (mode.status(LAZY)) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }
}
