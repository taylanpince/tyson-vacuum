#include <Servo.h>

Servo ESC;

static int powerButtonPin = 2;
static int motorPin = 9;

int targetMotorPower = 30;
int currentMotorPower = 30;
bool motorState = false;

void setup() {
  ESC.attach(motorPin, 1000, 2000);
  pinMode(powerButtonPin, INPUT);
  digitalWrite(powerButtonPin, HIGH);
}

void loop() {
  int powerMode = digitalRead(powerButtonPin);

  if (powerMode == LOW && motorState == false) {
    motorState = true;
    targetMotorPower = 80;
  } else if (powerMode == HIGH && motorState == true) {
    motorState = false;
    targetMotorPower = 30;
  }

  if (targetMotorPower > currentMotorPower) {
    currentMotorPower += 1;
  } else if (targetMotorPower < currentMotorPower) {
    currentMotorPower -= 1;
  }
  
  ESC.write(currentMotorPower);
  delay(100);
}
