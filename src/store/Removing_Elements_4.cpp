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
    #1:
    if that piece of memory is important to you and you want to release them back to the system there is one extra step to do

    you can call the function shrink to fit which will release the unused memory back to the system

    #2:
    if you are using Old C++ you can use the swap and this should also do the job of shrinking the memory
    */
    auto itr = std::remove(c.begin(), c.end(), 1); //Complexity : O(n)
    c.erase(itr, c.end());
    c.shrink_to_fit(); // C++ 11        /*#1*/
    //std::vector<int>(c).swap(c);      /*#2*/
    print(c, "After erase():");
    std::cout << "capacity():" << c.capacity() << std::endl;

    return 0;
}
