bool estadoBoton           = false;
int estado                 = 0;
const int led[]            = {4, 5, 6, 7, 8, 9};
const int nled             = 6;
unsigned long tiempoInicio = 0;
unsigned long tiempoFinal  = 0;
unsigned long tiempoApagado = 0;
const int boton            = 12;
int contador               = 0;

void setup() {
  for (int i = 0; i < nled; i++){
    pinMode(led[i], OUTPUT);
  }
  pinMode(boton, INPUT);
}

// Encender todos
void todosON(){
  for (int i = 0; i < nled; i++){
    digitalWrite(led[i], HIGH);
  }
}

// Apagar todos
void todosOFF(){
  for (int i = 0; i < nled; i++){
    digitalWrite(led[i], LOW);
  }
}

// Parpadeo general
void parpadeo(int veces, int tiempo){
  for (int i = 0; i < veces; i++){
    todosOFF();
    todosON();
    delay(tiempo);
    todosOFF();
    delay(tiempo);
  }
}

// Secuencia ascendente
void ascendente(){
  for ( int j = nled; j > 0; j--){
    for (int i = 0; i < j; i++){
      digitalWrite(led[i], HIGH);
      digitalWrite(led[i-1], LOW);
      delay(250);
    }
  }
}

// Ida
void ida(){
  for ( int j = 0; j < nled; j++){
    for (int i = j ; i >= 0 ; i--){
      digitalWrite(led[i], LOW);
      digitalWrite(led[i-1], HIGH);
      delay(200);
    }
  }
}

// Secuencia descendente
void descendente(){
  for ( int j = 0; j <= nled; j++){
    for (int i = nled; i >= j ; i--){
      digitalWrite(led[i], HIGH);
      digitalWrite(led[i+1], LOW);
      delay(250);
    }
  }
}

// Vuelta
void vuelta(){
  for ( int j = nled; j >= 0 ; j--){
    for (int i = j ; i <= nled ; i++){
      digitalWrite(led[i], LOW);
      digitalWrite(led[i+1], HIGH);
      delay(250);
    }
  }
}

// Salto del conejo
void conejo(){
  for (int i = 0 ; i<nled; i++){
    digitalWrite(led[i], HIGH);
    digitalWrite(led[i-1], LOW);
    delay(250);
  }
  for (int i = nled ; i >= 0 ; i--){
    digitalWrite(led[i], LOW);
    digitalWrite(led[i-1], HIGH);
    delay(250);
  }
}

void TEST(){
  parpadeo(5, 200);
  ascendente();
  ida();
  descendente();
  vuelta(); 
  conejo();
}

int Encender(int estado, bool lectura ){
  
  // Detecta cuando se presiona
  if (lectura == HIGH && estadoBoton == false){
    estadoBoton = true;
    tiempoInicio = millis();  // guarda el tiempo
  }

  // Detecta cuando se suelta
  if (lectura == LOW && estadoBoton == true){
    tiempoInicio = 0;
    estadoBoton = false;
  }

  // Si está presionado, medir tiempo
  if (estadoBoton == true){
    if (millis() - tiempoInicio >= 2000){ // 2 segundos
      estado = 1; // Pasa al estado 1 (TEST para probar los LEDs)
      estadoBoton = false;
      return estado;
    }
  }
  return estado; // Conserva el estado actual
}

// Funcion para encender LEDs segun veces precionado el boton
int contar(int espera, bool lectura ) {

  // Detecta flanco (cuando presionas)
  if (lectura == HIGH && estadoBoton == false){
    estadoBoton = true;
    if (contador < nled){
      tiempoApagado = millis();  // guarda el tiempo 
      // enciende el LED segun las veces precionado
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
    tiempoApagado = 0;
    tiempoFinal = millis(); 
  }

  // Si mantiene precionado 2 segundos se apaga
  if (tiempoApagado != 0 && millis() - tiempoApagado >= 2000){
    tiempoApagado = 0;
    estado = 3;  // Pasa al estado 3 (Se apaga y espera)
    estadoBoton = false;
    contador = 0;
    return estado;
  }
  // si no preciona nada por 5 segundos se apaga
  if (tiempoFinal != 0 && millis() - tiempoFinal >= 5000){
    tiempoFinal = 0;
    estado = 3;   // Pasa al estado 3 (Se apaga y espera)
    estadoBoton = false;
    contador = 0;
    return estado;
  }

  return estado;  // Conserva su estado actual
}

//_------------------------------
void loop() {

  bool lectura = digitalRead(boton);

  switch (estado){

    case 0: // estado apagado esperando 2 segundos pra encender
      estado = Encender(estado, lectura);
      break;

    case 1: //test
      TEST();
      tiempoApagado = 0;
      tiempoFinal = 0;
      estadoBoton = false;
      estado = 2;
      break;

    case 2: // Cuentas las veces que se preciona el boton y si 
            // no se preciona nada en 5 segundos se apaga
      estado = contar(estado, lectura);
      break;

    case 3: // Da una señal que se esta apagando y vuelve al estado 0
      parpadeo(5, 200);
      estado = 0;
      break;
  }
}