#ifndef SONA_H_
#define SONA_H_
struct sona_data
{
    short head;
    short data[8];
    short check;
};

class Sona{
    public:
        Sona(int _uart_num,int _uart_baud);
        void init();
        void get_data(int *sona_data);
        void data_processing();
    private:
        int uart_num;
        int uart_baud;
        int data_buffer_flag;
        int data_buffer[10];
    public:
        struct sona_data data;
        
};
#endif