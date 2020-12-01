#include <iterator>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
    /*
    iterator can be convertible to reverse iterator
    */

    std::vector<int>::iterator itr;
    std::vector<int>::reverse_iterator ritr;

    ritr = std::vector<int>::reverse_iterator(itr);

    //itr = std::vector<int>::iterator(ritr); //compile error
    itr = ritr.base();

    //C++ Standard : base() returns current iterator

    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int>::reverse_iterator ritr2 = std::find(vec.rbegin(), vec.rend(), 3); // ritr pointing to 3

    std::cout << (*ritr2) << std::endl; // 3

    std::vector<int>::iterator itr2 = ritr2.base();

    std::cout << (*itr2) << std::endl; //4

    /*
                |                |     |     |     |                  |    
    'vec.rend()'|  1'vec.begin()'|  2  |  3  |  4  |  5 'vec.rbegin()'|   'vec.end()'
                |                |     |     |     |                  |
    vec.begin() : head of vector
    vec.end()   : next the last
    vec.rbegin(): tail of the vector
    vec.rend()  : prev. the begin.

    desc :
    ritr2 is pointing to 3(n)
    itr2 = ritr2.base() is pointing to 4(n+1)

    * current iterator of 'vec.rend()' is 'vec.begin()'
    * current iterator of 'vec.rbegin()' is 'vec.end()'
    */

    return 0;
}
