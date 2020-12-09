/*
using namespace std everything inside STL library is defined inside the namespace 'std' 

vector is a dynamic array that can grow it is dynamically allocated on the heap and the 
size of it is not fixed vector has a member function called push back which append an 
element to the end of the array 

so the sequence of the element in the in the vector is defined by the sequence they are 
pushed back 

as we said each container is required to provide a iterate interface so vector has a member 
function called begin() another member function called end() 
    the begin() will return the iterator that points to the first element of the vector
    the end() will return the iterator that points to the end of the vector and with the iterators

I can use a for loop to iterate through each element inside of the container for vector int 
iterator so the iterator is a type that's defined inside the vector

an iterator is just like a pointer you can assign one to another you can compare them you can 
increment a iterator and you can dereference an iterator so even though iterator is a class 
it behaves just like a regular pointer 


another thing to note is the function of begin() and end() defines a half-open range it includes 
the first item that pointed to by begin but it doesn't include the last item that points through 
by end so this is a mathematical notation of it

    vec.begin() points to the first element in the vector
    vec.end() points to one spot after the last element in the vector
    this is a very important concept to keep in mind 
        so if I try to dereference vec.end() we can get an error
	        //std::cout << *vec.end() << std::endl // Ouch!
	        undefined behavior and very dangerous situation that you never want to get yourself into 

sort function will sort all the element in the range from itr1 to itr2 in this case the entire vector 


many people have rarely used C++ standard library they prefer to write everything by themselves actually
majority of our C++ program should be using the standard library there are good reasons for that

Reasons to use c++ Standard Library
1. Code reuse, no need to re-invent the wheel
2. Efficiency(fast and use less resources). Modern C++ compiler are usually tuned to optimize for C++ standard library code.
3. Accurate, less buggy.
4. Terse, readable code; reduced control flow.
5. Standardization, guranteed availability
6. A role model of writing library.
7. Good knowledge of data structures and algorithms.

*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    std::vector<int> vec;
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8); // vec: 4,1,8

    std::vector<int>::iterator itr1 = vec.begin(); // half-open : [begin, end)
    std::vector<int>::iterator itr2 = vec.end();

    for (std::vector<int>::iterator itr = itr1; itr != itr2; ++itr)
    {
        std::cout << *itr << " "; // Print out : 4 1 8
    }
    std::sort(itr1, itr2); // vec: {1, 4, 8}
}
