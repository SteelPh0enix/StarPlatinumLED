#include "webserver.hpp"
#include "constants.hpp"

#include <Arduino.h>
#include <ESP8266WebServer.h>
#include <LittleFS.h>

ESP8266WebServer server;

void handleNotFound() {
    auto file = LittleFS.open("404.html", "r");
    server.send(404, "text/html", file.readString());
    file.close();
}

void handleRoot() {
    auto file = LittleFS.open("index.html", "r");
    server.send(200, "text/html", file.readString());
    file.close();
}

void startServer() {
    Serial.println("Starting LittleFS...");
    if (LittleFS.begin()) {
        Serial.println("LittleFS started!");
    } else {
        while (true) {
            Serial.println(
                "LittleFS failed it's initialization, so i can't really move forward with anything. Looping "
                "eternally.");
            delay(1000);
        }
    }

    server.on("/", handleRoot);
    server.onNotFound(handleNotFound);
    server.serveStatic("/static/", LittleFS, "/");
    server.begin();
}

void handleServer() {
    server.handleClient();
}