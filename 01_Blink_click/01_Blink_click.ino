/*
  Description:  Código que reliza la activación de un led (13) y espera la lectura del push button.
  Author:       Carlos Ernesto Guevara Aguilar.
  Creation:     24 de Enero de 2018.
  Update:       24 de Enero de 2018.
  Comments:
*/

// Pin de lectura D02
int pushButton = 2;

// Estado inicial no presionado del botón
int buttonState = 0;

// Inicializa la aplicación.
void setup() {

  // Inicializa puerto serial
  Serial.begin (9600);
  
  // Inicializa el led de salida (Por default el 13)
  pinMode(LED_BUILTIN, OUTPUT);

  // Inicializa el led de entrada.
  pinMode (pushButton, INPUT);
} // void setup() {

// Loop de Ejecución
void loop() {

  // Invoca la función principal
  blink ();
} // void loop() {

void blink () {

  // Enciende el led
  digitalWrite(LED_BUILTIN, HIGH);   

  // Evalúa el estado de lectura del click (está muy chafa así)
  readClick ();                   
  
  // Espera un segundo
  delay(1000);                       
  
  // Apaga el led
  digitalWrite(LED_BUILTIN, LOW);    

  // Evalúa el estado de lectura del click (está muy chafa así)
  readClick ();

  // Espera un segundo
  delay(500);                       
} // void blink () {

// Lee si hubo evento en el pin
void readClick () {

  // Lee el estado de D02
  int newState = digitalRead (pushButton);  

  // Si cambió el estado del botón.
  if (newState != buttonState) {

    // Lo actualiza
    buttonState = newState;

    // Indica el nuevo estado.
    Serial.println (buttonState);
  } // if (newState != buttonState) {
} // void readClick () {
