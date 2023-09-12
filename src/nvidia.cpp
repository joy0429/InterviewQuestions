#include "nvidia.h"

nvidiaQ :: nvidiaQ(){

}

/******************************************************************************************
 * @brief   Q. Implement abs() w/o branching
 * @details A. When we want to get the negeative of num, by 2's complement, we would XOR 
 *             num with itself, then add 1. By and so, if we want to get positive of num, 
 *             we can add num with 31th bit of itself(called mask, similar to adding 1), 
 *             then XOR (num + mask) with mask.
 *          Time Complexity:    O(1)
 *          Space Complexity:   O(1)
******************************************************************************************/
void nvidiaQ :: abs_woBranch(){
    int num = -6,
        mask = num >> sizeof(int) * 8 - 1;
    cout << "Before abs: " << num << endl;
    cout << "After abs: " << ((num + mask) ^ mask) << endl;
    return;
}

nvidiaQ :: ~nvidiaQ(){
    
}