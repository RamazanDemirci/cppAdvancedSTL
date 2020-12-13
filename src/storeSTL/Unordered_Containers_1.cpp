/*
c++11 introduces unordered associative container 
	- unordered set or multiset 
	- unordered map or multimap 
just as the name indicates the order of the elements are not defined and that they 
may change over the time

Implementation of Unordered Containers:
							|. | ->|.| -> |.| 
... |.|.| -> Hash Func. ->  |. |
							|. | ->|.| -> |.| -> |.|
							...		|	
							 |		|-> Entries
							 |--------> Buckets

internally an unloaded container is implemented with the hash table which is an 
array of linked list that array is also called array of buckets and the linked 
lists are called entries

each element is used by the hash function to calculate a value and based on that 
value the element is inserted into its own place in the entries 

the biggest advantage of this kind of structure is if you have a fast and effective 
hash function finding an element in the hash table is very fast it only takes 
constant time the fastest among all the containers

Unordered Set:
#1:
I created an unordered set of string
#2:
I use the member function find() to find the element of green this takes amortized 
constant time which is very fast if the find() function found the item it will 
return the iterator that points to that item otherwise it will return the iterator 
that points to the end of the container 
#3:
so before you go ahead and dereference itr it is very important that you to check 
if it is pointing to the end because the length in the end iterator results in
undefined behavior

#4:
I can insert another item of yellow which also takes constant time 

#5:
I can even use it together with other containers say I have a vector of string 
which has purple and pink then my set insert vector begin() vector end() which 
inserts every item in the vector into the unordered_set it's very convenient 

#6:
unordered_set also provides some hash table specific API load_factor() function 
tells me the load factor of the hash table which is the ratio of the total number 
of elements and the total number of buckets 
#7
bucket() function tells me which bucket the element of X is stored at 
#8
bucket_count() function tells me the total number of buckets 

unordered_multiset is unordered_set that allows duplicate items 

unordered_map is very similar to unordered_set except that each element is a pair of key and value 

unordered_multimap is unordered_map that allows duplicate keys

hash collision => performance degrade
	one thing you have to keep in mind that although hash table provides amortized 
	constant time searching disk performance might degrade because of hash 
	collision 
	hash collision means many items are inserted at the same buckets so a degraded 
	hash table may have majority of its items inserted only at a few buckets
	the worst case looks like this all the elements are inserted into one bucket 
	so the performance of searching has degraded from constant time to linear time 

Properties of Unordered Containers:
1. Fastest search/insert at any place: O(1)
	Associative Container takes : O(log(n))
	vector, deque takes : O(n)
	list takes O(1) ro insert, O(n) to search
2. Unordered set/multiset: element value cannot be changed.
   Unordered map/multimap: element key cannot be changed

*/
#include <unordered_set>
#include <string>
#include <iostream>
#include <vector>

int main()
{
	//#1
	std::unordered_set<std::string> mySet = {"red", "green", "blue"};
	//#2
	std::unordered_set<std::string>::const_iterator itr = mySet.find("green"); //O(1)
	//#3
	if (itr != mySet.end())
		std::cout << *itr << std::endl;
	//#4
	mySet.insert("yellow"); //O(1)
	//#5
	std::vector<std::string> vec = {"purple", "pink"};
	//#6
	//Hash table specific APIs:
	std::cout << "load factor = " << mySet.load_factor() << std::endl;
	std::string x = "red";
	//#7
	std::cout << x << " is in bucket #" << mySet.bucket(x) << std::endl;
	//#8
	std::cout << "Total bucket #" << mySet.bucket_count() << std::endl;
	return 0;
}