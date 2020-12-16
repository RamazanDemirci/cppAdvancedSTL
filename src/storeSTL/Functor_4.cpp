/*
Function Objects (Functor)

Build-in Functors
less, greater, greater_equal, less_equal, not_equal_to, logical_and, logical_not,
logical_or, multiplies, minus, plus, divide, modulus, negate

- there's beauty in functors are convenient functions for the algorithm functions 
that we could use like the previous example

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int x = std::multiplies<int>()(3, 4); // x = 3 * 4

    if (std::not_equal_to<int>()(x, 10)) // if(x != 10)
        std::cout << x << " is not equal to 10" << std::endl;

    if (std::less<int>()(x, 10)) // if(x < 10)
        std::cout << x << " is less than 10" << std::endl;

    if (std::greater<int>()(x, 10)) // if(x > 10)
        std::cout << x << " is greater than 10" << std::endl;

    if (std::greater_equal<int>()(x, 10)) // if (x >= 10)
        std::cout << x << " is greater equal 10" << std::endl;

    return 0;
}