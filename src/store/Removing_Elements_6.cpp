#include <iterator>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
#include <set>
#include <unordered_set>

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
    // Remove elements from an associative container or unordered container
    std::multiset<int> c = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16}; //Remove 1's
    //std::unordered_set<int> c = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16}; //Remove 1's
    print(c, "Original:");
    /*#1
    auto itr = std::remove(c.begin(), c.end(), 1); // Complexity: O(n)
    c.erase(itr, c.end());
    print(c, "After erase():");
    */
    //#2
    c.erase(1); //O(log(n))
    print(c, "after erase():");

    return 0;
}

/*
#1:
we look at the multi set member function and we don't see a dedicated remove function like the list does so
maybe we should go back to use the remove algorithm followed by erase function the answer is no you don't
although multiset doesn't have a dedicated remove member function it has a much better version of erase function

#2:
the multi sets the erase function can remove items by value and do it quickly.
the multi sets erase function only needs logarithmic time to do the removal instead of linear time and for 
unordered container it is even faster it only needs amortized constant time to do the erase so in both case you should use
the member function erase to do the function of removal


Summary:

1. Vector or Deque : algorithm remove func. fallowed by member func. erase()
2. List : member func. remove()
3. Assosiative Container or Unordered Container : member func. erase()
*/