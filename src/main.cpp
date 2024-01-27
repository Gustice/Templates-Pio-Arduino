#include "StatusLed.h"
#include <Arduino.h>

const int BlinkTime = 50;

static StatusLed _statusLed(LED_BUILTIN);

void setup() {
    Serial.begin(9600);
    _statusLed.Set(StatusLed::Mode::DoubleFlash);
}

void loop() {
    Serial.print("Tick ");
    for (size_t i = 0; i < 16; i++) {
        Serial.print(".");
        _statusLed.Tick();
        delay(BlinkTime);
    }
    Serial.println("");
}
