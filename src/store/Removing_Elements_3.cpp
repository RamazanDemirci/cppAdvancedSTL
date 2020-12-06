#include <iterator>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

//Print contents or container
template <class T>
void print(T t, std::string msg)
{
    std::cout << msg << " { ";
    for (typename T::iterator it = t.begin(); it != t.end(); it++)
    {
        std::cout << *it << ", ";
    }
    std::cout << "}" << std::endl;
}

int main()
{
    std::vector<int> c = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16}; //Remove 1's
    print(c, "Original:");

    /*
    so this function you move will do what it can do which is move all the unremoved items to the front of the 
    vector and then return the iterator which points to the new logical end of the new vector 

    so to complete the task of removal we need a pointer is iterator to save the new end and then call the
    member function of the vector arrays to actually remove the item 

    we have removed all the ones in vector C and when we look capacity of C the capacity of C is still 10

    we have reduced the size of C from 10 to 5 and the C is still occupying as much memory as it does before 
    */
    auto itr = std::remove(c.begin(), c.end(), 1); //Complexity : O(n)
    c.erase(itr, c.end());
    print(c, "After erase():");
    std::cout << "capacity():" << c.capacity() << std::endl;
    return 0;
}
