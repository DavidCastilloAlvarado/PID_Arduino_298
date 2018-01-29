/*
Proyecto: prueba de entrada y salida para el motor DC
Autor: David Castillo Alvardo
Descripción: probar diferentes entradas y salidas para el motor DC
*/
// Definiendo pines

int IN1; 
int IN2;
int PWM1;
int forWARDS = 1; 
int backWARDS = 0;
//
int sensorPin = A0;    // select the input pin for the potentiometer
int ang=0;
int i=0;
int sensorValue = 0;   // variable to store the value coming from the sensor

void setup() {
  IN1 = 9;
  IN2 = 8;
  PWM1 = 11;
  pinMode(IN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  Serial.begin(9600);           // set up Serial library at 9600 bps

  sensorValue = analogRead(sensorPin);
    
}

void loop() {
  // Inicia la prueba al Motor
  // Voltaje Maximo de 20 V
  // Resolución del PWM = 256bits
  // Colocar la posición del eje en 0 grados
  if (ang < 50){
      double sp=82;
      shaftrev(IN1,IN2,PWM1,backWARDS,sp);
      sp=0.0719*sp + 0.9089;
      // read the value from the sensor:
      sensorValue = analogRead(sensorPin);
      ang=bit2ang(sensorValue);
      Serial.print(ang); Serial.print("\t");Serial.println(sp);
  }
  else if(ang<80){
   
      double sp=77;
      shaftrev(IN1,IN2,PWM1,backWARDS,sp);
      sp=0.0719*sp + 0.9089;
      // read the value from the sensor:
      sensorValue = analogRead(sensorPin);
      ang=bit2ang(sensorValue);
      Serial.print(ang); Serial.print("\t");Serial.print(sp);Serial.print("\t"); Serial.println(millis());
    }
  else if(ang<100 ){     
      double sp=80;
      shaftrev(IN1,IN2,PWM1,backWARDS,sp);
      sp=0.0719*sp + 0.9089;
      // read the value from the sensor:
      sensorValue = analogRead(sensorPin);
      ang=bit2ang(sensorValue);
      Serial.print(ang); Serial.print("\t");Serial.print(sp);Serial.print("\t"); Serial.println(millis());
    }
    else{
      while (ang > -40){
       //Serial.println("stop");
       //delay(1000);
       i=1;   
      double sp=77;
      shaftrev(IN1,IN2,PWM1,forWARDS,sp);
      sp=-0.0719*sp - 0.9089;
      // read the value from the sensor:
      sensorValue = analogRead(sensorPin);
      ang=bit2ang(sensorValue);
      Serial.print(ang); Serial.print("\t");Serial.print(sp);Serial.print("\t"); Serial.println(millis());

      }
       
      }
}
////////////////////////////////////////////////////////////////
int bit2ang(int a){
  int ang;
   //
    ang=-0.1899*a + 102.18;
    return ang;
  }

void shaftrev(int in1, int in2, int PWM, int sentido,int Wpulse)
{
  if(sentido == 0){ //backWARDS
    digitalWrite(in2, HIGH);
    digitalWrite(in1, LOW);
    analogWrite(PWM,Wpulse);
    }
  if(sentido == 1){ //forWARDS
    digitalWrite(in2, LOW);
    digitalWrite(in1, HIGH);
    analogWrite(PWM,Wpulse);     
    }
  
}
