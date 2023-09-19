#include <bitset>
#include <cassert>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;

class nvidiaQ{
public:
    nvidiaQ();
    void debug();
    void abs_woBranch();
    void numOf1Bits();
    void memAlignMallocFree();
    ~nvidiaQ();

    vector<string> funcNameList = {"debug", "abs_woBranch", "numOf1Bits", "memAlignMallocFree"};
};

struct record{
    size_t size;    //8 Bytes
    bool free;      //8 Bytes(base on compiler)
    record* next;   //8 Bytes
};

class memoryCtrl : nvidiaQ{
public:
    memoryCtrl();
    void* myMalloc(size_t size);
    void myFree(void *ptr);
    ~memoryCtrl();

    char memoryPool[1024];
    record* freeList = reinterpret_cast<record*>(memoryPool);
};