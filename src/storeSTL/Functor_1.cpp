/*
Function Objects (Functor)

-we have a class X and the we define operator parentheses for X which will take 
a string as a parameter and then it will print out the message with this string 
- in the main function I can create foo and then call foo with the string

#1:
- so here foo is actually an instance of X but we can use foo as if it is a 
function 
- this is the idea of functors 
- functor expands the concept of function by saying anything behave like a 
function is a function 
-in this example X is a class but it behaves like a function we call it a function 

note: don't mess up this syntax with the syntax of defining a type conversion 
function

#2: 
if I want to define the type conversion from X to a string?
- type conversion function you put the type after operator
- for defining a functor you have to put the type before the operator

#3:
what's the benefit of the defining functor' why don't we just use a regular 
function?
- Benefits of Functor:
    1. Smart function: capabilities beyon operator()
        - It can remember state
        - if you look at X then operator parentheses is a regular function but X 
        can provide more things beyond operator parenthes 
        - for example X can define  its own member data to remember the state of 
        the functor and because of those member data you could have two different instance of the same functor 
        that behaves different from each other
    2. It can have its own type
        - a functor can have its own type regular functions can only be 
        differentiated by their function signatures if two functions have the same 
        function signatures they are the same function however two functors can be 
        of different type even if they have the exact same function signature

*/
#include <iostream>
#include <string>

class X
{
public:
    void operator()(std::string str)
    {
        std::cout << "Calling functor X with parameter " << str << std::endl;
    }
    //#2
    operator std::string() const { return "X"; } // type conversion function
};

int main()
{
    //#1
    X foo;
    foo("Hi"); // Calling functor X with parameter 'Hi'
    return 0;
}