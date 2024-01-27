#include <Arduino.h>

const int LedPin = LED_BUILTIN;
const int BlinkTime = 250;

void setup() {
    pinMode(LedPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
    Serial.println("ON");
    digitalWrite(LedPin, HIGH);
    delay(BlinkTime);
    Serial.println("OFF");
    digitalWrite(LedPin, LOW);
    delay(BlinkTime);
}
