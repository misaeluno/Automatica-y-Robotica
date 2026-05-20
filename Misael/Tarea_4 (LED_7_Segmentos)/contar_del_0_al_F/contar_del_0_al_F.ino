const int pin[7] = {2, 3, 4, 5, 6, 7, 8};
//                  a, b, c, d, e, f, g


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
  for ( int i = 0; i < 7; i++ ){
    pinMode(pin[i], OUTPUT);
  }

  lightSegments(0);
}

void loop() {
  for (int i = 0; i < 16; i++){
    lightSegments(i);
    delay(1000);
  }

}

//funcion ligySegments
void lightSegments(int numero){
  //rescato el nuemro ingrsado
  byte numerobite = num[numero];
  for (int i = 0; i < 7; i++){
    //consigo los bit de la funcion NUM desde el a->g
    int bit = bitRead(numerobite, i);
    //se enciende el nuemro buscado
    digitalWrite(pin[i], bit);
  }
}