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
    void memCpy();
    ~nvidiaQ();

    vector<string> funcNameList = {"debug", "abs_woBranch", "numOf1Bits", "memAlignMallocFree", "memCpy"};
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
    void myMemCpy(void *dest, const void *src, size_t count);
    ~memoryCtrl();

    char memoryPool[1024];
    record* freeList = reinterpret_cast<record*>(memoryPool);
};