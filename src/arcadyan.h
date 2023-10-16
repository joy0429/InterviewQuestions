#include <stdio.h>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

#define ADDR_BASE       0x020000
#define ADDR_UART_TX    (ADDR_BASE + 0x0000E0)
#define MUL(x, y)       x * x * y 

class arcadyanQ{
public:
    arcadyanQ();
    void UartTx(unsigned char cuart_tx);
    void Q1();
    void Q2();
    void Q3();
    void func(int *int1, int *int2);
    void Q4();
    void swap(int c, int d);
    void Q5();
    void Q6();
    void Q7();
    void Q8();
    void Q9();
    void setBit(int &x, int b);
    void clrBit(int &x, int b);
    void xorBit(int &x, int b);
    void Q10();
    ~arcadyanQ();

    int tmp[ADDR_UART_TX + 1] = {0};

    vector<string> funcNameList = {"Q1", "Q2", "Q3", "Q4", "Q5",
                                   "Q6", "Q7", "Q8", "Q9","Q10"};
};