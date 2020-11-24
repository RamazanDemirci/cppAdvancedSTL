#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
#include <list>

int main()
{
    std::cout << "Hello Easy C++ project!" << std::endl;

    std::unordered_set<int> s = {2, 4, 1, 8, 5, 9}; //Hash table
    std::unordered_set<int>::iterator itr;

    //Using member function
    itr = s.find(4); //O(1)

    //Using Algorithm
    itr = std::find(s.begin(), s.end(), 4); //O(n)

    //How about map/multimap?
    std::map<char, std::string> mymap = {{'S', "Sunday"}, {'M', "Monday"}, {'W', "Wednesday"}, ..};

    std::map<char, std::string>::iterator itr2;

    //Using member function
    itr2 = mymap.find('F'); //O(log(n))

    //Using Algorithm
    itr2 = find(mymap.begin(), mymap.end(), std::make_pair('F', "Friday")); //O(n)

    //How about list?
    std::list<int> l = {2, 4, 1, 8, 5, 9};

    //Using member function
    l.remove(4); //O(n) //remove item by pointers
    //>l : {2,1,8,5,9}

    //Using Algorithm
    std::remove(l.begin(), l.end(), 4); //O(n)  //remove item by copy
    //>l : {2,1,8,5,9,9}
    //remove alg. note erase the item just remove by copied.
    //mst do fallowing
    std::list<int>::iterator itr3 = std::remove(l.begin(), l.end(), 4);
    l.erase(itr3, l.end());

    //Sort
    //Member function
    l.sort();

    //Algorithm
    std::sort(l.begin(), l.end());
}

/*
Summary
    - There are duplicated functions between container's member functions and algorithm functions.
    - Prefer member functions over algorithm fucntions with the same names.
*/