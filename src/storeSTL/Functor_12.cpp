/*
Function Objects (Functor)

Predicate

Predicate is used for comparison or condition check

A predicate must have satisfied two following conditions

A functor or function that:
1. Returns a boolean
2. Does not modify data

#1:
an example of predicates it returns a bool and it is passing the parameter by 
values so there's no way it can modify the original data 

- and that the transform function is using the predicate to decide whether the data 
needs to be copied or not 

- predicate is widely used in STL algorithms it's mainly used for comparison or 
condition check one thing 
- you have to keep in mind is you can't assume predicate is invoked only once per 
element during the execution of the algorithm 
- so it is recommended that a predicate is a pure function which means the return 
value is purely based on the input value and has nothing to do with how many times 
the predicate has been invoked 

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

class NeedCopy
{
public:
    bool operator()(int x)
    {
        return (x > 20) || (x < 5);
    }
};

int main()
{
    std::set<int> mySet = {3, 1, 25, 7, 12};
    std::deque<int> d;

    std::transform(mySet.begin(), mySet.end(), //Source
                   std::back_inserter(d),      //Destination
                   NeedCopy());                //Functor

    std::for_each(d.begin(), d.end(), [](int item) { std::cout << item << " " << std::endl; });

    return 0;
}