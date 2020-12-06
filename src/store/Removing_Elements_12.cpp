#include <iterator>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
#include <set>
#include <unordered_set>
#include <functional>

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

bool equalOne(int e, int p) /*#1*/
{
    if (e == p)
    {
        std::cout << e << " will be removed" << std::endl;
        return true;
    }
    return false;
}

int main()
{
    // Print a message whenever an item is removed
    std::vector<int> c = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16}; //Remove 1's

    auto itr = std::remove_if(c.begin(), c.end(), std::bind(equalOne, std::placeholders::_1, 12)); /*#2*/
    c.erase(itr, c.end());

    print(c, "after erase():");

    /*
    now you may say this is not flexible what if I want to erase 12 do I need to create
    another function to check if e equal to 12 that is a good point we can make our solution better 
    
    (#1)we can add add another integer parameter 
    (#2)in the remove function we can use bind function to bind the second parameter to any number
    */

    return 0;
}
