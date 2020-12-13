#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

/*

Another way of categorizing containers:
1. Array based containers :vector deque
2. Node base cantainers: list + associative containers + unordered container

Array based cantainers invalidates pointers:
- Native pointers, iterators, references


what will be printed out ?

if you are lucky it print out two because that could be the new location of two if 
you are unlucky however it will print out a random number 
if you are really unlucky or I should say if you are lucky 'the program will crash'

in summary this results in undefined behavior every time.

you remove something from a vector or insert something into a vector the
pointers that previously pointing to the content of the vector might get invalidated 
sometimes they are not sometimes they are 

but it is dangerous to assume those pointers are still valid so in this case we 
should stop using the pointer 'p' anymore because of the insertion(#1) 

but the note based the container(above 2.) doesn't have that problem there pointers 
will remain valid even after you have inserted something or remove something from 
the container as long as the pointer is not deleted
*/
int main()
{
	std::vector<int> vec = {1, 2, 3, 4};
	int *p = &vec[2]; // p points to 3
	//#1
	vec.insert(vec.begin(), 0);
	std::cout << *p << std::endl;

	return 0;
}