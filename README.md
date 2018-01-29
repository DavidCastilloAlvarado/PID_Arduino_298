# PID_Arduino_298
Create a PID control of a DCMotor, using an arduino and L298 Driver.
/********************************************************
Lima - Perú ENE/2018
AUTOR: Castillo Alvarado, David 
PROYECTO: Control de Motor DC - PID(Z)
Descripción:
  El presente proyecto es una implementación didactica sobre el uso
  del metodo de control de posición por PID en un motor DC.
CONEXIÓN::::::::::::::::::::::::::
> Arduino: (5V USB)
  A0  = Sensor de posición
  A1  = Sensor que lee el valor del SetPoint
  D8  = IN1 --L298N
  D9  = IN2 --L298N
  D11 = PWM --L298N
> L298N (5v & 19v)
  IN1
  IN2
  In PWM 
FUENTES:::::::::::
  https://www.youtube.com/watch?v=c0L4gNKwjRw
  https://playground.arduino.cc/Code/Timer1
  https://playground.arduino.cc/Code/PIDLibrary
 ********************************************************/
