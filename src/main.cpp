#include <Arduino.h>
int i = 0;
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  if(Serial1.available()){
    Serial.print(Serial1.read());
    Serial.print(" ");
    i++;
  }
  if(i==10) 
    {Serial.println();
    i = 0;
    }
 }