#include "sona.h"
#include "Arduino.h"
Sona::Sona(int _uart_num,int _uart_baud):uart_num(_uart_num),uart_baud(_uart_baud){
    data_buffer[10] = {0};
    data_buffer_flag = 0;

}
void Sona::init(){
    if(uart_num == 2){
        Serial2.begin(9600);
    }
}

void Sona::get_data(int sona_data[8]){
    while(data_buffer_flag  >= 9 ){
        data_processing();
    }
}

void Sona::data_processing(){
    if(uart_num == 2){
        if(Serial2.available()){
            
        }
    }
}