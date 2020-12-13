/*
Associative Array
- map and unordered map

there is no separate container called associative array but associative array can be 
implemented with map or unordered_map
#1:
I created unordered_map of char and string
#2:
accessing the value of each element is just like accessing a regular array. 
this is why it is called associative array
#3:
the member function at provides the same thing but it also provides range check
#4:
this code won't compile because vec[5] is not created yet
#5: however for associative array, this line will effectively insert another 
a pair of W Wednesday into the container 
#6
we can do insertion as calling the insert function with that pair. 

#7:
however the insert function cannot be used to modify the existing elements in the 
container so if I insert M Monday since M Monday is already in there this operation 
will fail

#8:
the subscript operator can be used to modify the existing member so this one will 
succeed so the subscript operator provides a write access to the container this has 
a important consequence 

*/
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

int main()
{
	//#1
	std::unordered_map<char, std::string> day = {
		{'S', "Sunday"},
		{'M', "Monday"}};
	//#2
	std::cout << day['S'] << std::endl; //No range check
	//#3
	std::cout << day.at('S') << std::endl;
	//#4
	std::vector<int> vec = {1, 2, 3};
	//vec[5] = 5; //Compile Error
	//#5
	day['W'] = "Wednesday"; // Inserting {'W', "Wednesday"}
	//#6
	day.insert(std::make_pair('F', "Friday")); // Inserting {'F', "Friday"}
	//#7
	day.insert(std::make_pair('M', "MONDAY")); // Fail to modify, it's an unordered_map
	//#8
	day['M'] = "MONDAY"; //Succeed to modify

	return 0;
}