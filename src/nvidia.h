#include <iostream>
#include <string>
#include <vector>
using namespace std;

class nvidiaQ{
public:
    nvidiaQ();
    void abs_woBranch();
    ~nvidiaQ();

    vector<string> funcNameList = {"abs_woBranch"};
};