#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

#include "constants.hpp"
#include "webserver.hpp"

void connectToWiFi() {
    WiFi.begin(Constants::WIFI_SSID, Constants::WIFI_PASSWORD);
    Serial.printf("Connecting to WiFi %s", Constants::WIFI_SSID);

    while (WiFi.status() != WL_CONNECTED) {
        delay(200);
        Serial.printf(".");
    }

    Serial.print(" Connected!\r\nIP address: ");
    Serial.println(WiFi.localIP());
}

void startDNS() {
    Serial.println("Starting mDNS responder...");

    if (!MDNS.begin(Constants::DNS_DOMAIN_NAME)) {
        Serial.println("Cannot start mDNS responder, the device will be accesible ONLY via IP address!");
    } else {
        Serial.printf("mDNS started, the device will be accesible on http://%s.local/", Constants::DNS_DOMAIN_NAME);
    }
}

void setup() {
    Serial.begin(Constants::SERIAL_BAUDRATE);
    Serial.println("Hello, world! This is Star Platinum, HTTP RGBW LED strip server!");

    connectToWiFi();
    startDNS();
    startServer();
}

void loop() {
    MDNS.update();
    handleServer();
}