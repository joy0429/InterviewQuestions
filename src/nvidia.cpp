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

/******************************************************************************************
 * @brief   Q. Implement malloc and free (with memory alignment)
 * @details A. We can implement malloc by linked list concept
 *             1. Create a memoryPool to assume the max of valid space.
 *             2. freeList recording each space that has be malloc by struct Block. Block 
 *                includes size(the size of this malloc), free(represent if this memory can
 *                be malloc), and next(record the pointer of previous malloc)
 *             3. When malloc a new space, we have to check if there is a valid space can be
 *                malloc. If yes, create & update record; otherwise return NULL pointer.
 *             4. When free the space, the free tag of this record change to valid, and move
 *                the remaing space together to prevent from fragmentation.
 *          Time Complexity:    O(n), n: num of record
 *          Space Complexity:   O(n)
 * @related #memory
******************************************************************************************/
memoryCtrl:: memoryCtrl(){
    this -> freeList -> size = sizeof(memoryPool);
    this -> freeList -> free = true;
    this -> freeList -> next = nullptr;
}

void* memoryCtrl :: myMalloc(size_t size){
    // Find a free block that can accommodate the requested size.
    record *prev = NULL,
           *current = this -> freeList;
    while(current){
        if ((current -> free) && (current -> size >= size)) {
            // Split the block if it's larger than needed
            // If not, it represents the remaining space is equal to the size we need
            if (current -> size > (size + sizeof(record))) {
                record* newBlock = reinterpret_cast<record*>(reinterpret_cast<char*>(current) + size + sizeof(record));
                newBlock -> size = current -> size - size - sizeof(record);
                newBlock -> free = true;
                newBlock -> next = current -> next;
                current -> size = size;
                current -> next = newBlock;
            }            
            current->free = false;
            return reinterpret_cast<void*>(current + 1);
        }
        prev = current;
        current = current -> next;
    }
    return NULL;
}

void memoryCtrl :: myFree(void *ptr){
    if (!ptr) return;

    // Mark the block as free.
    record* block = reinterpret_cast<record*>(ptr) - 1;
    block -> free = true;

    // Merge adjacent free blocks to avoid fragmentation.
    record* current = freeList;
    while (current) {
        if (current -> free && current -> next && current -> next -> free) {
            current -> size += current -> next -> size + sizeof(record);
            current -> next = current -> next -> next;
        }
        current = current -> next;
    }
}

void nvidiaQ :: memAlignMallocFree(){
    memoryCtrl memCtrl;
    int size = 0,
        *intArray;
    
    cout << "Input size: ";
    cin >> size;

    try{
        intArray = static_cast<int*>(memCtrl.myMalloc(size * sizeof(int)));
        if(!intArray) throw "No valid space can malloc.";
    } catch(const char *msg){
        cerr << msg << endl;
        exit(EXIT_FAILURE);
    }

    cout << "intArray[";
    for (int i = 0; i < size; ++i){
        intArray[i] = i;
        cout << intArray[i] << ",";
    }
    cout << "]" << endl;

    memCtrl.myFree(intArray);
}

memoryCtrl:: ~memoryCtrl(){

}

/******************************************************************************************
 * @brief   Q. Memcpy implementation
 * @details A. Using 2 pointers of char array to copy string from source to destinate. When
 *             copying char, we have to check the copy direction due to the case of over-
 *             lapping memory.
 * @note    Q. Why don't we copy source to a non-overlapping space directly?
 *          A. 1. Increase complexity
 *                It would increase the design complexity of memcpy to avoid overlapping.
 *             2. Lower performance
 *                In many cases, the memory of source & destinate wouldn't overlap. If we 
 *                implement an avoid overlapping function in memcpy, it would waste time.
 *             3. Consistency
 *                Programmer don't need to consider the special case, and it is easily
 *                maintain & understad the code.
 *             4. Tolerance
 *                It doesn't need other checking function when handling the case that 
 *                memory are overlapped such as calculating of graphic, etc.
 * @example case 1(copy from begin)     case 2(copy from last)
 *          addr. 0, 1, 2, 3            addr. 0  1  2  3  4
 *          src  [a, b, c, d]           src  [a, b, c, d]
 *          dest    [b, c]              dest    [b, c]
 *                    |                            |
 *                    V                            V
 *          dest [a, b, c, d]           dest    [a, b, c, d]
 * 
 *          Time Complexity:    O(n), n: length of string
 *          Space Complexity:   O(n)
 * @related #memory
******************************************************************************************/
void myMemCpy(void* dest, const void* src, size_t count) {
    char* destChar = static_cast<char*>(dest);
    const char* srcChar = static_cast<const char*>(src);

    if (destChar < srcChar) {
        for (size_t i = 0; i < count; i++) {
            destChar[i] = srcChar[i];
        }
    } else if (destChar > srcChar) {
        for (size_t i = count - 1; i >= 0; i--) {
            destChar[i] = srcChar[i];
        }
    }
}

