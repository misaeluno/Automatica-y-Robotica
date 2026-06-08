// PARA EL MISA CON MUCHO AMOR <3<3<3
#define si if
#define sino else
#define entero int
#define real float
#define constante const
#define raizCuadrada sqrt

#define inicializacion setup
#define bucle loop

#define lecturaAnaloga analogRead

#define vacio void

#define limitar constrain

#define demora_ms delay

// LA CELESTE ME VA A MATAR POR ESTO. QUE SEPA QUE LO HAGO POR EL MISA :')
// ESTO ES ALGO QUE EXISTE Y QUE SE LLAMA "SOBRECARGAR FUNCIÓN".
// DECLARAS LA MISMA FUNCIÓN, PERO CON PARAMETROS DISTINTOS PARA
// QUE PUEDAN SER RECIVIDOS EN DISTINTAS CIRCUNSTANCIAS
vacio SerialIniciar(entero N) {
  Serial.begin(N);
}

// Para texto
vacio SerialImprimir(String texto) {
  Serial.print(texto);
}

// Para números enteros
vacio SerialImprimir(entero numero) {
  Serial.print(numero);
}

// Para números decimales
vacio SerialImprimir(real numero) {
  Serial.print(numero);
}

vacio SerialImprimirLinea(String texto) {
  Serial.println(texto);
}

vacio SerialImprimirLinea(entero numero) {
  Serial.println(numero);
}

// Para decimales con número de cifras
vacio SerialImprimir(real numero, entero decimales) {
  Serial.print(numero, decimales);
}

vacio SerialImprimirLinea(real numero, entero decimales) {
  Serial.println(numero, decimales);
}

// ESCRITURA ESTANDAR DE VARIABLES y funciones
// tipado nombreApellido = valor;

// PARA CONSTANTES
// constante tipado2 NOMBRE_APELLIDO = valor;

// <3<3<3

// CÓDIGO DEL JOYSTICK
// MI JOYSTICK ES ANÁLOGO
// SU ORIGEN (0.0, 0.0) ES EN LA ESQUINA INFERIOR DERECHA
// SUS VALORES ANÁLOGOS SON ENTRE 0 - 1023 EN AMBOS EJES
// EL CENTRO SE ENCUENTRA EN 511.5 EN AMBOS EJES

// ESTÉ CÓDIGO BUSCA LOS SIGUIENTES VALORES:
// 1. Los valores análogos de cada eje
// 2. Un valor entre 0.0 y 1.0 desde el centro del joystick hasta los extremos de este
// 3. Un valor entre -1.0 y 1.0 para cada eje (0.0 en centro) que nos dé la magnitud entre el centro y la dirección del joystick tomada

// -- PINES --
// EJE X DEL JOYSTICK
constante entero PIN_JOY_X = A0;
// EJE Y DEL JOYSTICK
constante entero PIN_JOY_Y = A1;

// -- CONSTANTES DE CALIBRACIÓN --
// CENTROS DEL JOYSTICK
constante real CENTRO_X = 511.5f;
constante real CENTRO_Y = 511.5f;

// DESVIACIÓN (ANÁLOGA) MÁXIMA DEL JOYSTICK DESDE EL CENTRO HACIA UN EXTREMO
constante real MAXIMO_ANALOGO = 511.5f; 

// LA MAGNITUD DEL VALOR NORMALIZADO ES
// ES sqrt(1² + 1²) = sqrt(2).
// ESTE VALOR SE REQUIERE PARA CIERTOS CALCULOS
constante real MAXIMA_MAGNITUD = raizCuadrada(2.0f);

// ZONA MUERTA. UNA FRACCIÓN DEL RANGO NORMALIZADO
// QUE SE IGNORA. EVITA QUE EL JOYSTICK TOME VALORES
// DISTINTOS DE 0 EN REPOSO.
// EQUIVALE A UN 5%.
constante real ZONA_MUERTA = 0.05f;

vacio inicializacion() {
  SerialIniciar(9600);
  SerialImprimirLinea("=== Joystick listo ===");
  SerialImprimirLinea("Análogo_X\tAnálogo_y\tNormal_X\tNormal_Y\tMagnitud");
}

vacio bucle() {
  // LECTURA DE VALORES ANÁLOGOS (0 - 1023)
  entero analogoX = lecturaAnaloga(PIN_JOY_X);
  entero analogoY = lecturaAnaloga(PIN_JOY_Y);

  // OBTENER LOS VALORES NORMALES ENTRE -1.0 Y 1.0 CON 0.0 EN CENTRO
  real normalX = (analogoX - CENTRO_X) / MAXIMO_ANALOGO;
  real normalY = (analogoY - CENTRO_Y) / MAXIMO_ANALOGO;

  // CALCULAR MAGNITUD (HIPOTENUSA)
  real magnitud = raizCuadrada(normalX * normalX + normalY * normalY);

  // NORMALIZA ENTRE 0.0 y 1.0
  magnitud /= MAXIMA_MAGNITUD;

  // APLICAR ZONA MUERTA
  si (magnitud < ZONA_MUERTA) {
    magnitud = 0.0f;
  }
  sino {
    // RECALCULAR PARA QUE LA SALIDA DE 0 SEA SUAVE
    magnitud = (magnitud - ZONA_MUERTA) / (1.0f - ZONA_MUERTA);
  }

  // LIMITAR VALORES PARA ESTAR SEGUROS
  magnitud = limitar(magnitud, 0.0f, 1.0f);

  // IMPRIMIR RESULTADOS EN EL Serial
  SerialImprimir(analogoX);   SerialImprimir("\t\t");
  SerialImprimir(analogoY);   SerialImprimir("\t\t");
  SerialImprimir(normalX, 3); SerialImprimir("\t\t");
  SerialImprimir(normalY, 3); SerialImprimir("\t\t");
  SerialImprimirLinea(magnitud, 4);

  // UNA LECTURA POR SEGUNDO (mil milisegundos)
  demora_ms(1000);
}

// UN "ERROR" QUE SE DEBE ARREGLAR ES QUE LA MAGNITUD.
// SOLO ES 1 EN LAS ESQUINAS. ESTABA BUSCANDO UN CALCULO
// QUE PERMITIIEZE OBTENER UN 1 SI EL JOYSTICK ESTABA
// COMPLETAMENTE EN EL EXTREMO, EN CUALQUIER DIRECCIÓN.