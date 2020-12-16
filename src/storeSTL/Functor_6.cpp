/*
Function Objects (Functor)

Parameter Binding
#1:
with the bind function we have another solution for the add2() problem that we 
talked about in the previous 

- we define addVal function that required two integer parameters, 

- use bind function to bind the addVal() function with a second parameter of 2 or 
any other number that you want to use

-- bind() function is only available in C++ 11
-- if you are using the old C++ you can use the equivalent function 
    - c++ 03 : bind1st, bind2nd



*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>
#include <iterator>

void addVal(int i, int val)
{
    std::cout << i + val << std::endl;
}

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

    std::for_each(vec.begin(), vec.end(), std::bind(addVal, std::placeholders::_1, 2));

    return 0;
}