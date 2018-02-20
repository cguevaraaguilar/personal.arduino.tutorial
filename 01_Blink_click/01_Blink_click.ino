/*
  Description:  Código que reliza la activación de un led (13) y espera la lectura del push button.
  Author:       Carlos Ernesto Guevara Aguilar.
  Creation:     24 de Enero de 2018.
  Update:       24 de Enero de 2018.
  Comments:
*/

int pushButton = 2;
int buttonState = 0;

// Inicializa la aplicación.
void setup() {

  // Inicializa puerto serial
  Serial.begin (9600);
  
  // Inicializa el led de salida.
  pinMode(LED_BUILTIN, OUTPUT);

  // Inicializa el led de entrada.
  pinMode (pushButton, INPUT);
}

// Loop de Ejecución
void loop() {

  blink ();
  
  
}

void blink () {

  digitalWrite(LED_BUILTIN, HIGH);   // Enciende el led
  readClick ();
  delay(500);                       // Espera un segundo
  digitalWrite(LED_BUILTIN, LOW);    // Apaga el led
  readClick ();
  delay(500);                       // Espera un segundo
}

void readClick () {

  int newState = digitalRead (pushButton);  // Lee el estado de D02

  // Si cambió el estado del botón.
  if (newState != buttonState) {

    // Lo actualiza
    buttonState = newState;

    // Indica el nuevo estado.
    Serial.println (buttonState);
  }

}

