/*
Arrays:
there are two limitation of array container.
- size cannot be changed.
- two array of integer may have different type
    #1 : a and b is actually different type.
    if i have a function that takes array of 3 elements, it wont takes and 4 elements
    because they are different types.
*/

#include <array>
#include <iostream>
#include <algorithm>

int main()
{
    std::array<int, 3> a = {3, 4, 5};
    a.begin();
    a.end();
    a.size();
    //a.swap();

    //#1
    std::array<int, 4> b = {3, 4, 5};

    return 0;
}