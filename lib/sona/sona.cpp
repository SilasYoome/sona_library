#include "sona.h"
#include "Arduino.h"
#include <string.h>

Sona::Sona(int _uart_num,int _uart_baud):uart_num(_uart_num),uart_baud(_uart_baud){
    sona_data_buffer[10] = {0};
    sona_data_buffer_flag = 0;

}
void Sona::init(){
    if(uart_num == 2){
        Serial2.begin(9600);
    }
}

void Sona::data_calculation(){
    strncpy(sona_data, sona_data_buffer);
}

void Sona::get_data(){
    
}


void Sona::uart2_data(){
    while (Serial2.available())
    {
        sona_data_buffer[sona_data_buffer_flag] = Serial2.read();
        if(sona_data_buffer_flag == 0 && sona_data_buffer[sona_data_buffer_flag] != 0xFF){
            sona_data_buffer_flag = 0;
            break;
        } else{
            sona_data_buffer_flag++;
            if(sona_data_buffer_flag > 9){
                char check_num = 0;
                for(int i = 0;i<10;i++){
                    check_num += sona_data_buffer[i];
                }
                if(check_num == sona_data_buffer[9]){
                    data_calculation();
                }
                check_num = 0;
                sona_data_buffer_flag = 0;
            }
        }
    }
    
}

void serialEvent2(){
}