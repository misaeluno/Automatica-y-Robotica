#include <Stepper.h>
// 2048 son los pasos para 1 vuelta
int RPM = 2048;
//360 crados = 2048 pasos
//  X craqdos = X pasos

// velocidad de vuelta (baja: 4 ->alta: 11) +11 se quema, -4 no se mueve
int velocidad = 11;

                //RPM, pin1, pin2, pin3, pin4)
Stepper myStepper(RPM, 8, 9, 10, 11);

void setup() {
  myStepper.setSpeed(velocidad);
}

void loop() {
  // put your main code here, to run repeatedly:
  myStepper.step(RPM);
  

}
