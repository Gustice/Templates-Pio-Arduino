#include "main.hpp"

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

static RotatingIndex<int> _tickIdx(16);

void loop() {
    if (_tickIdx.IncrementAndCheckIfRevolves()) {
        Serial.println("");
        Serial.print("Tick ");
    }
    Serial.print(".");
    _statusLed.Tick();
    delay(BlinkTime);
}
