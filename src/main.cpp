#include "StatusLed.h"
#include <Arduino.h>

const int BlinkTime = 50;

#ifndef INVERT_STATUS_LED
constexpr StatusLed::LedLogic StatusLedLogic = StatusLed::LedLogic::Normal;
#else
constexpr StatusLed::LedLogic StatusLedLogic = StatusLed::LedLogic::Inverted;
#endif

static StatusLed _statusLed(LED_BUILTIN, StatusLedLogic);

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
