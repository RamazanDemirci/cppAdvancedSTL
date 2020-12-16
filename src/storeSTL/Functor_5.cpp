/*
Function Objects (Functor)

Parameter Binding

#1:
- we have a set of integer which has 2 3 4 5 
- we want multiply each element by 10 and save the result into a vector of
integer vec

- we know there's a functor multiplies that we can use

- we know there's a algorithm transform which can call the multiplies on every item 
of my set then back insert the result into vec

-but we have a problem the functor multiplies takes two parameter however transform 
needs a functor that takes only one parameter
    -- what can we do? we can use the bind function

- with the bind function the placeholder::_1  means 
    - the first parameter of multiplies will be substituted with an element from 
    mySet 
    - the second parameter is 10 
so the result is vec:{20, 30, 40, 50} 

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>
#include <iterator>

int main()
{
    std::set<int> mySet = {2, 3, 4, 5};
    std::vector<int> vec;

    int x = std::multiplies<int>()(3, 4); // x = 3 * 4

    // Multiply myset's elements by 10 and save in vec:
    std::transform(mySet.begin(), mySet.end(),                                    //source
                   std::back_inserter(vec),                                       //destination
                   std::bind(std::multiplies<int>(), std::placeholders::_1, 10)); //functor
    //First parameter of multiplies<int>() is substituted with mySet's element

    //printing results
    std::for_each(vec.begin(), vec.end(), [](int item) { std::cout << item << std::endl; });
    //std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout));

    return 0;
}