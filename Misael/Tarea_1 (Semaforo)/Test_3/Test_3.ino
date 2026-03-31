bool Boton_Estado          =  false;
int Estado_dia            =  0;
int Hora                  =  0;
int Estado_Luz            =  0;

const int boton           =  2;   
const int Led_Auto_1V     =  4;
const int Led_Auto_2A     =  5;
const int Led_Auto_3R     =  6;
const int Led_Auto_4V     =  7;
const int Led_Auto_5A     =  8;
const int Led_Auto_6R     =  9;
const int Led_Persona_7V  = 10;
const int Led_Persona_8R  = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(Led_Auto_1V, OUTPUT);
  pinMode(Led_Auto_2A, OUTPUT);
  pinMode(Led_Auto_3R, OUTPUT);
  pinMode(Led_Auto_4V, OUTPUT);
  pinMode(Led_Auto_5A, OUTPUT);
  pinMode(Led_Auto_6R, OUTPUT);
  pinMode(Led_Persona_7V, OUTPUT);
  pinMode(Led_Persona_8R, OUTPUT);
  pinMode(boton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Crear variable de estado IMPORTANTES
  Boton_Estado = digitalRead(boton);
  switch (Estado_dia) {
    case 0: // dia
      switch (Estado_Luz ){
        // 1V, 6R y 8R
        case 0:
          Hora = Hora + 1;
          // Prendido 1V y apagado 2A y 3R
          digitalWrite(Led_Auto_1V, HIGH);
          digitalWrite(Led_Auto_2A, LOW);
          digitalWrite(Led_Auto_3R, LOW);
          // Apagado 4V, 4A y prendido 6R
          digitalWrite(Led_Auto_4V, LOW);
          digitalWrite(Led_Auto_5A, LOW);
          digitalWrite(Led_Auto_6R, HIGH);
          // Apagado 7V y prendido 8R
          digitalWrite(Led_Persona_7V, LOW);
          digitalWrite(Led_Persona_8R, HIGH);
          delay(2000);
          if(Boton_Estado == true){
            Estado_Luz = 4;
          }
          else{
            Estado_Luz = 1;
          }
          break;
        // 2A
        case 1:
          // Apagado 1V, 3R y prendido 2A
          digitalWrite(Led_Auto_1V, LOW);
          digitalWrite(Led_Auto_2A, HIGH);
          // LEDs 4V, 5A, 6R, 7V y 8R se mantiene igual
          Estado_Luz = 2;
          delay(2000);
          break;
        // 3R y 4V
        case 2:
          // Apagado 1V, 2A y prendido 3R
          digitalWrite(Led_Auto_1V,LOW);
          digitalWrite(Led_Auto_2A, LOW);
          digitalWrite(Led_Auto_3R, HIGH);
          // Prendido 4V y apagado 5A y 6R
          digitalWrite(Led_Auto_4V, HIGH);
          digitalWrite(Led_Auto_6R, LOW);
          // Prendido 7V y apagado 8R
          digitalWrite(Led_Persona_7V, HIGH);
          digitalWrite(Led_Persona_8R, LOW);
          Estado_Luz = 3;
          delay(2000);
          break;
        // 5A
        case 3:
          //Apado 4V, 6R y prendido 5A
          digitalWrite(Led_Auto_4V, LOW);
          digitalWrite(Led_Auto_5A, HIGH);
          Estado_Luz = 0;
          delay(2000);
          if ( Hora >= 2){
            Estado_dia = 1;
          }
          break;
        // Boton
        case 4:
          // Se apaga 1V y Prende 2A intermintentemente
          digitalWrite(Led_Auto_2A, LOW);
          delay(500);
          digitalWrite(Led_Auto_2A, HIGH);
          delay(500);
          digitalWrite(Led_Auto_2A, LOW);
          delay(500);
          digitalWrite(Led_Auto_2A, HIGH);
          // LEDs 4V, 5A, 6R, 7V y 8R se mantiene igual
          Estado_Luz = 2;
          Boton_Estado = false;
          delay(500);
          break;
      }
      break;
    case 1: // NOCHE
      switch (Estado_Luz ){
        // 1V, 6R y 8R
        case 0:
          Hora = Hora + 1;
          // Prendido 1V y apagado 2A y 3R
          digitalWrite(Led_Auto_1V, HIGH);
          digitalWrite(Led_Auto_2A, HIGH);
          digitalWrite(Led_Auto_3R, LOW);
          // Apagado 4V, 4A y prendido 6R
          digitalWrite(Led_Auto_4V, LOW);
          digitalWrite(Led_Auto_5A, LOW);
          digitalWrite(Led_Auto_6R, HIGH);
          // Apagado 7V y prendido 8R
          digitalWrite(Led_Persona_7V, LOW);
          digitalWrite(Led_Persona_8R, HIGH);
          delay(2000);
          if(Boton_Estado == true ){
            Estado_Luz = 4;
          }
          else{
            Estado_Luz = 1;
          }
          break;
        // 2A
        case 1:
          // Apagado 1V, 3R siempre, mientras que 2A intermitente mente
          digitalWrite(Led_Auto_1V, LOW);
          digitalWrite(Led_Auto_2A, LOW);
          delay(500);
          digitalWrite(Led_Auto_2A, HIGH);
          delay(500);
          digitalWrite(Led_Auto_2A, LOW);
          delay(500);
          digitalWrite(Led_Auto_2A, HIGH);
          // LEDs 4V, 5A, 6R, 7V y 8R se mantiene igual
          Estado_Luz = 2;
          delay(500);
          break;
        // 3R y 4V
        case 2:
          // Apagado 1V, 2A y prendido 3R
          digitalWrite(Led_Auto_1V,LOW);
          digitalWrite(Led_Auto_2A, LOW);
          digitalWrite(Led_Auto_3R, HIGH);
          // Prendido 4V, 5A y apgado 6R
          digitalWrite(Led_Auto_4V, HIGH);
          digitalWrite(Led_Auto_5A, HIGH);
          digitalWrite(Led_Auto_6R, LOW);
          // Prendido 7V y apagado 8R
          digitalWrite(Led_Persona_7V, HIGH);
          digitalWrite(Led_Persona_8R, LOW);
          Estado_Luz = 3;
          delay(2000);
          break;
        // 5A
        case 3:
          // Apagado 4V, 6R siempre mientras que 5A intermitente mente
          digitalWrite(Led_Auto_4V, LOW);
          digitalWrite(Led_Auto_5A, LOW);
          delay(500);
          digitalWrite(Led_Auto_5A, HIGH);
          delay(500);
          digitalWrite(Led_Auto_5A, LOW);
          delay(500);
          digitalWrite(Led_Auto_5A, HIGH);
          Estado_Luz = 0;
          delay(500);
          if(Hora >= 4){
            Hora = 0;
            Estado_dia = 0;
          }
          break;
        // Boton
        case 4:
          // se apaga v1 y Prende 2A intermintentemente
          digitalWrite(Led_Auto_2A, LOW);
          delay(500);
          digitalWrite(Led_Auto_2A, HIGH);
          delay(500);
          digitalWrite(Led_Auto_2A, LOW);
          delay(500);
          digitalWrite(Led_Auto_2A, HIGH);
          // LEDs 4V, 5A, 6R, 7V y 8R se mantiene igual
          Estado_Luz = 2;
          Boton_Estado = false;
          delay(500);
          break;
      }
      break;
  }   
}
