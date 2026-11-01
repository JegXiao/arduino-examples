#include <Arduino.h>
#include <Servo.h>
Servo myServo;

void setup() {
    Serial.begin(9600);
    pinMode(A0, INPUT);
    myServo.attach(9);
}

void loop() {
    int adc = analogRead(A0);
    double voltage = map(adc,0,1023,0,500);
    int angle = map(adc,0,1023,0,180);
    myServo.write(angle);
    voltage /= 100;
    Serial.println(voltage);
    delay(100);
}