void nvidiaQ :: memCpy() {
    char source[1024], copy[1024];

    cout << "String: ";
    cin >> source;
    myMemCpy(copy, source, 1024);
    cout << "Copied: " << copy << endl;
}

/******************************************************************************************
 * @brief   Q. Check if the binary tree is valid
 * @details A. Using DFS to check the value of (sub)tree's root is bigger then the left
 *             subtree & smaller than the right subtree
 *          Time Complexity:    O(logn), n: num of nodes
 *          Space Complexity:   O(n)
 * @ref     Leetcode 98. Validate Binary Search Tree
 * @related #binary tree #DFS
*****************************************************************************************/
bool nvidiaQ :: isValidBST(tree *root, tree *min, tree *max){
    if(!root) return true;
    if((min && (root -> val <= min -> val)) || (max && (root -> val >= max -> val))) return false;
    return isValidBST(root -> left, min, root) && isValidBST(root -> right, root, max);
}

void nvidiaQ :: checkValidBT(){
    // case 1
    tree *root1 = new tree(2);
    root1 -> left = new tree(1);
    root1 -> right = new tree(3);
    cout << "case 1: " << (isValidBST(root1, NULL, NULL)? "pass" : "fail") << endl;

    // case 2
    tree *root2 = new tree(5);
    root2 -> left = new tree(1);
    root2 -> right = new tree(4);
    root2 -> right -> left = new tree(3);
    root2 -> right -> right = new tree(6);

    cout << "case 2: " << (isValidBST(root2, NULL, NULL)? "pass"  : "fail") << endl;
}
/******************************************************************************************
 * @brief   Q. Reverse part of linked list by input numbers
 * @details A. Find the node "prev" before the swap part. Then swap each node "now" with
 *             its next node "next" in order(remember link "now" back to the node after swap
 *             part, and link "next" back to "prev")
 *          Time Complexity:    O(n), n: length of linked list should be reversed
 *          Space Complexity:   O(1)
 * @ref     Leetcode 206. Reverse Linked List(similar)
 * @related #linked list #2 pointers
******************************************************************************************/
linkedList* nvidiaQ :: reverseList(linkedList *head, int start, int end){
    if(!head || start == end) return NULL;

    // Create a dummy node to prevent from reverse from head
    linkedList *dummy = new linkedList(INT_MAX);
    dummy -> next = head;

    // Find & record the head before reversed part
    linkedList *prev = dummy;
    for(int i = 1; i < start; i++) prev = prev -> next;

    // Swap value by now & next, and link prev to the next
    linkedList *now = prev -> next, *next;
    for(int i = start; i < end; i++){
        next = now -> next;
        now -> next = next -> next;
        next -> next = prev -> next;
        prev -> next = next;
    }
    return dummy -> next;
}

void nvidiaQ :: reverseListResult(){
    linkedList *head = new linkedList(1);
    head -> next = new linkedList(2);
    head -> next -> next = new linkedList(3);
    head -> next -> next -> next = new linkedList(4);
    head -> next -> next -> next -> next = new linkedList(5);

    cout << "Orig. linked list: [1->2->3->4->5]" << endl;
    cout << "Reverse loc: 2~4" << endl;

    linkedList *newHead = reverseList(head, 2, 4);

    cout << "After reverse: [";
    while(newHead){
        cout << newHead -> val << "->";
        newHead = newHead -> next;
    }
    cout << "]" << endl;
}

/******************************************************************************************
 * @brief   Q. There are some tasks, each of which is of different types and takes up some 
 *          memory spaces. Assume each tasks only takes 1 sec. The OS can only run "2" same
 *          type of tasks at the same time, and it only has 10 MB spaces. Return the shortest
 *          time that all the tasks can be finished.
 * @details Using map to record task detail in each types. And task detail record the usage
 *          of memory of each tasks. Then checking each type and finding the tasks by two 
 *          pointers that can be run at the same time.
 * @related #2 pointers #unordered map
******************************************************************************************/
int nvidiaQ :: shortestTime(vector<int> &tasks, vector<int> &types){
    int times = 0;
    unordered_map<int, vector<int>> map;

    for(int idx = 0; idx < tasks.size(); idx++) map[types[idx]].push_back(tasks[idx]);

    for(auto type : map)
    {
        int start = 0, end = type.second.size() - 1;
        sort(type.second.begin(), type.second.end());

        while(start < end){
            int sum = type.second[start] + type.second[end];
            if(sum > 10) end--;
            else if(sum < 10) start++;
            else start++, end--;
            times++;
        }
        if(start <= end) times++;
    }
    return times;
}

void nvidiaQ :: parallelProcess(){
    vector<int> tasks = {7, 2, 3, 9},
                types = {1, 2, 1, 3};
    cout << "Shortest Time(sec.): " << shortestTime(tasks, types) << endl;
}

nvidiaQ :: ~nvidiaQ(){
    
}