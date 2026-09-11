#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(9);
}

void loop() {
  for (int sudut = 0; sudut <= 180; sudut++) {
    servo.write(sudut);
    delay(15);
  }

  for (int sudut = 180; sudut >= 0; sudut--) {
    servo.write(sudut);
    delay(15);
  }
}
