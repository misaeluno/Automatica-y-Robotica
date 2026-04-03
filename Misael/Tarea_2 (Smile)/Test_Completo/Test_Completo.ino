bool Boton_Estado          =  false;
int Estado_dia            =  0;
int Hora                  =  0;
int Estado_Luz            =  0;

const int boton           =  2;   
const int Led_1     =  4;
const int Led_2     =  5;
const int Led_3     =  6;
const int Led_4     =  7;
const int Led_5     =  8;
const int Led_6     =  9;

void setup() {
  // put your setup code here, to run once:
  pinMode(Led_1, OUTPUT);
  pinMode(Led_2, OUTPUT);
  pinMode(Led_3, OUTPUT);
  pinMode(Led_4, OUTPUT);
  pinMode(Led_5, OUTPUT);
  pinMode(Led_6, OUTPUT);
  pinMode(boton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Hora==0){
// -Parpadeo por 2 segundos --
    digitalWrite(Led_1, HIGH);
    digitalWrite(Led_2, HIGH);
    digitalWrite(Led_3, HIGH);
    digitalWrite(Led_4, HIGH);
    digitalWrite(Led_5, HIGH);
    digitalWrite(Led_6, HIGH);
    delay(250);
    digitalWrite(Led_1, LOW);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_4, LOW);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_6, LOW);
    delay(250);
    digitalWrite(Led_1, HIGH);
    digitalWrite(Led_2, HIGH);
    digitalWrite(Led_3, HIGH);
    digitalWrite(Led_4, HIGH);
    digitalWrite(Led_5, HIGH);
    digitalWrite(Led_6, HIGH);
    delay(250);
    digitalWrite(Led_1, LOW);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_4, LOW);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_6, LOW);
    delay(250);
    digitalWrite(Led_1, HIGH);
    digitalWrite(Led_2, HIGH);
    digitalWrite(Led_3, HIGH);
    digitalWrite(Led_4, HIGH);
    digitalWrite(Led_5, HIGH);
    digitalWrite(Led_6, HIGH);
    delay(250);
    digitalWrite(Led_1, LOW);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_4, LOW);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_6, LOW);
    delay(250);
    digitalWrite(Led_1, HIGH);
    digitalWrite(Led_2, HIGH);
    digitalWrite(Led_3, HIGH);
    digitalWrite(Led_4, HIGH);
    digitalWrite(Led_5, HIGH);
    digitalWrite(Led_6, HIGH);
    delay(250);
    digitalWrite(Led_1, LOW);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_4, LOW);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_6, LOW);
    delay(250);
