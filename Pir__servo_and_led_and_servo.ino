#include<Servo.h> 

#define PIR_PIN 2       // PIR sensor input pin
#define LED_PIN 4       // LED control pin
#define SERVO_PIN 9     // Servo motor control pin

int servoAngle = 0;    // Initial angle for the servo motor
Servo myServo;         // Servo object

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT); // Set LED pin as OUTPUT
  myServo.attach(SERVO_PIN);
  Serial.begin(9600);
}

void loop() {
  int pirValue = digitalRead(PIR_PIN);

  if (pirValue == HIGH) {
    Serial.println("Motion detected!");

    // Turn on the LED
    digitalWrite(LED_PIN, HIGH);

    // Open the door using the servo motor
    openDoor();

    // Wait for some time (adjust as needed)
    delay(5000);

    // Close the door using the servo motor
    closeDoor();

    // Turn off the LED
    digitalWrite(LED_PIN, LOW);

    Serial.println("Motion stopped.");
  }

  delay(100); // Adjust delay as needed
}

void openDoor() {
  // Move the servo motor to open the door
  for (int angle = 0; angle <= 90; angle += 1) {
    myServo.write(angle);
    delay(15);
  }
}

void closeDoor() {
  // Move the servo motor to close the door
  for (int angle = 90; angle >= 0; angle -= 1) {
    myServo.write(angle);
    delay(15);
  }
}
