#include "nvidia.h"

nvidiaQ :: nvidiaQ(){

}

/******************************************************************************************
 * @brief   Q. The code below is doing string initialization, what's the potential problem
 *             in this code?
 * @details A. First problem, this string would lost NULL end('\0') due to all bytes are 0
 *             in string with size 128 bytes.
 *             Second, the max value of char c is 127, but the size of str is 128. Char c
 *             would become 0 due to overflow after adding 1 when char c = 127. This cause
 *             a infinite loop in runtime.
 * @related #bitwise operation #debug
******************************************************************************************/
void nvidiaQ :: debug(){
    char c;
    char str[128];
    assert(0 && "Strlen(&str[0]) is 128, it would become infinite loop in below code"); 
    for(char c = 0; c < 128; c++){
        str[c] = 0;
    }
}

/******************************************************************************************
 * @brief   Q. Implement abs() w/o branching
 * @details A. When we want to get the negeative of num, by 2's complement, we would XOR 
 *             num with itself, then add 1. By and so, if we want to get positive of num, 
 *             we can add num with 31th bit of itself(called mask, similar to adding 1), 
 *             then XOR (num + mask) with mask.
 *          Time Complexity:    O(1)
 *          Space Complexity:   O(1)
 * @related #bitwise operation
******************************************************************************************/
void nvidiaQ :: abs_woBranch(){
    int num, mask, afterMask, ans;
    
    cout << "Negative integer:  ";
    cin >> num;

    mask = num >> sizeof(int) * 8 - 1;
    afterMask = num + mask;
    ans = afterMask ^ mask;

    bitset<32> bNum(num), bMask(mask), bAfterMask(afterMask), bAns(ans);

    cout << "Num:                " << num << ", " << bNum << endl;
    cout << "Mask:               " << mask << ", " << bMask << endl;
    cout << "Num + mask:         " << afterMask << ", " << bAfterMask << endl;
    cout << "(Num + mask) ^ mask: " << ans << ", " << bAns << endl;
    return;
}

/******************************************************************************************
 * @brief   Q. Write a function that takes an unsigned integer and returns the number of 
 *             '1' bits it has (also known as the Hamming weight).
 * @details A. [Brian Kernighan's Algorithm] Editing last digit to opposite value by 
 *             (num - 1) and using this value to AND origin num. By and so, only last bit 
 *             would be changed each time, and we only need to increase times when num is
 *             still > 0.
 *          Time Complexity:    O(n), n: num of '1' bits
 *          Space Complexity:   O(1)
 * @ref     Leetcode 191. Number of 1 Bits
 * @related #bitwise operation
******************************************************************************************/
void nvidiaQ :: numOf1Bits(){
    int num, ans = 0;
    
    cout << "Integer: ";
    cin >> num;

    bitset<32> bNum(num);

    while(num){
        num &= (num - 1);
        ans++;
    }

    cout << "num's binary: " << bNum << endl;
    cout << "Num of 1 bit: " << ans << endl;
}

nvidiaQ :: ~nvidiaQ(){
    
}