#include <Thread.h>
#include <ThreadController.h>

/*
  Description:  Código que reliza la lectura de eventos de botón y parpadeo de led de manera asíncrona.
  Author:       Carlos Ernesto Guevara Aguilar.
  Creation:     3 de Febrero de 2018.
  Update:       6 de Septiembre de 2018.
  Comments:
                6 de Septiembre de 2018.
                  Se reorganizó el código.
*/
 
// Controlador de hilos
ThreadController moContrroller = ThreadController();

// Hilo como apuntador
Thread* moThreadReadButton = new Thread();
// Hilo como objeto
Thread moThreadBlinkLED = Thread();

// pin del botón - D02
int mnPushButton = 2;
// último estado del botón. 1 - Oprimido, 0 - Libre. (Al establecerse en 1, el primer mensaje de la aplicación es estado cerrado.)
int mnButtonState = 1;

// Periodo, en milisegundos, en que se debe actualizar el LED. 
int mnTimeBlinckLED = 1000;
// Pediodo, en milisegundos, en que se debe actualizar la lectura del botón.
int mnTimeReadButton = 100;

// Estado del LED. 1 - Encendido, 0 - Apagado.
boolean mnLEDStatus = true;

// Mensajes de la aplicación.
// Mensajes del estado de la aplicación.
String msButtonState = "El estado del botón en D02 es: ";
String msButtonPressed = "Presionado";
String msButtonOpen = "Abierto";

// Configura el entorno de ejecución.
void setup(){

  // Habilita comunicación serial.
  Serial.begin(9600);

  // Inicializa el led de salida (Por default el 13)
  pinMode(LED_BUILTIN, OUTPUT);

  // Inicializa el led de entrada.
  pinMode (mnPushButton, INPUT);

  // Configura hilo de lecutra de botón.
  moThreadReadButton->onRun(readButtonState);
  moThreadReadButton->setInterval(mnTimeReadButton);

  // Configura hilo de parpadeo de LED.
  moThreadBlinkLED.onRun(blinkLED);
  moThreadBlinkLED.setInterval(mnTimeBlinckLED);

  // Agrega los hilos al controlador.
  moContrroller.add(moThreadReadButton);
  moContrroller.add(&moThreadBlinkLED); // & to pass the pointer to it
} // void setup(){

// Proceso principal
void loop(){

  // Inicia la ejecución de los hilos
  moContrroller.run();
} // void loop(){

// Lee si hay un click
void readButtonState(){

  int lnNewState = digitalRead (mnPushButton);  // Lee el estado de D02

  // Si cambió el estado del botón.
  if (lnNewState != mnButtonState) {

    // Lo actualiza
    mnButtonState = lnNewState;

    // Indica el nuevo estado.
    if (mnButtonState) {

      // Si presionado.
      Serial.println (msButtonState + msButtonPressed);
    } else {

      // Si abierto.
      Serial.println (msButtonState + msButtonOpen);
      
    } // if (mnButtonState) {
  } // if (lnNewState != mnButtonState) {
} // void readButtonState(){ 

// Parpadea led en D13 
void blinkLED(){

    // Actualiza el led (D13).
    digitalWrite(LED_BUILTIN, mnLEDStatus);   
    // Cambia el estatus del LED para el siguiente ciclo.
    mnLEDStatus = !mnLEDStatus;
} // void blinkLED(){
