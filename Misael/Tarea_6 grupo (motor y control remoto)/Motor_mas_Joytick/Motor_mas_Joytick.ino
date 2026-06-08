#include <Stepper.h>
// 2048 son los pasos para 1 vuelta
int RPM = 2048;
//360 crados = 2048 pasos
//  X craqdos = X pasos

// velocidad de vuelta (baja: 4 ->alta: 11) +11 se quema, -4 no se mueve
int velocidad = 10;

                //RPM, pin1, pin2, pin3, pin4)
Stepper myStepper(RPM, 8, 10, 9, 11);

//Pines analógicos
const int VRy = 0;  //A0
const int VRx = 1;  //A1

int lectura = 0;

void setup() {
  
  Serial.begin(9600);
  myStepper.setSpeed(velocidad);
}

void loop() {

  //myStepper.step(RPM);

  lectura = analogRead(VRy);
  if(lectura<350){
    myStepper.step(RPM);
  }
  else if(lectura>700){
    myStepper.step(-RPM);
  }
  else{
    myStepper.step(0);
  }
  Serial.print("Lectura Eje Y: ");
  Serial.println(lectura);
  delay(500);
}