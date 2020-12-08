#include <iostream>
template <typename T>
T square(T x)
{
    return x * x;
}

/*
you don't have to specifically tell the compiler the data type the data type can be 
inferred from the parameter

template has a side-effect called code bloat even though we only have one copy of the
square function code '#1' square function and '#2' square function are actually 
different square functions. in other words they occupy their own space in the final 
program image so if we use the square template function on a lot of
different data types the code size will be bloated
*/

int main()
{
    std::cout << square(5) << std::endl;   //#1
    std::cout << square(5.5) << std::endl; //#2
    return 0;
}
