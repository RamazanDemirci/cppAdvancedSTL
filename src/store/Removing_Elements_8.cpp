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

    for (std::multiset<int>::iterator itr = c.begin(); itr != c.end();)
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
    so how can we fix this one way to fix it is we can move the incrementing of itr to over here(#1) now
    since this is a post incrementing of itr it will return the old iterator for c to erase and it is advanced 
    to the next element successfully and that the since the itr is already pointing to the next element we need to
    move printing(#2) itr value statement before the erase and when we'll go to the second run of the for loop 
    it is already pointing to the next element if it is not equal to one when you need to increment the
    itr in else statement now let's run that loop on the program now all the ones are erased successfully 
    and the program did not crash so this is how you erase elements from associative containers with handcrafted loop
    */

    return 0;
}