//----------------------------
    // LLenado Asendente
    digitalWrite(Led_1, HIGH);
    delay(500);
    digitalWrite(Led_1, LOW);
    digitalWrite(Led_2, HIGH);
    delay(500);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_3, HIGH);
    delay(500);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_4, HIGH);
    delay(500);
    digitalWrite(Led_4, LOW);
    digitalWrite(Led_5, HIGH);
    delay(500);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_6, HIGH);
    //------------------------
    delay(500);
    digitalWrite(Led_1, HIGH);
    delay(500);
    digitalWrite(Led_1, LOW);
    digitalWrite(Led_2, HIGH);
    delay(500);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_3, HIGH);
    delay(500);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_4, HIGH);
    delay(500);
    digitalWrite(Led_4, LOW);
    digitalWrite(Led_5, HIGH);
    //-----------------------
    delay(500);
    digitalWrite(Led_1, HIGH);
    delay(500);
    digitalWrite(Led_1, LOW);
    digitalWrite(Led_2, HIGH);
    delay(500);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_3, HIGH);
    delay(500);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_4, HIGH);
    //------------------------
    delay(500);
    digitalWrite(Led_1, HIGH);
    delay(500);
    digitalWrite(Led_1, LOW);
    digitalWrite(Led_2, HIGH);
    delay(500);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_3, HIGH);
    //-----------------------
    delay(500);
    digitalWrite(Led_1, HIGH);
    delay(500);
    digitalWrite(Led_1, LOW);
    digitalWrite(Led_2, HIGH);
    //------------------------
    delay(500);
    digitalWrite(Led_1, HIGH);
    //------------------------
    //------------------------
    // Ida 
    delay(500);
    digitalWrite(Led_1, LOW);
    //------------------------
    delay(500);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_1, HIGH);
    delay(500);
    digitalWrite(Led_1, LOW);
    //------------------------
    delay(500);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_2, HIGH);
    delay(500);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_1, HIGH);
    delay(500);
    digitalWrite(Led_1, LOW);
    //------------------------
    delay(500);
    digitalWrite(Led_4, LOW);
    digitalWrite(Led_3, HIGH);
    delay(500);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_2, HIGH);
    delay(500);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_1, HIGH);
    delay(500);
    digitalWrite(Led_1, LOW);
    //------------------------
    delay(500);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_4, HIGH);
    delay(500);
    digitalWrite(Led_4, LOW);
    digitalWrite(Led_3, HIGH);
    delay(500);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_2, HIGH);
    delay(500);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_1, HIGH);
    delay(500);
    digitalWrite(Led_1, LOW);
    //------------------------
    digitalWrite(Led_6, LOW);
    digitalWrite(Led_5, HIGH);
    delay(500);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_4, HIGH);
    delay(500);
    digitalWrite(Led_4, LOW);
    digitalWrite(Led_3, HIGH);
    delay(500);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_2, HIGH);
    delay(500);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_1, HIGH);
    delay(500);
    digitalWrite(Led_1, LOW);
    delay(500);
    //------------------------
    //------------------------
    // LLenado Desendente
    delay(500);
    digitalWrite(Led_6, HIGH);
    delay(500);
    digitalWrite(Led_6, LOW);
    digitalWrite(Led_5, HIGH);
    delay(500);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_4, HIGH);
    delay(500);
    digitalWrite(Led_4,LOW);
    digitalWrite(Led_3, HIGH);
    delay(500);
    digitalWrite(Led_3,LOW);
    digitalWrite(Led_2, HIGH);
    delay(500);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_1, HIGH);
    //--------------------------
    delay(500);
    digitalWrite(Led_6, HIGH);
    delay(500);
    digitalWrite(Led_6, LOW);
    digitalWrite(Led_5, HIGH);
    delay(500);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_4, HIGH);
    delay(500);
    digitalWrite(Led_4,LOW);
    digitalWrite(Led_3, HIGH);
    delay(500);
    digitalWrite(Led_3,LOW);
    digitalWrite(Led_2, HIGH);
    //--------------------------
    delay(500);
    digitalWrite(Led_6, HIGH);
    delay(500);
    digitalWrite(Led_6, LOW);
    digitalWrite(Led_5, HIGH);
    delay(500);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_4, HIGH);
    delay(500);
    digitalWrite(Led_4,LOW);
    digitalWrite(Led_3, HIGH);
    //--------------------------
    delay(500);
    digitalWrite(Led_6, HIGH);
    delay(500);
    digitalWrite(Led_6, LOW);
    digitalWrite(Led_5, HIGH);
    delay(500);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_4, HIGH);
    //--------------------------
    delay(500);
    digitalWrite(Led_6, HIGH);
    delay(500);
    digitalWrite(Led_6, LOW);
    digitalWrite(Led_5, HIGH);
    //--------------------------
    delay(500);
    digitalWrite(Led_6, HIGH);
    //--------------------------
    // Salida
    delay(500);
    digitalWrite(Led_6, LOW);
    //-----------------------
    delay(500);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_6, HIGH);
    delay(500);
    digitalWrite(Led_6, LOW);
    //-----------------------
    delay(500);
    digitalWrite(Led_4, LOW);
    digitalWrite(Led_5, HIGH);
    delay(500);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_6, HIGH);
    delay(500);
    digitalWrite(Led_6, LOW);
    //-----------------------
    delay(500);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_4, HIGH);
    delay(500);
    digitalWrite(Led_4, LOW);
    digitalWrite(Led_5, HIGH);
    delay(500);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_6, HIGH);
    delay(500);
    digitalWrite(Led_6, LOW);
    //-----------------------
    delay(500);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_3, HIGH);
    delay(500);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_4, HIGH);
    delay(500);
    digitalWrite(Led_4, LOW);
    digitalWrite(Led_5, HIGH);
    delay(500);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_6, HIGH);
    delay(500);
    digitalWrite(Led_6, LOW);
    //-----------------------
    delay(500);
    digitalWrite(Led_1, LOW);
    digitalWrite(Led_2, HIGH);
    delay(500);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_3, HIGH);
    delay(500);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_4, HIGH);
    delay(500);
    digitalWrite(Led_4, LOW);
    digitalWrite(Led_5, HIGH);
    delay(500);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_6, HIGH);
    delay(500);
    digitalWrite(Led_6, LOW);
    delay(500);
    //-----------------------
//---------------------------
    digitalWrite(Led_1, HIGH);
    delay(500);
    digitalWrite(Led_1, LOW);
    digitalWrite(Led_2, HIGH);
    delay(500);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_3, HIGH);
    delay(500);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_4, HIGH);
    delay(500);
    digitalWrite(Led_4, LOW);
    digitalWrite(Led_5, HIGH);
    delay(500);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_6, HIGH);
    delay(500);
    //------------------------
    digitalWrite(Led_6, LOW);
    digitalWrite(Led_5, HIGH);
    delay(500);
    digitalWrite(Led_5, LOW);
    digitalWrite(Led_4, HIGH);
    delay(500);
    digitalWrite(Led_4, LOW);
    digitalWrite(Led_3, HIGH);
    delay(500);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_2, HIGH);
    delay(500);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_1, HIGH);
    delay(500);
    digitalWrite(Led_1, LOW);
    delay(500);
    //-----------------------
    Hora = Hora +1;
  }

}
