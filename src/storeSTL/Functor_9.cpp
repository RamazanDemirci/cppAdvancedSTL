/*
Function Objects (Functor)

Parameter Binding
#1:

we create a needCopy() that takes an integer and returns a boolean saying whether 
the integer need to be copied or not
- then in the transform function I can use the needCopy function 

so it is much clearer this way

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>
#include <iterator>
#include <math.h>
#include <deque>

bool needCopy(int x)
{
    return (x > 20) || (x < 5);
}

int main()
{
    std::set<int> mySet = {3, 1, 25, 7, 12};
    std::deque<int> d;

    std::transform(mySet.begin(), mySet.end(), //source
                   std::back_inserter(d),      //destination
                   needCopy);                  //functor

    std::for_each(d.begin(), d.end(), [](int item) { std::cout << item << " " << std::endl; });

    return 0;
}