const int boton = 2;
const int led[] = {4, 5, 6, 7, 8, 9};
const int nled = 6;

int contador = 0;
bool estadoBoton = false;

void setup() {
  pinMode(boton, INPUT);

  for (int i = 0; i < nled; i++){
    pinMode(led[i], OUTPUT);
  }
}

void loop() {

  bool lectura = digitalRead(boton);

  // Detecta flanco (cuando presionas)
  if (lectura == HIGH && estadoBoton == false){
    estadoBoton = true;

    if (contador < nled){
      digitalWrite(led[contador], HIGH);
      contador = contador + 1;
      delay(250);
    }

    else {
      // Apagar todos correctamente
      int i = nled - 1;
      for (i; i >= 0; i--){
        digitalWrite(led[i], LOW);
      }
      delay(250);
      contador = 0;
    }
  }

  // Detecta cuando sueltas
  if (lectura == LOW && estadoBoton == true){
    estadoBoton = false;
  }

}