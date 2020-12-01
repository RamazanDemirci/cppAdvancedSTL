#include <iterator>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main()
{

    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int>::reverse_iterator ritr = std::find(vec.rbegin(), vec.rend(), 3); // ritr pointing to 3

    //Inserting
    //vec.insert(ritr, 9);        // vec : { 1,2,3,9,4,5} //compile error
    vec.insert(ritr.base(), 9); // vec : {1,2,3,9,4,5}

    //Erasing
    //vec.erase(ritr);        // vec: {1,2,4,5} //compile error
    vec.erase(ritr.base()); // vec: {1,2,4,5}

    return 0;
}
