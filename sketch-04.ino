/*
Velocidad Minima: 1330
Velocidad Maxima: 2280
-----------------------
PIN 3 eje blancon Left
PIN 5 eje blancon Right
PIN 6 eje rojo Back
PIN 9 eje rojo Front
*/
#include <Servo.h>
#define number_of_servos 4 // Constante para definir cantidad de motores
int servoPins[] ={ 3, 5, 6, 9 }; // Definicion de Pins a usar
Servo servos[number_of_servos]; // Declaracion de objetos tipo Servo de size Number_of_servos
int led = 13;

// Conectando los Servos a los PINS definidos en servoPins array
void initEngines(){
  for(int i = 0; i < number_of_servos; i++) {
    servos[i].attach(servoPins[i]);
  }
}

void setup(){
  //Serial.begin(9600);
  initEngines();
  delay(100);
  pinMode(led, OUTPUT);
  for(int i=0; i<number_of_servos; i++) {
    servos[i].writeMicroseconds(1000);
  }
  delay(1000);
}

void loop() {
  // Senal de iniciacion. enciende y apaga El LED 3 veces en un periodo de 3 Segundos
  for(int i = 0; i < 3; i++) {
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
  }
  // Prueba de motores antes de iniciar el vuelo
  // Enciende motores por un segundo uno por uno
  for(int i = 0; i < number_of_servos; i++) {
    digitalWrite(led,HIGH);
    servos[i].writeMicroseconds(1330);
    delay(1000);
    digitalWrite(led,LOW);
    servos[i].writeMicroseconds(1000);
  }
  //Inicia vuelo por 5 segs
  for(int i = 0; i < number_of_servos; i++) {
    servos[i].writeMicroseconds(2000);
  }
  delay(5000);
  //Finalizacion de vuelo
  for(int i = 0; i < number_of_servos; i++) {
    servos[i].writeMicroseconds(1000);
  }
  delay(5000);
 }

