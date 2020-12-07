#include <vector>
#include <iostream>
/*
vector and the deque have very similar interfaces, big difference on the interface is a vector
can easily grow on one end and that deque can easily grow on both ends 

because of their similarity people often have difficulty deciding which one to use 

despite the similar interfaces vector and the deque are actually very different data structures 
and because of that difference often time you prefer using one over the other 
*/
int main()
{
    std::vector<int> vec = {2, 3, 4, 5}; //#1

    vec.push_back(6); //#2

    std::cout << "vec's size    :" << vec.size() << std::endl;
    std::cout << "vec's capacity:" << vec.capacity() << std::endl;

    /*
    #1:
    result:
    vec's size    :4
    vec's capacity:4
    as you see, initialized data size define the capacity value
    what if i want to insert a new item in the vector?

    #2:
    result:
    vec's size    :5
    vec's capacity:8

    how did this happen?


    in the first case capacity are 4 so all the spaces are fully occupied.
    after i push back another item but the vector is 4 there's no room to insert another item 
    or can the vector do it creates a new array which has twice the capacity of the original one and
    then copy all the data to the new array now it can easily insert the new item into the new array so now the vector
    size is 5 and in fact capacity is 8 
    vectors capacity grows exponentially it grows by certain ratio in this case this ratio is 2 but it doesn't 
    have to be to some implementation use 1.5 as the ratio
    the vector has a new array which contains all the data remember the new array is a different array from 
    the oldarray so what will happen to the old array the old array will be simply deleted and its space will be 
    released back to the system so this is how a vector grows and involved this process of reallocation 

    -> check capacity is full
        -> if yes allocate twice capacity of array
        -> copy all data from old array to new array
        -> delete old array and give the memory to the system
    -> push back new item

#Drawbacks
    * expensive reallocation
        the expensive reallocation every time a reallocation happens the original data will be copied to a new 
        location and other originals will be destroyed that is a lot of construction and destruction

    *requires contiguous memory
        the second delay a vector requires contiguous memory imagine I already have ten thousands of data 
        in the vector and when the reallocation happens I need to allocate 20,000 data of contiguous memory that 
        could become a big problem especially when the memory is already heavily fragmented so this makes a vector 
        exception prone when the vector size is big 
    */

    return 0;
}
