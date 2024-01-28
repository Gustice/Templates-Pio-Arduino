#include "main.hpp"

#ifdef DEBUGGER_STUB
#include <app_api.h>
#include <avr8-stub.h>
#endif

const int BlinkTime = 50;

#ifndef INVERT_STATUS_LED
constexpr StatusLed::LedLogic StatusLedLogic = StatusLed::LedLogic::Normal;
#else
constexpr StatusLed::LedLogic StatusLedLogic = StatusLed::LedLogic::Inverted;
#endif

static StatusLed _statusLed(LED_BUILTIN, StatusLedLogic);

void setup() {
#ifdef DEBUGGER_STUB
    debug_init();
#else
    Serial.begin(9600);
#endif
    _statusLed.Set(StatusLed::Mode::DoubleFlash);
}

static RotatingIndex<int> _tickIdx(16);

void loop() {
#ifndef DEBUGGER_STUB
    if (_tickIdx.IncrementAndCheckIfRevolves()) {
        Serial.println("");
        Serial.print("Tick ");
    }
    Serial.print(".");
#endif

    _statusLed.Tick();
    delay(BlinkTime);
}
