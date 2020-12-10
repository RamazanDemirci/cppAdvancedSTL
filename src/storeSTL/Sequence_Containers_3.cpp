/*
Deque:

Deque and vector have very similar interfaces.(#1)
the big difference bettween two is, 
    - vector can grow only at the end of the vector
    - deque can grow both at the end and at the begining.
- deque doesn't provide contiguous data
- deque also provide random access just like vector

Properties:
    1. fast insert/remove at the begining and the end.
    2. slow insert/remove in the middle.
    3. slow search: O(n)
*/

#include <deque>
#include <iostream>

int main()
{
    std::deque<int> deq = {4, 6, 7};
    deq.push_front(2); //deq: {2,4,6,7}
    deq.push_back(3);  //deq: {2,4,6,7,3}

    //#1
    std::cout << deq[1]; //4
}