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
            itr = c.erase(itr);                                     /*#1*/
        }
        else
        {
            itr++;
        }
    }

    print(c, "after erase():");

    /*
    the correct way to do it is this get 'itr = c.erase(itr)' because the vectors erase function
    always return a valid iterator that points to the next element after that you erase the element 

    now all that ones are erased and the program did not crash so this is the correct way to erase 
    elements from sequence container and unordered container 

    as a summary:
    Sequence containerand unordered container: itr=c.erase(itr);
        
        for sequence container an unloaded container you use the return value from the erase function
        as the next element 

    Associative container : c.erase(itr++);
        for associative container you use post incrementing to advance to the next element you can't
        use the returned value because associative containers of utilize function returns nothing 
    */

    return 0;
}
