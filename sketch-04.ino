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
#include <Ultrasonic.h>

#define number_of_servos 4 // Constante para definir cantidad de motores
int servoPins[] ={ 3, 5, 6, 9 }; // Definicion de Pins a usar
Servo servos[number_of_servos]; // Declaracion de objetos tipo Servo de size Number_of_servos

// Define PINS para la data del sensor de ultra sonido 12(Trigger PIN) 13(Echo PIN)
#define TRIGGER_PIN  12
#define ECHO_PIN     13

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
int led = 13;

// Conectando los Servos a los PINS definidos en servoPins array
void initEngines(){
  for(int i = 0; i < number_of_servos; i++) {
    servos[i].attach(servoPins[i]);
  }
}

long radar(){
  long microsec = ultrasonic.timing();
  microsec = constrain(microsec, 0, 4000);
  long distance = map(microsec, 0, 4000,2285,1000);
  //Serial.print("MS: ");
  //Serial.print(distance);
  //Serial.print("\n");
  return distance;
}

void setup(){
  Serial.begin(9600);
  initEngines();
  delay(100);
  //pinMode(led, OUTPUT);
  for(int i=0; i<number_of_servos; i++) {
    servos[i].writeMicroseconds(1000);
  }
  // Senal de iniciacion. enciende y apaga El LED 3 veces en un periodo de 3 Segundos
  for(int i = 0; i < 3; i++) {
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
  }
  delay(1000);
}

void loop() {
      long myradar = radar();

         for(int i = 0; i < number_of_servos; i++) {
            servos[i].writeMicroseconds(myradar);
         }
      delay(100);
 }

