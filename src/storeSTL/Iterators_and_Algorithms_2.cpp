/*
#1:
Every Container has a iterator and a const_iterator

- Const iterator provides a read-only access to the containers elements 

#2:
- i use 'citr' which is a constant iterator to iterate through every item in my set 
and then print it out if i try 
- to modify the element it won't compile

#3:
C++11 also provide all the containers to additional function to access the constant 
iterator cbegin() and cend() 
those two functions provide a convenient access of the 
constant iterative to the algorithm functions
in this case the algorithm function of for_each(..) will call my function on each 
element in mySet and my function can only read an elements in mySet cannot modify 
elements in mySet

#4:
STL also provides some functions for iterators one of them is advanced 
- advanced(itr, 5) move the iterator forward five items 
this is a convenient function for all other iterators 

- distance measures the distance between two iterators and again
this is a convenient function for non random access iterators
*/

#include <vector>
#include <list>
#include <forward_list>
#include <iostream>
#include <set>
#include <algorithm>

void MyFunction(int item)
{
    std::cout << item << std::endl;
}
int main()
{
    //#1
    std::set<int>::iterator itr;
    std::set<int>::const_iterator citr;

    std::set<int> mySet = {2, 4, 5, 1, 9};
    //2
    for (citr = mySet.begin(); citr != mySet.end(); ++citr)
    {
        std::cout << *citr << std::endl;
        //*citr = 3;    //Compile Error
    }
    //#3
    std::for_each(mySet.cbegin(), mySet.cend(), MyFunction); // Only in C++11

    //Iterator Functions:
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int>::iterator vitr = vec.begin();
    auto itr1 = vitr + 5;
    auto itr2 = vitr + 2;
    itr = mySet.begin();
    std::advance(itr, 3);                  // Mode itr forward 5 spots. itr += 5;
    auto dist = std::distance(itr1, itr2); // MEasure the distance between itr1 and itr2
    std::cout << "adv : " << *itr << std::endl;
    std::cout << "dist : " << dist << std::endl;

    return 0;
}