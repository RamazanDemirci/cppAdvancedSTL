#include <vector>
#include <iostream>

int main()
{
    // common member functions of all containers.
    std::vector<int> vec;
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8);

    //vec: {4, 1, 8}
    if (vec.empty())
    {
        std::cout << vec.size(); //3
    }
    std::vector<int> vec2(vec); //Copy Ctor, vec2: {4, 1, 8}
    vec.clear();                //Remove all items in vec; vec.size() == 0
    vec2.swap(vec);             //vec2 becomes empty, and vec has 3 items.

    /*
    Since the containers have common api you may expected there are some 
    inheritance and polimorphism ivolved which you beleive some performance 
    penalty of abstraction actually not, stl is very effcienct

    Notes: No penalty of abstraction, very efficient.

    Properties of Vector:
    1. fast insert/remove at the end: O(1)
    2. slow insert/remove at begining or in the middle: O(n)
    3. slow search: O(n)
    */
}