#include <Servo.h>

Servo RedServo;

int servoPin = 9;
int ServoPosition = 90;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  RedServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String inputString = Serial.readString();
    Serial.print("Connected!");
    Serial.println(inputString);
    if (inputString.startsWith("تحت")) {
      Serial.println("Down");
      for (ServoPosition = 0; ServoPosition <= 180; ServoPosition++)
      {
        RedServo.write(ServoPosition);
        delay(50);
      }
    }
    else if (inputString.startsWith("فوق"))
    {
      Serial.println("Up");
      for (ServoPosition = 180; ServoPosition >= 0; ServoPosition--)
      {
        RedServo.write(ServoPosition);
        delay(50);
      }
    }
  }

}
