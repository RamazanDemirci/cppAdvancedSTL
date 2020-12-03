#include <set>
#include <algorithm>

class Lsb_less
{
public:
    bool operator()(int x, int y)
    {
        return (x % 10) < (y % 10);
    }
};

int main()
{
    std::set<int> s = {21, 23, 26, 27};

    std::set<int>::iterator itr1, itr2;

    itr1 = std::find(s.begin(), s.end(), 36); //itr1 is pointer to s.end()

    itr2 = s.find(36); // //itr1 is pointer to s.end()

    /*
    this stiation we dont use external condition and two result is same
    */

    return 0;
}

/*
Guidelines

if the function is using operator "<" or its like, it2s checking equivalence
    - Typically it's algorithm that works with sorted data, or a member
       function of container with sorted data, such as associative container

if the function is using operator "==" or its like, it's checking equality
    - Typically tha data is not required to be sorted


Algorithms of equality:
    std::search
    std::find_end
    std::find_first_of
    std::adjacent_search

Algorithms of equivalance
    std::binary_search
    std::includes
    std::lower_bound
    std::upper_bound


Summary:
    When using a function to search or remove certain element, 
    make sure you understand the difference between equality and equivalance
*/
