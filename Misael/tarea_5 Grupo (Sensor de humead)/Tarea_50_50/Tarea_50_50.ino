int columnas[8] = {2,3,4,5,6,7,8,9};
int filas[8]    = {10, 11, 12, 13, A0, A1, A3, A2};

void setup(){ 
  for (int i=0; i<8; i++){
    pinMode(columnas[i], OUTPUT);
    pinMode(filas[i], OUTPUT);
  }
}

const byte caras[4][8][8] ={
  {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 1, 0, 1},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {1, 0, 1, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0}
  },
  {
    {1, 1, 0, 0, 0, 0, 1, 1},
    {0, 0, 1, 0, 0, 1, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0}
  },
  {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0}
  },
  {
    {0, 1, 1, 0, 0, 1, 1, 0},
    {1, 1, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0}
  },
};

void loop(){
   
  for ( int i=0; i<4; i++){
    int numero=i;
    unsigned long inicio = millis();

    while (millis() - inicio < 2000){
      mostrar_cara(numero);
    }
  }
}

void mostrar_cara(int numero){ 
  for (int k=0; k<8; k++){
    // Apga todas las filas por si algo esta encendido
    for( int i=0; i<8; i++){
      digitalWrite(filas[i], HIGH);
    }
    // j para filas y k para columnas
    for (int j=0; j<8; j++){
      digitalWrite(columnas[j], caras[numero][k][j]);
    }
    digitalWrite(filas[k], LOW);
    delayMicroseconds(500);
  }
}
