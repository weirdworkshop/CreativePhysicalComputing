/* ---------------------------------------------------------------------------
Connect a piezo buzzer (without internal oscillator) or speaker to these pins:
  Pins  9 & 10 - ATmega328, ATmega128, ATmega640, ATmega8, Uno, Leonardo, etc.
  Pins 11 & 12 - ATmega2560/2561, ATmega1280/1281, Mega
  Pins 12 & 13 - ATmega1284P, ATmega644
  Pins 14 & 15 - Teensy 2.0
  Pins 25 & 26 - Teensy++ 2.0
Be sure to include an inline 100 ohm resistor on one pin as you normally do when connecting a piezo or speaker.
--------------------------------------------------------------------------- */

#include <toneAC.h>

int g3 = 196;
int a3 = 220;
int b3 = 247;
int c4 = 262;
int d4 = 294;
int e4 = 330;
int f4 = 350;
int g4 = 392;


// Melody liberated from the toneMelody Arduino example sketch by Tom Igoe.
//int melody[] = { c4, g3, a3, a3,g3, 0, b3,c4 };
int melody[] = { 262, 196, 196, 220, 196, 0, 247, 262 };
int noteDurations[] = { 4, 8, 8, 4, 4, 4, 4, 4 };

void setup() {
  
  Serial.begin(9600);
  
  } 
void loop() {
  for (unsigned long freq = 125; freq <= 5000; freq += 2) {
    toneAC(freq); // Play the frequency (125 Hz to 15 kHz sweep in 10 Hz steps).
    delay(1);     // Wait 1 ms so you can hear it.
  }
  toneAC(); // Turn off toneAC, can also use noToneAC().

  delay(2000); 

  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];

    Serial.println(melody[thisNote]);
    

    
    toneAC(melody[thisNote], 10, noteDuration, true); // Play thisNote at full volume for noteDuration in the background.
    delay(noteDuration * 4 / 3); // Wait while the tone plays in the background, plus another 33% delay between notes.
  }
   delay(2000); 

  
}
