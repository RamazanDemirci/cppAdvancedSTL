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
    more efficent way is use the algorithm function remov  vector item

    but there is a problem here. if you run  this code, you will some item that value is 1 is not remove

    the reason that; algorithms function has no idea about the container they only know the data trough  the iterators
    so the algorithm function remove has no idea whether the data is not in a dynamic array or binary tree or hash table

    that is why it is impossible for the algorithms function remove to actually remove the items from the container
    */
    std::remove(c.begin(), c.end(), 1); //Complexity : O(n)
    print(c, "After erase():");
    return 0;
}
