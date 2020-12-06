#include <iterator>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
#include <set>
#include <unordered_set>
#include <functional>

//Print contents or container
template <class T>
void print(T t, std::string msg)
{
    std::cout << msg << " { ";
    for (typename T::iterator it = t.begin(); it != t.end(); it++)
    {
        std::cout << *it << ", ";
    }
    std::cout << "}" << std::endl;
}

int main()
{
    // Print a message whenever an item is removed
    std::vector<int> c = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16}; //Remove 1's

    //Lambda function:
    auto itr = std::remove_if(c.begin(), c.end(),
                              [](int e) {
                                  if (e == 12)
                                  {
                                      std::cout << e << " will be removed" << std::endl;
                                      return true;
                                  }
                                  else
                                  {
                                      return false;
                                  }
                              });
    c.erase(itr, c.end());

    print(c, "after erase():");

    /*
    some people may say this is still not as flexible as I wanted it to be because if I want to print out 
    different message I still need to create different function
    
    for that alright we can make it even better and we could use a lambda function to do the job with lambda
    function it is almost as flexible as handcrafting a loop and also with lambda function or the 
    code are located in the same place not like locating in another function

    I'll put some plus lambda function is a very powerful combination as well as you get 
    used to the syntax of a lambda function
    */

    return 0;
}
