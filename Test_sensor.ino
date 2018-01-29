/*
Autor: Castillo Alvarado , David
test: Sensor
*/

int sensorPin = A0;    // select the input pin for the potentiometer
double ang=0;
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:

  Serial.begin(9600);           // set up Serial library at 9600 bps
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  ang=-0.1899*sensorValue + 102.18;
  // A 90 grados mide 116bits , a 0 grados mide 433 bits
 Serial.print( ang ); Serial.println( '\t' ); //Serial.println( ang);
  // turn the ledPin on

}
