#include <Arduino.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

#include "constants.hpp"

void setup() {
    Serial.begin(Constants::SERIAL_BAUDRATE);
}

void loop() {}