#include <bitset>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class nvidiaQ{
public:
    nvidiaQ();
    void debug();
    void abs_woBranch();
    void numOf1Bits();
    ~nvidiaQ();

    vector<string> funcNameList = {"debug", "abs_woBranch", "numOf1Bits"};
};