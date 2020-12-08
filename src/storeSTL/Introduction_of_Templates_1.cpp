#include <iostream>

int square(int x)
{
    return x * x;
}

double square(double x)
{
    return x * x;
}

/*
as you can see I have to make a duplicate of the square function for each one of the
data type this makes our code look ugly

we don't want that and this is why we need a template
*/

int main()
{
    std::cout << square(5) << std::endl;
    std::cout << square(5.5) << std::endl;
    return 0;
}
