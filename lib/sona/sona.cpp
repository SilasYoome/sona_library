#include "Sona.h"
#include "Arduino.h"
#include <string.h>

Sona::Sona(int _uart_num,int _uart_baud):uart_num(_uart_num),uart_baud(_uart_baud){
    sona_data_buffer[10] = {0};
    sona_data_buffer_flag = 0;
    check_num = 0;
    message_tail = 9;

}
void Sona::init(){
    if(uart_num == 2){
        Serial2.begin(9600);
    }
}

void Sona::get_data(unsigned char* data,int data_size){
    if(data_size == sizeof(sona_data)){
        //僅將sona[1] ~ sona[8]傳出，[0]與[9]是標頭標尾，不需要傳出
        for(int i = 1;i<data_size;i++){
            data[i] = sona_data[i]++;
        }
    }
}


bool Sona::uart2_data(){
    while (Serial2.available())
    {
        sona_data_buffer[sona_data_buffer_flag] = Serial2.read(); //uart2接收資料依序放進sona_data_buffer

        if(sona_data_buffer_flag == 0 && sona_data_buffer[sona_data_buffer_flag] != 0xFF){
            //如果標頭不為0xFF時，退回0重新放資料
            sona_data_buffer_flag = 0;
            break;
        } else{
            
            check_num += sona_data_buffer[sona_data_buffer_flag];

            //如果沒有觸發標頭錯誤的條件時，sona_data_buffer_flag繼續加上去
            sona_data_buffer_flag++;

            //當sona_data_buffer_flag>9，表示buffer放滿，開始做資料處理
            if(sona_data_buffer_flag > message_tail){

                 //確認標尾正確後放入另外一個空間sona_data，用來存正確的資料
                if(check_num-sona_data_buffer[sona_data_buffer_flag] == sona_data_buffer[sona_data_buffer_flag]){
                    memcpy(sona_data,sona_data_buffer,sizeof(sona_data_buffer));
                }
                check_num = 0;//確認碼暫存空間歸零
                sona_data_buffer_flag = 0;//旗標歸0
            }
        }
        return true;
    }
    return false;
    
}