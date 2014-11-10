#include <Modus.h>

#define NONE  0 // You can use Mode 0 too if you want.
#define LAZY  1 // You can choose any name and any order.
#define WORK  2 // Don't go redefining language names, like pinMode or void
#define PARTY 3 // unless you know what you're doing.

#define BETWEEN(x, a, b)  ((a) <= (x) && (x) <= (b))

// 2 seconds auto-resetable cycle called blink.
// led is off for a second and on for one second.
// cycle auto-restarts every 2 seconds.

Modus mode(3); // Creates 3 modes + Mode 0 which is always there.
byte led1 = 23;
byte led2 = 25;
byte led3 = 27;

unsigned long t = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // Automatically starts into mode 0 (None).

  digitalWrite(led1, mode.state(WORK));

  if (mode.status(PARTY)) {
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
  }

  digitalWrite(led2, mode.state(LAZY));


  if (BETWEEN(millis(), t, t+2000)) {
    mode.set(LAZY);
  } else if (BETWEEN(millis(), t+2000, t+4000)) {
    mode.set(WORK); // Enters into Work mode (Mode 2).
  } else if (BETWEEN(millis(), t+4000, t+7000)) {
    mode.set(PARTY);
  } else {
    mode.set(NONE);
    t = millis();
  }
}
