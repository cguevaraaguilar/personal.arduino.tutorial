/*
Descripcion:  Sketch que parpadea el led interconstuido (PIN13) cada medio segundo.
Autor:        Carlos Ernesto Guevara Aguilar.
F. Creacion:  30 de mayo de 2020.
F. Cambio:    30 de mayo de 2020
Comentarios:  
*/

// delay
int wait = 500;  // 500 ms

// Inicializa
void setup () {
  
  pinMode(LED_BUILTIN, OUTPUT);
} // void setup () {
  
void loop () {
  
  digitalWrite(LED_BUILTIN, LOW);
  delay (wait);
  digitalWrite(LED_BUILTIN, HIGH);
  delay (wait);
} //void loop () {
