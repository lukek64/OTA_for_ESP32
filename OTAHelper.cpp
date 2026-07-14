#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoOTA.h>

#include "OTAHelper.h"


// Change these
const char* OTA_SSID = "sesplearningstudios";
const char* OTA_PASSWORD = "@nn3nb3rg";


// Optional OTA password
const char* OTA_PASSWO2RD_LOGIN = "robot123";

void setupOTA()
{
    WiFi.mode(WIFI_STA);

    WiFi.begin(OTA_SSID, OTA_PASSWORD);


    Serial.print("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }


    Serial.println();
    Serial.println("WiFi connected");


    Serial.print("ESP32 IP: ");
    Serial.println(WiFi.localIP());



    ArduinoOTA
        .onStart([]()
        {
            String type;

            if (ArduinoOTA.getCommand() == U_FLASH)
                type = "sketch";
            else
                type = "filesystem";

            Serial.println("OTA Start: " + type);
        });


    ArduinoOTA
        .onEnd([]()
        {
            Serial.println("\nOTA Complete");
        });


    ArduinoOTA
        .onProgress([](unsigned int progress, unsigned int total)
        {
            Serial.printf(
                "OTA Progress: %u%%\r",
                (progress / (total / 100))
            );
        });


    ArduinoOTA
        .onError([](ota_error_t error)
        {
            Serial.printf(
                "OTA Error[%u]\n",
                error
            );
        });


    ArduinoOTA.setPassword(OTA_PASSWO2RD_LOGIN);
    ArduinoOTA.begin();


    Serial.println("OTA Ready");
}



void handleOTA()
{
    ArduinoOTA.handle();
}
