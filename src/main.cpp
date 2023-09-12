#include "main.h"

int main(){
    int company = 0, question = 0;

    cout << "Companies List NO.:" << endl;
    for(int idx = 0; idx < companiesList.size(); idx++){
        cout << companiesList[idx] << ": " << idx << "\t";
        if((idx > 0) && ((idx + 1) % 5 == 0)) cout << endl;
    }

    cout << "Enter Company No.: ";
    CATCH_ERR(company);
    cout << "Enter Question No.: ";
    CATCH_ERR(question);
    
    // TODO: Add other companies question
    switch (company)
    {
    case 1:{
        nvidiaQ q;
        break;
    }
    default:
        break;
    }    

    return 0;
}