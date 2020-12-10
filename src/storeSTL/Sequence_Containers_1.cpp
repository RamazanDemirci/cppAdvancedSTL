/*
- Sequence containers(array and linked list)
	- vector, deque, list, forward list, array
- Associative Containers(binary tree)
	- set, multiset
	- map, multimap
	
	- all the elements are always sorted.
- Unordered Containers(hash table)
	- unordered set/multiset
	- unordered map/multimap
	
- STL Headers
	- #include <vector>
	- #include <deque>
	- #include <list>
	- #include <set>	//set and multiset
	- #include <map>	//map and multimap
	- #include <unordered_set>//unordered set/multiset
	- #include <unordered_map>//unordered map/multimap
	- #include <iterator>
	- #include <algorithm>
	- #include <numeric> //some numeric algorithms
	- #include <functional>
	
- vector:
	- vector is a dynamic array that grows in one directions
    - vectors elements can be randomly access
    #1: beacuse of the random accessness i can traverse a vector just like traversing 
    a native c++ array
    #2: can be traverse a vector through the iterator
    - this way of traversing is usually fast than using random access(#1)
    - this is a universal way of traversing a container.
    #3:C++11 provides new way of traversing a container

    -vector is a dynamically allocated contiguous array in memory
        - none of other container provides contiguous data in memory
        #4: creating a pointer that poinr to first element of the vector,
            i can use it like using regular array
*/

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> vec; // vec.size() == 0
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8); // vec: {4,1,8}; vec.size() == 3

    //vector specific operations
    std::cout << vec[2];    //8 (no range check)
    std::cout << vec.at(2); //8 (throw range_error exception when index of out of range)
    //#1
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    //#2
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
        std::cout << *itr << " ";
    //#3
    for (auto it : vec) //C++ 11
        std::cout << it << " ";

    //#4
    int *p = &vec[0];

    p[2] = 6;
}