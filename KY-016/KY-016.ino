/*
Descripción:  KY-016 RGB Full color LED module.
Autor:        Carlos Ernesto Guevara Aguilar.
F. Creación:  12 de Septiembre de 2018.
F. Cambio:    12 de Septiembre de 2018.
Comentarios:
              Se realizó diagrama con Fritzing en ./fritzing
*/

// Velocidad del puerto serial
static const short SERIAL_SPEED = 9600;

// Pin RED
static const byte PIN_RED = 11;

// Pin GREEN
static const byte PIN_GREEN = 10;

// Pin BLUE
static const byte PIN_BLUE = 9;

// Valor de intencidad
byte val;

// Incialización
void setup() {

  // Indica la velocidad de ejecución del puerto serial.
  Serial.begin (SERIAL_SPEED);

  // Prepara los Pins de sailda
  pinMode (PIN_RED, OUTPUT);
  pinMode (PIN_GREEN, OUTPUT);
  pinMode (PIN_BLUE, OUTPUT);
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

  digitalWrite (PIN_BLUE, HIGH);
  delay (1000);
  digitalWrite (PIN_BLUE, LOW);
  delay (1000);

  digitalWrite (PIN_RED, HIGH);
  digitalWrite (PIN_GREEN, HIGH);
  delay (1000);
  digitalWrite (PIN_RED, LOW);
  digitalWrite (PIN_GREEN, LOW);
  delay (1000);

  digitalWrite (PIN_RED, HIGH);
  digitalWrite (PIN_BLUE, HIGH);
  delay (1000);
  digitalWrite (PIN_RED, LOW);
  digitalWrite (PIN_BLUE, LOW);
  delay (1000);

  digitalWrite (PIN_GREEN, HIGH);
  digitalWrite (PIN_BLUE, HIGH);
  delay (1000);
  digitalWrite (PIN_GREEN, LOW);
  digitalWrite (PIN_BLUE, LOW);
  delay (1000);

  digitalWrite (PIN_RED, HIGH);
  digitalWrite (PIN_GREEN, HIGH);
  digitalWrite (PIN_BLUE, HIGH);
  delay (1000);
  digitalWrite (PIN_RED, LOW);
  digitalWrite (PIN_GREEN, LOW);
  digitalWrite (PIN_BLUE, LOW);
  delay (1000);

} // void loop() {
