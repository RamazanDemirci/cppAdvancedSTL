#include <iterator>
#include <vector>
#include <string>
#include <iostream>

int main()
{
    /* Two ways to declare a reverse iterator
    std::reverse_iterator<std::vector<int>>::iterator ritr;
    std::vector<int>::reverse_iterator ritr;
    */

    // Traversing with reverse iterator
    std::vector<int> vec = {4, 5, 6, 7};
    std::reverse_iterator<std::vector<int>::iterator> ritr;
    for (ritr = vec.rbegin(); ritr != vec.rend(); ritr++)
        std::cout << *ritr << std::endl; //prints: 7 6 5 4

    return 0;
}
