#include <Arduino.h>
#define FIRST_PIN 3
#define SENSOR A0
#define MIN 276
#define MAX 285
void showVol(int vol);
void setup() {
Serial.begin(9600);
Serial.println("Ready");
pinMode(FIRST_PIN, OUTPUT);
pinMode(FIRST_PIN+1,OUTPUT);
pinMode(FIRST_PIN+2,OUTPUT);
pinMode(FIRST_PIN+3,OUTPUT);
pinMode(FIRST_PIN+4,OUTPUT);
pinMode(SENSOR,INPUT);
}

void loop() {
  // if (Serial.available()) {
  //   int vol = Serial.parseInt();
  //   Serial.println(vol);
  //   showVol(vol);
  // }
showVol(map(analogRead(SENSOR),MIN,MAX,0,5));
//Serial.println(analogRead(SENSOR));

}
void showVol(int vol){\

  digitalWrite(FIRST_PIN, LOW);
  digitalWrite(FIRST_PIN+1, LOW);
  digitalWrite(FIRST_PIN+2, LOW);
  digitalWrite(FIRST_PIN+3, LOW);
  digitalWrite(FIRST_PIN+4, LOW);
  for (int i = 0; i < vol; i++) digitalWrite(FIRST_PIN+i, HIGH);
}
