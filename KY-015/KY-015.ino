/*
Descripción:  Lectura de sensor de Humedad KY_015
Autor:        Carlos Ernesto Guevara Aguilar.
F. Creación:  7 de Septiembre de 2018.
F. Cambio:    7 de Septiembre de 2018.
Comentarios:
              Se realizó diagrama con Fritzing en ./fritzing

              KY015 DHT11 Temperature and humidity sensor.
*/

// Velocidad del puerto serial
static const short SERIAL_SPEED = 9600;

// Pin con el que se harán las lecturas del DHT11.
static const byte DHpin = 8;

// Arreglo donde se almacenarán las lecturas.
byte dat [5];

// Incialización
void setup() {

  // Indica la velocidad de ejecución del puerto serial.
  Serial.begin (SERIAL_SPEED);

  // Establece el pin para lectura / escritura.
  pinMode (DHpin, OUTPUT);
} // void setup() {

// Punto de ejecución.
void loop() {

  // Inicializa el sensor
  start_test ();

  // Indica la Humedad, el valor en binario lo convierte a decimal. Parte entera y parte decimal
  Serial.print ("Humedad: ");
  Serial.print (dat [0], DEC);
  Serial.print (".");
  Serial.print (dat [1], DEC);
  Serial.print ("%. ");

  // Indica la Temperatura, el valor en binario lo convierte a decimal. Parte entera y parte decimal
  Serial.print ("Temperatura: ");
  Serial.print (dat [2], DEC);
  Serial.print (".");
  Serial.print (dat [3], DEC);
  Serial.println ("º C");

  // Si error en el checksum  
  if (dat [4] != (dat [0] + dat [1] + dat [2] + dat [3]))
    Serial.println ("Checksum error");

  // Espera un segundo para la siguiente lecutra.
  delay (2000);
} // void loop() {

// Hace una lectura
byte read_data () {

  // Variable de retorno;
  byte result = 0;

  // Lectura de 1 a 8
  for (int i = 0 ; i < 8 ; i++) {

    // Espera hasta que la lectura sea 0, ie el dispositivo esté listo.
    while (digitalRead (DHpin) == LOW);

    // Espera 30 microsegundos.
    delayMicroseconds (30);

    //High in the former, low in the post
    if (digitalRead (DHpin) == HIGH) {
      result |= (1 << (8 - i));
    } // if (digitalRead (DHpin) == HIGH) {

    // Espera hasta el próximo bit de recepción.
    while (digitalRead (DHpin) == HIGH);
  } // for (int i = 0 ; i < 8 ; i++) {

  return (result);
} // byte read_data () {

// Prepara el sensor para lecturas.
void start_test () {

  // Baja el pin para poder enviar la señal de lectura.
  digitalWrite (DHpin, LOW);
  
  // Espera 30 milisegundos.
  delay (30);

  // Sube el pin para poder iniciar la lectura.
  digitalWrite (DHpin, HIGH);

  // Espera al sensor
  delayMicroseconds (40);

  // Permite la lecutura del pin.
  pinMode (DHpin, INPUT);

  // Mientras la lectura es alta
  
  while (digitalRead (DHpin) == HIGH);

  // Espera 80 micro segundos.
  delayMicroseconds (80);
  
  // Si la lectura es baja espera 80 milisegundos
  if  (digitalRead (DHpin) == LOW);
    delayMicroseconds (80);

  // Hace la lectura de los 5 bytes de información.
  for (int i = 0; i < 5; i++) {
    dat [i] = read_data ();
  } // for (int i = 0; i < 5; i++) {

  // Prepara el pin para salida
  pinMode (DHpin, OUTPUT);

  // Indica que ha terminado la lecutra.
  digitalWrite (DHpin, HIGH);
} // void start_test () {
