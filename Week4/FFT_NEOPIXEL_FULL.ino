/*

	Example of use of the FFT libray to compute FFT for a signal sampled through the ADC.
        Copyright (C) 2018 Enrique Condés and Ragnar Ranøyen Homb

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#include "arduinoFFT.h"
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 20
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);




arduinoFFT FFT = arduinoFFT(); /* Create FFT object */
#define CHANNEL A0
const uint16_t samples = 128; //This value MUST ALWAYS be a power of 2.  Try 256 on Arduino Mega.
const double samplingFrequency = 9000; //Hz, must be less than 10000 due to ADC. And will be Double Highest Frequency

unsigned int sampling_period_us;
unsigned long microseconds;

/*
These are the input and output vectors
Input vectors receive computed results from FFT
*/
double vReal[samples];
double vImag[samples];


#define SCL_INDEX 0x00
#define SCL_TIME 0x01
#define SCL_FREQUENCY 0x02
#define SCL_PLOT 0x03

void setup()
{
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  
  sampling_period_us = round(1000000*(1.0/samplingFrequency));
  
  Serial.begin(115200);
  Serial.println("Ready");
  delay(5000);
}

void loop()
{
  /*SAMPLING*/
  for(int i=0; i<samples; i++)
  {
      microseconds = micros();    //Overflows after around 70 minutes!

      vReal[i] = analogRead(CHANNEL);
      vImag[i] = 0;
      while(micros() < (microseconds + sampling_period_us)){
        //empty loop
      }
  }

  
/* Calculate FFT and print the dominat Frequency */

  FFT.Windowing(vReal, samples, FFT_WIN_TYP_HAMMING, FFT_FORWARD);	/* Weigh data */
  FFT.Compute(vReal, vImag, samples, FFT_FORWARD); /* Compute FFT */
  FFT.ComplexToMagnitude(vReal, vImag, samples); /* Compute magnitudes */
  
  double dominantFreq = FFT.MajorPeak(vReal, samples, samplingFrequency);
  Serial.println(dominantFreq, 6); //Print out what frequency is the most dominant.

   if(dominantFreq < 1000){
      pixels.clear(); // Set all pixel colors to 'off'

      for(int i=0; i<3; i++) { // For each pixel...
         pixels.setPixelColor(i, pixels.Color(0, 20, 0));
         pixels.show();   // Send the updated pixel colors to the hardware.
       }
       delay(5);
       pixels.clear(); // Set all pixel colors to 'off'
      }

      
      if(dominantFreq  > 1000 && dominantFreq< 2000){
          pixels.clear(); // Set all pixel colors to 'off'

          for(int i=3; i<6; i++) { // For each pixel...
             pixels.setPixelColor(i, pixels.Color(0, 50, 20));
             pixels.show();   // Send the updated pixel colors to the hardware.
           }
           delay(5);
           pixels.clear(); // Set all pixel colors to 'off'
      }

      if(dominantFreq  > 2000  && dominantFreq < 3000){
        


          pixels.clear(); // Set all pixel colors to 'off'

          for(int i=6; i<9; i++) { // For each pixel...
             pixels.setPixelColor(i, pixels.Color(0, 0, 30));
             pixels.show();   // Send the updated pixel colors to the hardware.
           }
           delay(5);
           pixels.clear(); // Set all pixel colors to 'off'
      }

        if(dominantFreq  > 3000  && dominantFreq < 4000){
        


          pixels.clear(); // Set all pixel colors to 'off'

          for(int i=9; i<14; i++) { // For each pixel...
             pixels.setPixelColor(i, pixels.Color(20, 45, 90));
             pixels.show();   // Send the updated pixel colors to the hardware.
           }
           delay(5);
           pixels.clear(); // Set all pixel colors to 'off'
      }


         if(dominantFreq   > 4000){
        


          pixels.clear(); // Set all pixel colors to 'off'

          for(int i=14; i<20; i++) { // For each pixel...
             pixels.setPixelColor(i, pixels.Color(90, 0, 30));
             pixels.show();   // Send the updated pixel colors to the hardware.
           }
           delay(5);
           pixels.clear(); // Set all pixel colors to 'off'
      }

}
