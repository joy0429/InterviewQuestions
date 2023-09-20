#include <bitset>
#include <cassert>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;

struct tree{
    int val;
    tree *left;
    tree *right;
    tree() : val(0), left(NULL), right(NULL) {};
    tree(int val) : val(val), left(NULL), right(NULL) {};
    tree(int val, tree *left, tree *right) : val(val), left(left), right(right) {};
};

struct linkedList{
    int val;
    linkedList *next;
    linkedList(int val) : val(val), next(NULL) {};
};

class nvidiaQ{
public:
    nvidiaQ();
    void debug();
    void abs_woBranch();
    void numOf1Bits();
    void memAlignMallocFree();
    void memCpy();
    void checkValidBT();
    bool isValidBST(tree *root, tree *min, tree *max);
    void reverseListResult();
    linkedList* reverseList(linkedList *head, int start, int end);
    ~nvidiaQ();

    vector<string> funcNameList = {"debug", "abs_woBranch", "numOf1Bits", "memAlignMallocFree", "memCpy",
                                   "checkValidBT", "reverseListResult"};
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