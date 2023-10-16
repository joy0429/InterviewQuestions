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

    arcadyanQ ArcadyanQ;
    function<void(arcadyanQ*)> arcadyanQList[] = {&arcadyanQ::Q1, &arcadyanQ::Q2, 
                                                  &arcadyanQ::Q3, &arcadyanQ::Q4, 
                                                  &arcadyanQ::Q5, &arcadyanQ::Q6,
                                                  &arcadyanQ::Q7, &arcadyanQ::Q8,
                                                  &arcadyanQ::Q9, &arcadyanQ::Q10};

    switch (company){
        case COMPANY_ARCADYAN:
            for(int idx = 0; idx < ArcadyanQ.funcNameList.size(); idx++){ 
                cout << idx << ": " << ArcadyanQ.funcNameList[idx] << endl;
            }
            cout << "Enter Question No.: ";
            using arcadyanQTuple = tuple<void (arcadyanQ::*)()>;
            CATCH_ERR(question, ArcadyanQ.funcNameList.size());
            arcadyanQList[question](&ArcadyanQ);
            break;
        case COMPANY_NVIDIA:
            for(int idx = 0; idx < NvidiaQ.funcNameList.size(); idx++){ 
                cout << idx << ": " << NvidiaQ.funcNameList[idx] << endl;
            }
            cout << "Enter Question No.: ";
            using NvidiaQTuple = tuple<void (nvidiaQ::*)()>;
            CATCH_ERR(question, NvidiaQ.funcNameList.size());
            nvidiaQList[question](&NvidiaQ);
            break;
        default:
            break;
    }    
    return 0;
}