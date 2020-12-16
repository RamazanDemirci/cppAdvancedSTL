/*
Function Objects (Functor)

Parameter Binding
#1:
build-in functors and the bind function I can do something fancy 

say I want to copy everything from mySet that satisfy this 
condition(when (x > 20) || (x < 5) ) to a deck of integer d
- again I want to use the transform function 

now the problem is there is no built-in functors that do this kind of check 

- I don't want to create another function that specifically for this purpose then 
one way I can do it is

#1:
-I can construct a functor from the built-in functors
- I use the bind function
- I use the building functors of logic or greater and less 

-- how do you like it you probably don't like it because this code is not very 
readable it will probably take a while for you to figure out what this monster 
is doing so for problem like this it is probably better for you to create another 
function
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

int main()
{
    std::set<int> mySet = {3, 1, 25, 7, 12};
    std::deque<int> d;

    std::transform(mySet.begin(), mySet.end(), //source
                   std::back_inserter(d),      //destination
                   std::bind(std::logical_or<bool>(),
                             std::bind(std::greater<int>(), std::placeholders::_1, 20),
                             std::bind(std::less<int>(), std::placeholders::_1, 5))); //functor

    std::for_each(d.begin(), d.end(), [](int item) { std::cout << item << " " << std::endl; });

    return 0;
}