int Boton_Estado          =  0;
int Led_1_Estado          =  0;
int Led_4_Estado          =  0;
int Estado_dia            =  0;
int horas                 =  0;

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
  Led_1_Estado = digitalRead(Led_Auto_1V);
  Led_4_Estado = digitalRead(Led_Auto_4V);

  //Inicia siempre el programa con Semaforo 1 encendido
  //Semaforo 1= Led 1V encendido y 2A y 3R Apagado
  digitalWrite(Led_Auto_1V, HIGH);
  digitalWrite(Led_Auto_2A, LOW);
  digitalWrite(Led_Auto_3R, LOW);
  //Semaforo 3= Led 4V y 5A apagado con 6R encendido
  digitalWrite(Led_Auto_4V, LOW);
  digitalWrite(Led_Auto_5A, LOW);
  digitalWrite(Led_Auto_6R, HIGH);
  //Semaforo 4= LEd 7A apago con 8R encendido
  digitalWrite(Led_Persona_7V, LOW);
  digitalWrite(Led_Persona_8R, HIGH);
  
  switch (Estado_dia) {
    // dia
    case 0:
      switch (Boton_Estado){
      //BOTON DE PRECIONADO
        case 0:
          // contador de horas del dia
          horas = horas + 1;
          if (Led_1_Estado == HIGH) {
            //Se apague 1V y se encienda el 2A
            digitalWrite(Led_Auto_1V, LOW);
            digitalWrite(Led_Auto_2A, HIGH);
            delay(1000);
            //Se apaga 2A y se enciende 3R
            digitalWrite(Led_Auto_2A, LOW);
            digitalWrite(Led_Auto_3R, HIGH);
            //Se prende 4V y se apaga el 6R
            digitalWrite(Led_Auto_4V, HIGH);
            digitalWrite(Led_Auto_6R, LOW);
            //Se debe prender 7V y se apaga 8R
            digitalWrite(Led_Persona_7V, HIGH);
            digitalWrite(Led_Persona_8R, LOW);
            //Guardamos los estados IMPORTANES DE NUEVO
            Led_1_Estado = digitalRead(Led_Auto_1V);
            Led_4_Estado = digitalRead(Led_Auto_4V);
            delay(1000);
          }
          if (Led_4_Estado == HIGH){
            //Se apague 4V y se encienda el 5A
            digitalWrite(Led_Auto_4V, LOW);
            digitalWrite(Led_Auto_5A, HIGH);
            delay(1000);
            //Se apaga 5A y se enciende 6R
            digitalWrite(Led_Auto_5A, LOW);
            digitalWrite(Led_Auto_6R, HIGH);
            //Se prende 4V y se apaga el 6R
            digitalWrite(Led_Auto_1V, HIGH);
            digitalWrite(Led_Auto_3R, LOW);
            //Se debe apaga 7V y se prende 8R
            digitalWrite(Led_Persona_7V, LOW);
            digitalWrite(Led_Persona_8R, HIGH);
            //Guardamos los estados IMPORTANES DE NUEVO
            Led_1_Estado = digitalRead(Led_Auto_1V);
            Led_4_Estado = digitalRead(Led_Auto_4V);
            delay(1000);
          }
          // Si se cumplen las 12 horas de luz de dia
          if (horas >= 4){
            Estado_dia = 1;
            break;
          }
          break;

        // BOTON PRECIONADO
        case 1:
          horas = horas + 1;
          //Se prende 2A, parpadiando
          digitalWrite(Led_Auto_2A, HIGH);
          delay(250);
          digitalWrite(Led_Auto_2A, LOW);
          delay(250);
          digitalWrite(Led_Auto_2A, HIGH);
          delay(500);
          //Ahora se apaga 1V, 2V y se prende 3R
          digitalWrite(Led_Auto_1V, LOW);
          digitalWrite(Led_Auto_2A, LOW);
          digitalWrite(Led_Auto_3R, HIGH);
          //Se prende 4V y se apaga 6R
          digitalWrite(Led_Auto_4V, HIGH);
          digitalWrite(Led_Auto_6R, LOW);
          //Se prende 7V y se apaga 8R
          digitalWrite(Led_Persona_7V, HIGH);
          digitalWrite(Led_Persona_8R, LOW);
          //Guardamos los estados IMPORTANES DE NUEVO
          Led_1_Estado = digitalRead(Led_Auto_1V);
          Led_4_Estado = digitalRead(Led_Auto_4V);
          delay(1000);
          Boton_Estado = 0;
          // Si se cumplen las 12 horas de luz de dia
          if (horas >= 4){
            Estado_dia = 1;
            break;
          }
          break;
      }
      break;
      
    // NOCHE
    case 1:
      Boton_Estado = 0;
      switch (Boton_Estado){
        //BOTON NO PRECIONADO
        case 0:
          // contador de horas del dia
          horas = horas + 1;
          if (Led_1_Estado == HIGH){
            // Tener 1V apagado y 2A intermintente
            digitalWrite(Led_Auto_1V, LOW);
            digitalWrite(Led_Auto_2A, LOW);
            delay(250);
            digitalWrite(Led_Auto_2A, HIGH);
            delay(250);
            digitalWrite(Led_Auto_2A, LOW);
            delay(250);
            digitalWrite(Led_Auto_2A, HIGH);
            delay(250);
            // Se apaga 2A y se enciende 3R
            digitalWrite(Led_Auto_2A, LOW);
            digitalWrite(Led_Auto_3R, HIGH);
            // Se prende 4V, 5A y se apaga R6
            digitalWrite(Led_Auto_4V, HIGH);
            digitalWrite(Led_Auto_5A, HIGH);
            digitalWrite(Led_Auto_6R, LOW);
            //Se prende 7V y se apaga 8R
            digitalWrite(Led_Persona_7V, HIGH);
            digitalWrite(Led_Persona_8R, LOW);
            //Guardamos los estados IMPORTANES DE NUEVO
            Led_1_Estado = digitalRead(Led_Auto_1V);
            Led_4_Estado = digitalRead(Led_Auto_4V);
            delay(1000);
          }

          if (Led_4_Estado == HIGH){
            // Tener 4V apagado y 5A intermintente
            digitalWrite(Led_Auto_4V, LOW);
            digitalWrite(Led_Auto_5A, LOW);
            delay(250);
            digitalWrite(Led_Auto_5A, HIGH);
            delay(250);
            digitalWrite(Led_Auto_5A, LOW);
            delay(250);
            digitalWrite(Led_Auto_5A, HIGH);
            delay(250);
            // Se apaga 5A y se enciende 6R
            digitalWrite(Led_Auto_5A, LOW);
            digitalWrite(Led_Auto_6R, HIGH);
            // Se prende 1V, 2A y se apaga 3R
            digitalWrite(Led_Auto_1V, HIGH);
            digitalWrite(Led_Auto_2A, HIGH);
            digitalWrite(Led_Auto_3R, LOW);
            //Se apaga 7V y se prende 8R
            digitalWrite(Led_Persona_7V, LOW);
            digitalWrite(Led_Persona_8R, HIGH);
            //Guardamos los estados IMPORTANES DE NUEVO
            Led_1_Estado = digitalRead(Led_Auto_1V);
            Led_4_Estado = digitalRead(Led_Auto_4V);
            delay(1000);
          }
          // Si se cumplen las 12 horas de luz de dia
          if (horas >= 4){
            Estado_dia = 1;
            break;
          }
          break;
        // BOTON PRECIONADO
        case 1:
          // contador de horas del dia
          horas = horas + 1;
          //Se prende 2A, parpadiando
          digitalWrite(Led_Auto_2A, HIGH);
          delay(250);
          digitalWrite(Led_Auto_2A, LOW);
          delay(250);
          digitalWrite(Led_Auto_2A, HIGH);
          delay(250);
          digitalWrite(Led_Auto_2A, LOW);
          delay(250);
          digitalWrite(Led_Auto_2A, HIGH);
          delay(500);
          //Ahora se apaga 1V, 2V y se prende 3R
          digitalWrite(Led_Auto_1V, LOW);
          digitalWrite(Led_Auto_2A, LOW);
          digitalWrite(Led_Auto_3R, HIGH);
          //Se prende 4V, 5A y se apaga 6R
          digitalWrite(Led_Auto_4V, HIGH);
          digitalWrite(Led_Auto_5A, HIGH);
          digitalWrite(Led_Auto_6R, LOW);
          //Se prende 7V y se apaga 8R
          digitalWrite(Led_Persona_7V, HIGH);
          digitalWrite(Led_Persona_8R, LOW);
          //Guardamos los estados IMPORTANES DE NUEVO
          Led_1_Estado = digitalRead(Led_Auto_1V);
          Led_4_Estado = digitalRead(Led_Auto_4V);
          delay(1000);
          Boton_Estado = 0;
          if (horas >= 4){
            horas = 0;
            Estado_dia = 0;
            break;
          }
      }
  }
}
