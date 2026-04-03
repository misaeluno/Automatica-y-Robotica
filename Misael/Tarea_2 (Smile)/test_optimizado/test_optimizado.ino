bool Boton_Estado = false;
int Hora = 0;
const int boton = 2;
const int led[] = {4, 5, 6, 7, 8, 9};
const int nled = 6;

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

void loop() {

  if (Hora == 0){

    parpadeo(5, 200);
    ascendente();
    ida();
    descendente();
    vuelta(); 
    conejo();
    Hora++;
  }
}