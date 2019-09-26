/*
  Blink without Delay

  Turns on and off a light emitting diode (LED) connected to a digital pin,
  without using the delay() function. This means that other code can run at the
  same time without being interrupted by the LED code.



  created 2005
  by David A. Mellis
  modified 8 Feb 2010
  by Paul Stoffregen
  modified 11 Nov 2013
  by Scott Fitzgerald
  modified 9 Jan 2017
  by Arturo Guadalupi
  
  modified 8 September
  by Catherine Jones

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
*/

// constants won't change. Used here to set a pin number:
const int ledPin1 =  8;// the number of the LED pin
const int ledPin2 =  10;// the number of the LED pin

// Variables will change:
int ledState1 = LOW;             // ledState used to set the LED1
int ledState2 = LOW;             // ledState used to set the LED2

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis1 = 0;        // will store last time LED1 was updated
unsigned long previousMillis2 = 0;        // will store last time LED2 was updated

// constants won't change:
const long interval1 = 500;           // interval 1 at which to blink (milliseconds)
const long interval2 = 3000;           // interval 2 at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis1 = millis();
  unsigned long currentMillis2 = millis();



  /* 
   *  Controls LED1
   */

  if (currentMillis1 - previousMillis1 >= interval1) {
      // save the last time you blinked the LED
      previousMillis1 = currentMillis1;
  
      // if the LED is off turn it on and vice-versa:
      if (ledState1 == LOW) {
          ledState1 = HIGH;
      } else {
          ledState1 = LOW;
      }


    // set the LED with the ledState of the variable:
    digitalWrite(ledPin1, ledState1);
    
  }



  
  /* 
   *  Controls LED2
   */

    if (currentMillis2 - previousMillis2 >= interval2) {
    // save the last time you blinked the LED
    previousMillis2 = currentMillis2;

    // if the LED is off turn it on and vice-versa:
      if (ledState2 == LOW) {
          ledState2 = HIGH;
      } else {
          ledState2 = LOW;
      }
     // set the LED with the ledState of the variable:
    digitalWrite(ledPin2, ledState2);


   }


  
}
