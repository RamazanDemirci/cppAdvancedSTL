#include <iostream>
template <typename T>
T square(T x)
{
    return x * x;
}

/*
when I call square function i tell the compiler that this is the square function of 
data type integer(#1), and double(#2)
*/

int main()
{
    std::cout << square<int>(5) << std::endl;      //#1
    std::cout << square<double>(5.5) << std::endl; //#2
    return 0;
}
