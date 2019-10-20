/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 
*/

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





void setup() {
  // declare the sensorPins as an INPUT:
  pinMode(sensorPin0, INPUT);
  pinMode(sensorPin1, INPUT);

  //enable the Serial pin 
  Serial.begin(9600);
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

  Serial.print("mapped Value 1  = ");
  Serial.println(sensorMapped1);

  //Short delay so we have time to read the value
  delay(500);

}
