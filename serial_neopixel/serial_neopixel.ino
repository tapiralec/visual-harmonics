//Alec Moore, Spring 2015
#include "Adafruit_NeoPixel.h"
#include <avr/power.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB+NEO_KHZ800);

int index;
int red;
int green;
int blue;

void setup(){
  strip.begin();
  strip.show();
  Serial.begin(115200); //most arduinos should be fine at this baudrate
}

void loop(){
  while(true){
    //position
    while(!Serial.available()); //wait for available data
    index = Serial.read()-1; //subtract 1 so we can index 0
    if (index==254) break; //enforce timing
    
    //R
    while(!Serial.available());
    red = Serial.read()-1;
    if (red==254) break;
    
    //G
    while(!Serial.available());
    green = Serial.read()-1;
    if (green==254) break;
    
    //B
    while(!Serial.available());
    blue = Serial.read()-1;
    if (blue==254) break;
    
    strip.setPixelColor(index, strip.Color(red,green,blue));
    strip.show();
    Serial.write(1); //let host know we finished updating.
  }
}
    

