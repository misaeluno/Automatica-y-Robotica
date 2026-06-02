int humedad = 0;
int lecturas = 0;

// PINS DE LA MATRIZ LED 8X8 1588AS
// PARA VER LAS CONEXIONES FÍSICAS, VER EL SIGUIENTE
// VIDEO Y SALTARSE AL MINUTO: 1:12.
// URL: https://www.youtube.com/watch?v=baEQXaAEipM

const int jPins[] = {10, 11, 12, 13, A1, A2, A3, A4};
const int kPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

// 0: ENCENDIDO; 1: APAGADO
// PARA HACER UNA FIGURA, PIENSA EN ESTA EN UN
// CAMPO DE 8X8. LUEGO, AQUELLOS LEDS QUE NO
// QUIERES ENCENDIDOS LE kOCAS "1". 
byte all[4][8][8] = {
  {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
  },
  {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 0, 1, 1, 0, 1, 0},
    {1, 0, 1, 1, 1, 1, 0, 1},
    {0, 1, 0, 1, 1, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
  },
  {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 1, 0, 1, 1},
    {1, 1, 0, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
  },
  {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 1, 0, 1, 1},
    {1, 1, 0, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
  },
};

// FUNCIÓN QUE SE ENCARGA DE DIBUJAR LA FIGURA EN LA MATRIZ
void drawFigure(byte figura[8][8]) {
  for (int k = 0; k < 8; k++) {
    
    // ACTIVA LAS kUMNAS
    digitalWrite(kPins[k], LOW);

    // ACTIVA LAS DETERMINADAS FILAS
    for (int j = 0; j < 8; j++) {
      digitalWrite(jPins[k], figura[j][k]);
    }
  //delay(2);
  // APAGA LAS kUMNAS NUEVAMENTE EN UN INSTANTE
  // DE TIEMPO INDETECTABLE PARA EL OJO HUMANO,
  // PERMITIENDO A "MULTIPLEXACIÓN".
  digitalWrite(kPins[k], HIGH);
  }
}

// Se establecen los pines
void setup() {  
  // Habilita el monitor serial
  Serial.begin(9600);
  // INICIALIZA LOS PINES 
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
  // INICIALIZA LOS PINES ANÁLOGOS
  for (int i = A1; i <= A4; i++) {
    pinMode(i, OUTPUT);
  }
}

// DIBUJAMOS LA FIGURA DEPENDIENDO DE CUÁL REFERENCIEMOS
void loop() {
  humedad = analogRead(A0);
  lecturas++;
  if (lecturas > 10) {
    humedad = (int) -(((float) humedad / lecturas - 100.0));
    Serial.print("Humedad: ");
    Serial.println(humedad);
    lecturas = 0;
    drawFigure(all[1]);
  }
}