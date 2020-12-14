/*
Iterators 

there are five categories of iterators 
#1. Random Access Iterator: vector, deque, array
- I can access the elements in a container randomly 
- I can also compare two iterators
- I can increment the include iterator 
- I can decrement the iterator 

note:  the pre increment is usually faster than post increment because the pre 
increment doesn't have to return the old value which is typically stored in the 
temporary variable 

#2. Bidirectional Iterator: list, set/multiset, map/multimap
- I can increment it I can decrement it but
- I cannot add or subtract a value to it 
- I cannot compare two iterators 

#3. Forward Iterator: forward_list
- forward iterator can only be incremented 
- it cannot be decremented 

unordered containers provide at least forward iterators but they have the option to 
provide a bi-directional iterator it depends on the implementation of the STL 

#4. Input Iterator: read and process values while iterating forward
- you can read from a dereference to input the iterator but you cannot write to it
#5. Output Iterator: output values while iterating forward
- you can write into a dereference the output in iterator but you cannot read fro

both input(#4) iterator and output(#5) iterator can only move forward it cannot move 
backward
*/

#include <vector>
#include <list>
#include <forward_list>
#include <iostream>

int main()
{
    //#1
    std::vector<int>::iterator itr;
    itr = itr + 5; // advance itr by 5
    itr = itr - 4;
    std::vector<int>::iterator itr1;
    std::vector<int>::iterator itr2;
    if (itr2 > itr1)
        std::cout << "itr2 gt itr1" << std::endl;

    //#2
    std::list<int>::iterator itr;
    ++itr; //faster than itr++
    --itr;

    //#3
    std::forward_list<int>::iterator itr;
    ++itr;

    //#4
    int x = *itr;

    //#5
    *itr = 100;

    return 0;
}