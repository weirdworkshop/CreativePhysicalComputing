/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 
*/


int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

int  inputLow = 0;     //Minimum value from analogue sensor
int  inputHigh = 1023; // maximum value from analogue sensor
int  mappedLow = 0;    // minimum value of map() output range
int  mappedHigh = 255; // maximum value of map() output range 
int sensorMapped = 0; //Where we store our mapped Value



void setup() {
  // declare the sensorPin as an INPUT:
  pinMode(sensorPin, INPUT);

  //enable the Serial pin 
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  

  //map the input range of 0 - 1023 to 0 - 255 
  //store in the sensorMapped variable
  sensorMapped = map(sensorValue0, inputLow, inputHigh, mappedLow, mappedHigh);

  `
  //Display the Sensor Value on the Serial Monitor
  Serial.print("mapped Value = ");
  Serial.println(sensorMapped);

  //Short delay so we have time to read the value
  delay(500);

}
