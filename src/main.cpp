#include <Arduino.h>
#include "sona.h"

Sona s(2,9600);
unsigned char data[10];
void setup() {
  Serial.begin(9600);
  s.init();
}

void loop() {
if(s.uart2_data()){
      s.get_data(data,sizeof(data));
      for(int i = 0;i < 10;i++){
    Serial.print(data[i]);
    Serial.print(" ");
      }
  Serial.println();
}
}

void serialEvent2(){
  //s.uart2_data();
}