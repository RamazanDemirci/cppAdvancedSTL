/*
Function Objects (Functor)

Parameterized Function

#1:
- we have a function at 2 that takes a integer parameter and what it does is add 2 
to that integer and print it out
- in the main function I create a vector 
- I call the algorithm function of for each function add2() will be invoked with 
each element of vec 

-- this is not a pretty-looking code because we are hard coding a number into a 
function name
--this is not extendable so how can we make the code more flexible 

#2:
- one obvious solution is we could define a global variable
- well instead so by changing the value of Val we can add any number for this 
function 
-- however using global variables is another nasty coding practice and we don't 
want to go there

#3:
- what other solution do we have we must be able to do better than this 
- one solution is we could use template so we define a template of addVal() which
still take an integer 
#3.1
-- now it's more flexible I can change this value to any value that I like
#3.2
-- however there is still a problem a temporary variable is resolved at compile 
time 
    - so it has to be a compile-time constant 
    - so if I have a integer X equal to 2 I cannot use X for Addval() this won't 
    compile then 

#4:
we have the best solution is using functor
- I define a functor of AddValue and val is a private data member of AddValue
- i create a ctor of AddValue which will initialize there with j 
- in the main function I can do it like this record AddValue(y)
-- so this is the most flexible solution it uses a parameterised function or a 
functor 
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//#2
//int val = 2;

//#1
void add2(int i)
{
    //#1
    //std::cout << i + 2 << std::endl;
    //#2
    //std::cout << i + val << std::endl;
}

//#3:
template <int val>
void addVal(int i)
{
    std::cout << val + i << std::endl;
}

//#4
class AddValue
{
    int val;

public:
    AddValue(int j) : val(j) {}
    void operator()(int i)
    {
        std::cout << i + val << std::endl;
    }
};

int main()
{
    std::vector<int> vec = {2, 3, 4, 5};
    //#1,#2
    //std::for_each(vec.begin(), vec.end(), add2); //{4,5,6,7}

    //#3, #3.1
    //std::for_each(vec.begin(), vec.end(), addVal<2>); //{4,5,6,7}
    //#3.2
    //int x = 2;
    //std::for_each(vec.begin(), vec.end(), addVal<x>); //{4,5,6,7}

    //#4
    int y = 2;
    std::for_each(vec.begin(), vec.end(), AddValue(2)); //{4,5,6,7}
    return 0;
}