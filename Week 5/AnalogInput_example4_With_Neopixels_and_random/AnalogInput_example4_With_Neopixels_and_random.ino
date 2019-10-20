/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 
*/

#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 15


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int sensorPin0 = A0;    // select the input pin for the potentiometer
int sensorPin1 = A1;   // select the input pin for the potentiometer

int sensorValue0 = 0;  // variable to store the value coming from the sensor
int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorMapped0 = 0; //Where we store our mapped Value
int sensorMapped1 = 0; //Where we store our mapped Value

int inputLow = 0;     //Minimum value from analogue sensor
int inputHigh = 1023; // maximum value from analogue sensor
int mappedLow = 0;    // minimum value of map() output range
int mappedHigh = 255; // maximum value of map() output range 

long randomValue;





void setup() {
  // declare the sensorPins as an INPUT:
  pinMode(sensorPin0, INPUT);
  pinMode(sensorPin1, INPUT);

  //enable the Serial pin 
  Serial.begin(9600);

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  // read the value from the sensor:
  sensorValue0 = analogRead(sensorPin0);
  sensorValue1 = analogRead(sensorPin1);

  //map the input range of 0 - 1023 to 0 - 255 
  //store in the sensorMapped variable

  sensorMapped0 = map(sensorValue0, inputLow, inputHigh, mappedLow, mappedHigh);
  sensorMapped1 = map(sensorValue1, inputLow, inputHigh, mappedLow, mappedHigh);

  //Display the Sensor Value on the Serial Monitor
  Serial.print("mapped Value 0  = ");
  Serial.println(sensorMapped0);

  Serial.print("mapped Value 0  = ");
  Serial.println(sensorMapped1);


  //Generate Random number for the blue NeoPixel
  randomValue = random(0,256);

  
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(sensorMapped0, sensorMapped1, randomValue));

    pixels.show();   // Send the updated pixel colors to the hardware.

    
  }

}
