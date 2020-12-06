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
    std::multiset<int> c = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16}; //Remove 1's

    for (std::multiset<int>::iterator itr = c.begin(); itr != c.end(); itr++)
    {
        if (*itr == 1)
        {
            c.erase(itr);
            std::cout << "Erase one item of " << *itr << std::endl;
        }
    }

    /*
    it prints out erased one item of one and then the program crashed so the first element of one is erased and then the
    program crashed or happened in the first loop of the for loop itr is equal to c.begin() which is the element of one
    since this element is equal to 1 it is erased successfully and then something bad happened after the code of c.begin()
    erase itr is finished the element that itr was pointing to is erased and every time an element is erased the
    iterator that was pointing to that element is invalidated so itr is invalidated it is no longer a valid
    iterator anymore and this is true for all containers iterators of erased elements are always invalidated so when
    we go to the second run of the for loop and check if it equal to c.end() the result is undefined behavior and in this
    case the undefined behavior is the program crashed!
    */

    return 0;
}
