
#include <Stepper.h>

const int stepsPerRevolution = 2048;
const int steps[] = { 256, -512, 768, -1024, 1280, -1792, 2048, 2048, 2048, 2048, -512, 1024, -1536 };
const int delays[] = { 50, 100, 200, 300, 400, 500, 2000, 0, 0, 0, 300, 200, 100 };
Stepper stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  stepper.setSpeed(10);
}

void loop() {
  delay(5000);
  for (size_t i = 0; i < sizeof steps / sizeof *steps; i++) {
    stepper.step(steps[i]);
    delay(delays[i]);
  }
  delay(5000);
}
