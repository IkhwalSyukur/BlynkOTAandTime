
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLYrwpoc0m"
#define BLYNK_DEVICE_NAME "OTA"
#define BLYNK_AUTH_TOKEN "uwvK7psroYDAgAifjchQqq-nHAt2rPSt"
#define BLYNK_FIRMWARE_VERSION        "1.0.4"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD
//#define USE_TTGO_T7

#include "BlynkEdgent.h"
#include "time.h"
#include <TimeLib.h>
#include <WidgetRTC.h>
BlynkTimer timer;
WidgetRTC rtc;

String currentTime = "";
String currentDate = "";

void clockDisplay()
{
  // You can call hour(), minute(), ... at any time
  // Please see Time library examples for details

  String currentTime = String(hour()) + ":" + minute() + ":" + second();
  String currentDate = String(day()) + " " + month() + " " + year();
  Serial.print("Current time: ");
  Serial.print(currentTime);
  Serial.print(" ");
  Serial.print(currentDate);
  Serial.println();

  // Send time to the App
  Blynk.virtualWrite(V1, currentTime);
  // Send date to the App
  Blynk.virtualWrite(V2, currentDate);
}

BLYNK_CONNECTED() {
  // Synchronize time on connection
  rtc.begin();
}

//void myTimerEvent()
//{
//  // You can send any value at any time.
//  // Please don't send more that 10 values per second.
//  Blynk.virtualWrite(V1,100);
//}

void setup()
{ 
  Serial.begin(115200);
  delay(100);
  pinMode(2,OUTPUT);
  BlynkEdgent.begin();
  setSyncInterval(10 * 60);
  timer.setInterval(10000L, clockDisplay);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}
