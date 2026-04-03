const int boton = 2;
const int led   = 4;

bool estadoBoton = false;
unsigned long tiempoInicio = 0;


void setup() {
  pinMode(boton, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {

  bool lectura = digitalRead(boton);

  // Detecta cuando se presiona
  if (lectura == HIGH && estadoBoton == false){
    estadoBoton = true;
    tiempoInicio = millis();  // guarda el tiempo
  }

  // Detecta cuando se suelta
  if (lectura == LOW && estadoBoton == true){
    estadoBoton = false;
    digitalWrite(led, LOW); // apaga si suelta antes
  }

  // Si está presionado, medir tiempo
  if (estadoBoton == true){
    if (millis() - tiempoInicio >= 2000){ // 2 segundos
      digitalWrite(led, HIGH);
    }
  }
}