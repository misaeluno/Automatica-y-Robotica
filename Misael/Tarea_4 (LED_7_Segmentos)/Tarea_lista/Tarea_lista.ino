const int pin[7] = {2, 3, 4, 5, 6, 7, 8};
//                  a, b, c, d, e, f, g

const int botones[4] = {10, 11, 12, 13};
bool estadoAnterior[4] = {false, false, false, false};
const int nbotones = 4;

unsigned long tiempoInicio = 0;
const int intervalo = 1000; // 1 segundo
int Cantidad = 0;

int auxilar = 0;

const byte num[16] = {//abcdefg
                      0b0111111, // 0
                      0b0000110, // 1
                      0b1011011, // 2
                      0b1001111, // 3
                      0b1100110, // 4
                      0b1101101, // 5
                      0b1111101, // 6
                      0b0000111, // 7
                      0b1111111, // 8
                      0b1101111, // 9
                      0b1110111, // A
                      0b1111100, // B
                      0b0111001, // C
                      0b1011110, // D
                      0b1111001, // E
                      0b1110001  // F
                      };

void setup() {
  for (int i = 0; i < 7; i++){
    pinMode(pin[i], OUTPUT);
  }

  for (int i = 0; i < nbotones; i++){
    pinMode(botones[i], INPUT_PULLUP); 
  }
}

void loop() {

  for (int i = 0; i < nbotones; i++){
    bool lectura = digitalRead(botones[i]) == LOW; 

    if (lectura == true && estadoAnterior[i] == false){
      auxilar = i;
      Cantidad = 0;
    }

    estadoAnterior[i] = lectura;
  }

  switch(auxilar){
    case 0: ejecutarSecuencia(1); break;
    case 1: ejecutarSecuencia(3); break;
    case 2: ejecutarSecuencia(7); break;
    case 3: ejecutarSecuencia(15); break; 
  }
}

void mostrarNumero(int numero){
  byte numerobite = num[numero];

  for (int i = 0; i < 7; i++){
    int bit = bitRead(numerobite, i);
    digitalWrite(pin[i], bit); // ánodo común
  }
}

void ejecutarSecuencia(int cantidad){

  if (millis() - tiempoInicio >= intervalo){
    tiempoInicio = millis();
    mostrarNumero(Cantidad);
    Cantidad++;
    if (Cantidad > cantidad){
      Cantidad = 0; 
    }
  }
}