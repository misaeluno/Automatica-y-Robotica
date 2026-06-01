int columnas[8] = {2,3,4,5,6,7,8,9};
int filas[8]    = {10, 11, 12, 13, A0, A1, A3, A2};

void setup(){ 
  for (int i=0; i<8; i++){
    pinMode(columnas[i], OUTPUT);
    pinMode(filas[i], OUTPUT);
  }
}

const byte caras[8][8] ={
    {0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 1, 0, 1},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {1, 0, 1, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0}
  
};

void loop(){
   
   for (int k=0; k<8; k++){
    // Apga todo mierda
    for( int i=0; i<8; i++){
      digitalWrite(filas[i], HIGH);
    }
    for (int j=0; j<8; j++){
      digitalWrite(columnas[j], caras[k][j]);
    }
    digitalWrite(filas[k], LOW);
  }
}