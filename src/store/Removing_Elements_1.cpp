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
    this is the very inefficent way of removing item of the vector
    */

    for (std::vector<int>::iterator itr = c.begin(); itr != c.end();)
    {
        if (*itr == 1)
        {
            itr = c.erase(itr);
        }
        else
        {
            itr++;
        }
    } //Complexity: O(n*m)

    print(c, "After erase():");
    return 0;
}
