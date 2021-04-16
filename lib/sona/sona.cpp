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

void Sona::get_data(unsigned char* data,int data_size){
    if(data_size == sizeof(sona_data)){
        for(int i = 0;i<data_size;i++){
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
            //如果沒有觸發標頭錯誤的條件時，sona_data_buffer_flag繼續加上去
            sona_data_buffer_flag++;

            //當sona_data_        return true;buffer放滿時，開始做資料處理
            if(sona_data_buffer_flag > 9){

                unsigned char check_num = 0;//確認標尾是否正確的暫存空間

                //標尾內容為[0] ～ [8]相加後 == [9]
                for(int i = 0;i<9;i++){
                    check_num += sona_data_buffer[i];
                }
                 //確認標尾正確
                if(check_num == sona_data_buffer[9]){
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