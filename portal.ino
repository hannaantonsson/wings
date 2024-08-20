#include <Servo.h>

// Skapa servo-objekt för de två servomotorerna
Servo servo1;
Servo servo2;

// Definiera servo-pinnar
const int servo1Pin = 6; // Justera till den pinne du har kopplat servo1 till
const int servo2Pin = 7; // Justera till den pinne du har kopplat servo2 till

// Definiera start- och slutvinklar
const int startAngle1 = 0; // Utgångsläget för servo1 (rakt upp)
const int endAngle1 = 150; // Slutvinkeln för servo1 (150 grader nedåt)
const int startAngle2 = 150; // Utgångsläget för servo2 (150 grader nedåt)
const int endAngle2 = 0; // Slutvinkeln för servo2 (rakt upp)

// Definiera steglängd och fördröjning
const float stepSize = 0.1; // Antal grader per steg, finjusterat för mjukare rörelse
const int delayTime = 8000; // Fördröjning i mikrosekunder per steg

void setup() {
  // Fäst servomotorerna till sina respektive pinnar
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);

  // Ställ servomotorerna i utgångsläget
  servo1.write(startAngle1);
  servo2.write(startAngle2);
}

void loop() {
  // Rör servomotorerna från startvinkeln till slutvinkeln
  for (float angle = startAngle1; angle <= endAngle1; angle += stepSize) {
    servo1.write(angle);
    servo2.write(startAngle2 - (angle - startAngle1)); // Spegla rörelsen för servo2
    delayMicroseconds(delayTime);
  }

  // Rör servomotorerna tillbaka från slutvinkeln till startvinkeln
  for (float angle = endAngle1; angle >= startAngle1; angle -= stepSize) {
    servo1.write(angle);
    servo2.write(startAngle2 - (angle - startAngle1)); // Spegla rörelsen för servo2
    delayMicroseconds(delayTime);
  }
}
