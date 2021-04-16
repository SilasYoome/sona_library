#ifndef SONA_H_
#define SONA_H_

class Sona{
    public:
        Sona(int _uart_num,int _uart_baud);
        void init();//初始化
        void get_data(unsigned char* data,int data_size) ;//將sona_data回傳
        bool uart2_data();//uart2中斷接收
    private:
        int uart_num;//uart port 預設是uart2
        int uart_baud;//uart 鮑率
        int sona_data_buffer_flag;//sona_data_buffer儲存旗標
        //unsigned char check_num;
        unsigned char sona_data_buffer[10];//sona接收資料暫存區
        unsigned char sona_data[10];//確認資料正確後的sona資料存放區
    public:
        
};
#endif