#include <UnoWiFiDevEd.h>
#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"

#define PIN 6
#define LED_COUNT 24

// Create an instance of the Adafruit_NeoPixel class called "leds".
// That'll be what we refer to from here on...
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);
int a;
uint8_t brightness;
int red;
int blue;
int green;
void setup()
{
  red = 0xFF; blue = 0x0; green = 0x0;
  //openWebConn();
  leds.begin();  // Call this to start up the LED strip.
  clearLEDs();   // This function, defined below, turns all LEDs off...
  leds.show();   // ...but the LEDs don't actually update until you call this.
  pinMode(PIN, OUTPUT);
  brightness = 255;
  leds.setBrightness(brightness);

  
}

void loop()
{
  clearLEDs();
  for (int i = 0; i <= LED_COUNT - 1; i++)
  {
    leds.setPixelColor(i, red, green, blue);
  }

  leds.show();  // Turn the LEDs on
  if (brightness < 255)brightness += 5;
  else brightness = 10;
  //openWebConn();
  delay(1000);
    


}
void openWebConn() {
  /*
   * openWebConn is used to get data from the webserver
   * Each call returns an integer of a JSON file which we'll map on a color chart
   */
  //  const char* connector = "rest";
  //  const char* server = "download.arduino.org";
  //  const char* method = "GET";
  //  const char* resource = "/latest.txt";

  //
  //  const char* connector = "rest";
  //  const char* server = "api.belair.tocker.iminds.be";
  //  const char* method = "GET";
  //  const char* resource = "/";

  const char* connector = "rest";
  const char* server = "http://api.belair.tocker.iminds.be";
  const char* method = "GET";
  const char* resource = "/location/single/u155kj/";

  Serial.begin(9600);
  Ciao.begin();
  delay(10000);
  int color = doRequest(connector, server, resource, method);
  red = color & 0xFF0000;
  blue = color & 0xFF00; 
  green = color & 0xFF;
  
}

int doRequest(const char* conn, const char* server, const char* command, const char* method) {
  CiaoData data = Ciao.write(conn, server, command, method);
  if (!data.isEmpty()) {
    Ciao.println( "State: " + String (data.get(1)) );
    Ciao.println( "Response: " + String (data.get(2)) );
    Serial.println( "State: " + String (data.get(1)) );
    Serial.println( "Response: " + String (data.get(2)) );
  }
  else {
    Ciao.println ("Write Error");
    Serial.println ("Write Error");
  }
  int test = 1; // CHANGE WITH DATA OF JSON ==> VALUE TO BE DISPLAYED
  return test;
}


// Sets all LEDs to off, but DOES NOT update the display;
// call leds.show() to actually turn them off after this.
void clearLEDs()
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    leds.setPixelColor(i, 0);
  }
}
