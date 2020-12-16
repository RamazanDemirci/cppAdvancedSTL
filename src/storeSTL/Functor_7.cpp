/*
Function Objects (Functor)

Parameter Binding
#1:
you can also convert a regular function into a functor

- I define a regular function of Pow which raises X to the power of Y

- I want to raise every element of mySet to the power of 2
- save that into the deque of integer d
- I'll use the template class function to convert the regular function Pow into a 
functor f
- I use the transform algorithm
    - the bind function to raise every item of my set to the power of 2
    - back_insert into d

note: the function class temperate is only in C++11e 
    - for the old simplest class you have to use 
        -- C++ 03 uses ptr_fun
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

double Pow(double x, double y)
{
    return std::pow(x, y);
}

int main()
{
    std::set<int> mySet = {3, 1, 25, 7, 12};
    std::deque<int> d;

    auto f = std::function<double(double, double)>(Pow); // C++11

    std::transform(mySet.begin(), mySet.end(),              //source
                   std::back_inserter(d),                   //destination
                   std::bind(f, std::placeholders::_1, 2)); //functor

    std::for_each(d.begin(), d.end(), [](int item) { std::cout << item << " " << std::endl; });

    return 0;
}