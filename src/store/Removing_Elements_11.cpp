#include <iterator>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
#include <set>
#include <unordered_set>

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

bool equalOne(int e)
{
    if (e == 1)
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

    auto itr = std::remove_if(c.begin(), c.end(), equalOne);
    c.erase(itr, c.end());

    print(c, "after erase():");

    /*
    now I have to confess that I have been misleading you to handcraft your own group of course
    you don't have to handcraft your own
    
    loop you can always use the algorithm now let me show you the library solution

    I call the algorithm function will move if remove_if() setup begins at the end equal_one() 
    and followed by the member function c.erased() to do the actual work of erasion 
    
    this also removed all the ones from the container so we can accomplish the same thing without
    worrying about all the pitfalls of handcrafting a loop of erasion 
    */

    return 0;
}
