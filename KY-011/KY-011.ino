/*
Descripción:  KY-011 Two color LED module
Autor:        Carlos Ernesto Guevara Aguilar.
F. Creación:  17 de Septiembre de 2018.
F. Cambio:    17 de Septiembre de 2018.
Comentarios:

              3mm Two color LED module KY-011 for Arduino, emits red and green light. You can adjust the amount of each color using PWM.
              
              Se realizó diagrama con Fritzing en ./fritzing
              El dispositivo no tiene resistencias.
*/

// Velocidad del puerto serial
static const short SERIAL_SPEED = 9600;

// Pin RED
static const byte PIN_RED = 11;

// Pin GREEN
static const byte PIN_GREEN = 10;

// Valor de intencidad
byte val;

// Incialización
void setup() {

  // Indica la velocidad de ejecución del puerto serial.
  Serial.begin (SERIAL_SPEED);

  // Prepara los Pins de sailda
  pinMode (PIN_RED, OUTPUT);
  pinMode (PIN_GREEN, OUTPUT);
} // void setup() {

// Inicio de ejecución
void loop() {

  digitalWrite (PIN_RED, HIGH);
  delay (1000);
  digitalWrite (PIN_RED, LOW);
  delay (1000);

  digitalWrite (PIN_GREEN, HIGH);
  delay (1000);
  digitalWrite (PIN_GREEN, LOW);
  delay (1000);

  digitalWrite (PIN_RED, HIGH);
  digitalWrite (PIN_GREEN, HIGH);
  delay (1000);
  digitalWrite (PIN_RED, LOW);
  digitalWrite (PIN_GREEN, LOW);
  delay (1000);

  for (val = 0 ; val < 254 ; val++) {

    analogWrite (PIN_RED, val);
    delay (4);

  } // for (val = 0 ; val < 254 ; val++) {

  for (val = 255 ; val > 0 ; val--) {

    analogWrite (PIN_RED, val);
    delay (4);

  } // for (val = 255 ; val>= 0 ; val--) {

  for (val = 0 ; val < 254 ; val++) {
  
    analogWrite (PIN_GREEN, val);
    delay (4);

  } // for (val = 0 ; val < 255 ; val++) {

  for (val = 255 ; val > 0 ; val--) {

    analogWrite (PIN_GREEN, val);
    delay (4);

  } // for (val = 255 ; val > 0 ; val--) {

  for (val = 0 ; val < 254 ; val++) {
  
    analogWrite (PIN_RED, val);
    analogWrite (PIN_GREEN, val);
    delay (4);

  } // for (val = 0 ; val < 254 ; val++) {

  for (val = 255 ; val > 0 ; val--) {

    analogWrite (PIN_RED, val);
    delay (4);

  } // for (val = 255 ; val > 0 ; val--) {

} // void loop() {
