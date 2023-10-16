#include "arcadyan.h"

arcadyanQ :: arcadyanQ(){}

/******************************************************************************************
 * @brief   Q1. Assume UartTx() would output 1 character. Please find the error in this code.
 * @related #array #pointer
******************************************************************************************/
void arcadyanQ :: UartTx(unsigned char cuart_tx){
    assert(0 && "We can't assign value to index ADDR_UART_TX"); 
    *((unsigned char*)ADDR_UART_TX) = cuart_tx;
}

void arcadyanQ :: Q1(){
    unsigned char a = 0x10;
    UartTx(a);
    printf("%d\n", tmp[ADDR_UART_TX + 1]);
}

/******************************************************************************************
 * @brief   Q2. Show the result from output.
 * @related #array #pointer            
******************************************************************************************/
void arcadyanQ :: Q2(){
    int arr[] = {10, 20, 30, 40 ,50, 60};
    int *ptr = arr;
    printf("%d\n", arr[2]);         //30
    printf("%d\n", *(arr + 2));     //30
    printf("%d\n", ptr[2]);         //30
    printf("%d\n", *(ptr + 2));     //30
}

/******************************************************************************************
 * @brief   Q3. 
******************************************************************************************/
void arcadyanQ :: Q3(){

}

/******************************************************************************************
 * @brief   Q4. Show the result from output.
 * @related #pointer #prefix/postfix adder #static
******************************************************************************************/
void arcadyanQ :: func(int *int1, int *int2){
    static int var3 = 30;
    int var4 = 40;

    printf("%d, %d, %d, %d\n", ++(*int1), (*int2)++, var3++, var4++);
}

void arcadyanQ :: Q4(){
    static int var1 = 10;
    int var2 = 20;

    func(&var1, &var2); //11, 20, 30, 40
    func(&var1, &var2); //12, 21, 31, 40
}

/******************************************************************************************
 * @brief   Q5. Please help to correct the code to make the code work as expectedto swap a,
 *              b value.
 * @details A. (After correction):
 *              void swap(int *c, int *d){
 *                  int *temp = c;
 *              	...
 *              }
 *              int main(){
 *                  ...
 *                  swap(&a, &b);
 *                  printf("%d %d\n", a, b);    // 10 5
 *              }
 * @related #call by value/reference/address
******************************************************************************************/
void arcadyanQ :: swap(int c, int d){
    int tmp = c;
    c = d;
    d = tmp;
}

void arcadyanQ :: Q5(){
    int a = 5, b = 10;
    swap(a, b);
    printf("%d %d\n", a, b);    //5 10
}

/******************************************************************************************
 * @brief   Q6. After executing the code below, what message will be shown?
 * @details A. 0113234
 * @related #pointer #prefix/postfix adder
******************************************************************************************/
void arcadyanQ :: Q6(){
    char s[] = "0113256";
    char *p = s;
    printf("%c", *p++);     // p points to s[1] after printing the value of s[0]
    printf("%c", *(p++));   // p points to s[2] after printing the value of s[1]
    printf("%c", (*p)++);   // add 1 to s[2] after printing the value
    printf("%c", *++p);     // p moves to s[3] and print the value
    printf("%c", *(++p));   // p moves to s[4] and print the value
    printf("%c", ++*p);     // add 1 to s[4] and print the value
    printf("%c\n", ++(*p)); // add 1 to s[4] and print the value
}

/******************************************************************************************
 * @brief   Q7. After executing the code below, what message will be shown?
 * @details A. All the operataion in macro should be enclosed in parentheses,or it will be
 *             performed separately and sequentially.
 * @related #macro
******************************************************************************************/
void arcadyanQ :: Q7(){
    printf("%d\n", MUL(2, 5));      // 20 (2 * 2 * 5)
    printf("%d\n", MUL(2 + 3, 2));  // 14 (2 + 3 * 2 + 3 * 2)
}

/******************************************************************************************
 * @brief   Q8. After executing the code below, what message will be shown?
 * @details We can see (c = b) as function. c wolud set to 0 and return 0. But the result of
 *          c didn't be changed after ending this function, so the value of c in printf is 6.
 * @related #logic operation
******************************************************************************************/
void arcadyanQ :: Q8(){
    int a = 5, b = 0, c = 6;
    a = (a & b) && (c = b);
    printf("a=%d, b=%d, c=%d\n", a, b, c);  // a=0, b=0, c=6
}
/******************************************************************************************
 * @brief   Q9. Please answer the sizeof s, p & c.
 * @related #variable types
******************************************************************************************/
void arcadyanQ :: Q9(){
    char s[] = "Hellow World", *p = s, c;
    printf("sizeof(s) = %d\n", sizeof(s));  //13
    printf("sizeof(p) = %d\n", sizeof(p));  //8
    printf("sizeof(c) = %d\n", sizeof(c));  //1
}
/******************************************************************************************
 * @brief   Q10. Please write the code below:
 *          a) Set a specific bit
 *          b) Clear a specific bit
 *          c) Inverse a specific bit(0->1, 1->0)
 * @related #bitwise operation
******************************************************************************************/
void arcadyanQ :: setBit(int &x, int b){ x |= (1 << b); }
void arcadyanQ :: clrBit(int &x, int b){ x &= ~(1 << b); }
void arcadyanQ :: xorBit(int &x, int b){ x ^= (1 << b); }
void arcadyanQ :: Q10(){
    int x = 0;
    setBit(x, 1);
    printf("%d\n", x);  // 2
    clrBit(x, 1);
    printf("%d\n", x);  // 0
    xorBit(x, 1);
    printf("%d\n", x);  // 2
}

arcadyanQ :: ~arcadyanQ(){}