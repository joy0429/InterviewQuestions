#include "main.h"

int main(){
    int company = 0, question = 0;

    cout << "Companies List NO.:" << endl;
    for(int idx = 0; idx < companiesList.size(); idx++){
        cout << companiesList[idx] << ": " << idx << "\t";
        if((idx > 0) && ((idx + 1) % 5 == 0)) cout << endl;
    }

    cout << "\nEnter Company No.: ";
    CATCH_ERR(company, companiesList.size());
    cout << endl;

    // TODO: Add other companies question & function pointer
    nvidiaQ NvidiaQ;
    function<void(nvidiaQ*)> nvidiaQList[] = {&nvidiaQ::debug,              &nvidiaQ::abs_woBranch, 
                                              &nvidiaQ::numOf1Bits,         &nvidiaQ::memAlignMallocFree, 
                                              &nvidiaQ::memCpy,             &nvidiaQ::checkValidBT,
                                              &nvidiaQ::reverseListResult,  &nvidiaQ::parallelProcess,
                                              &nvidiaQ::showEachChar,       &nvidiaQ::showNthElement,
                                              &nvidiaQ::anagramResult,      &nvidiaQ::sysClock};

    switch (company){
        case COMPANY_NVIDIA:
            for(int idx = 0; idx < NvidiaQ.funcNameList.size(); idx++){ 
                cout << idx << ": " << NvidiaQ.funcNameList[idx] << endl;
            }
            cout << "Enter Question No.: ";
            using funcTuple = tuple<void (nvidiaQ::*)()>;
            CATCH_ERR(question, NvidiaQ.funcNameList.size());
            nvidiaQList[question](&NvidiaQ);
            break;
        default:
            break;
    }    
    return 0;
}