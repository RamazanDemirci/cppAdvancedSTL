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

int main()
{
    // Print a message whenever an item is removed
    std::vector<int> c = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16}; //Remove 1's

    for (std::vector<int>::iterator itr = c.begin(); itr != c.end();)
    {
        if (*itr == 1)
        {
            std::cout << "Erase one item of " << *itr << std::endl; /*#2*/
            c.erase(itr++);                                         /*#1*/
        }
        else
        {
            itr++;
        }
    }

    print(c, "after erase():");

    /*
    now how about the other containers what about vectors can I use this same way to erase elements 
    from a vector let's try it and run it as you see only three elements of one are erased now 
    what happened for vector when never an element is erased all the iterators after that element are
    invalidated so whenever one is erased all the iterators that points to any one of the rest of element 
    gets invalidated so even though it is advanced to the next element successfully it is still a 
    invalidated iterator so the rest of the program still has undefined behavior and in this case 
    the undefined behavior gives you an illusion that the program is running okay which is worse than crashing 
    */

    return 0;
}
