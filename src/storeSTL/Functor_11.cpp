/*
Function Objects (Functor)

Why do wee need functor in STL?

functor has a important law in STL remember we said associative containers are 
always sorted

what criteria do they use for sorting?

#1: it is automatically sorted in ascending order
- the template class set actually can take two template parameters one is the type 
of its element and the second one is a comparison functor that's used for sorting 
and the default value for that comparison functor is less. 
- so #1 is equal #2

#3:
now suppose I want to create a set that's sorted in a different order 
- I want to sort them according to the least significant digit

I will use lsb_less instead of less 
- then I need to define else lsb_less suppose I

defined lsb_less takes two integers and it will return to when the least
significant digit of X is less than wise

how does this code look?
--this code will not compile because set requires a function type as its second 
parameter not just a function or function pointer and lsb_less is a function 

- so we need to define a functor

#4:
now this code will work 
- so now you see the importance of functor in stl without functor the 
associative container won't work.
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

//#3
bool lsb_less(int x, int y)
{
    return (x % 10) < (y % 10);
}

//#4
class Lsb_less
{
public:
    bool operator()(int x, int y)
    {
        return (x % 10) < (y % 10);
    }
};

int main()
{
    //#1
    std::set<int> mySet = {3, 1, 25, 7, 12};
    //#2    //same as
    std::set<int, std::less<int>> mySet2 = {3, 1, 25, 7, 12};
    //#3
    //std::<int, std::lsb_less>mySet3 = {3, 1, 25, 7, 12};

    //#4
    std::set<int, Lsb_less> mySet4 = {3, 1, 25, 7, 12};

    std::for_each(mySet4.begin(), mySet4.end(), [](int item) { std::cout << item << " " << std::endl; });

    return 0;
}