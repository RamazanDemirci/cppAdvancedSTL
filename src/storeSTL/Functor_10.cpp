/*
Function Objects (Functor)

Parameter Binding
#1:

better yet if you are using C++ 11 you could use lambda function

how I use a lambda function that provide the same kind of data check so with 
lambda function I don't have to create a separate function in a different place 
everything is in one place and the code is still very readable 

lambda function works very well with the algorithms 

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

    std::transform(mySet.begin(), mySet.end(),                 //source
                   std::back_inserter(d),                      //destination
                   [](int x) { return (x > 20) || (x < 5); }); //functor

    std::for_each(d.begin(), d.end(), [](int item) { std::cout << item << " " << std::endl; });

    return 0;
}