#ifndef SONA_H_
#define SONA_H_

class Sona{
    public:
        Sona(int _uart_num,int _uart_baud);
        void init();
        void get_data();
        void data_calculation();
        void uart2_data();
    private:
        int uart_num;
        int uart_baud;
        int sona_data_buffer_flag;
        unsigned char sona_data_buffer[10];
        unsigned char sona_data[10];
    public:
        
};
#endif