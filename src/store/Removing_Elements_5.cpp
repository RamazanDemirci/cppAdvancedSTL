#include <iterator>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <list>

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
    // Remove elements from list
    std::list<int> c = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16}; //Remove 1's
    print(c, "Original:");
    /*
    //#1
    auto itr = std::remove(c.begin(), c.end(), 1); // Complexity: O(n)
    c.erase(itr, c.end());
    print(c, "After erase():");
    */

    //#2
    c.remove(1);
    print(c, "after remove():");

    return 0;
}

/*
#1 :
this also gets the job done for a list but this is not the optimal way of removing items 
list has a member function called remove and this remove function can do the job of
removing items more efficiently why is that as we mentioned the algorithm function remove 
does the job by moving the unremoved items towards the front of the vector 

#2 :
but the member function remove doesn't do that the member function remove knows the data structure of a linked list so it does
to remove by clicking the forward pointer and the backward pointers which is more efficient so now this is a
faster easier and cleaner way of removing items for a list
*/
