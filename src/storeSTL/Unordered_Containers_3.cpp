/*
Associative Array
- map and unordered map

#1:
this code certainly will not compile because M is not modifiable 

#2:
suppose I only want to print out m[s] so I don't need modify it I only need to 
print it this code should compile since we are only doing a read on 'm' right? wrong! as
innocent as this code look it will fail with the exact same message as previous 
one(#1) 
so what happened ? 
it turns out the subscript operator provides a write operation to the container so 
when the compiler see this it will assume that you are going to write into 'm' so in 
order to print the m['S'] 

#3
we have to do #3 this will find the element of s and if 
remember very important to the check it not equal to m.end() then print out 'itr' 
so this is the correct way to print out the element of 'S' 

which one should I use?
Notes about Associative Array:
1. Search time: unordered_map, O(1); map, O(log(n));
	- For such time it looks like an ordered map is better, but you need to be aware
	of 2. however map provides a guaranteed logarithmic time search so this is 
	actually important for real-time system
2. Unordered_map may degrade to O(n)
3. Can't use multimap and unordered_multimap, they don't have [] operator.
	- because they don't have unique keys and that they don't have they don't 
	even have subscript operator([])


Container Adaptor:
- Provide a restricted interface to meet special needs
- Implemented with fundamental container classes
1. stack: LIFO, push,	pop(),	top()
2. queue: FIFO, push(),	pop(), front(), 	back()
3. priority queue: first item always has the greatest priority push(), pop(), top() 


*/
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

void foo(const unordered_map<char, string> &m)
{
	//#1
	//m['S'] = "SUNDAY";
	//#2
	//std::cout << m['S'];
	//#3
	auto itr = m.find('S');
	if (itr != m.end())
		std::cout << *itr << std::endl;
}

int main()
{
	std::unordered_map<char, std::string> day = {
		{'S', "Sunday"},
		{'M', "Monday"}};

	foo(day);

	return 0;
}