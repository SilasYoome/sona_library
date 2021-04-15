#include <Arduino.h>
int i = 0;
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  int data = 0;
  if(Serial1.available()){
    data = Serial.read();
    Serial.print(data);
    Serial.print(" ");
    i++;
  }
  if(i==10) 
    {Serial.println();
    i = 0;
    }
 }