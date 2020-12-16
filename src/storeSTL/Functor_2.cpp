/*
Function Objects (Functor)

Parameterized Function

- functor also introduces the concept of parameterize the function 
#1:
- for the example of class X if I define a ctor of X that takes a integer parameter 
then in the main function I can do (#1) so this looks like a function that is
parameterised with 8 and then invoked with a regular parameter of 'hi'

#3:
why do we want something like this why don't we create a function that takes two 
parameter one is a integer and another one is a string ?


*/
#include <iostream>
#include <string>

class X
{
public:
    X(int i) {}
    void operator()(std::string str)
    {
        std::cout << "Calling functor X with parameter " << str << std::endl;
    }
};

int main()
{
    //X(8)("Hi");
    return 0;
}