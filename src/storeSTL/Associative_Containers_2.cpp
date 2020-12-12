/*
map
- No duplicated key
- keys cannot be modified

associative containers are always sorted but sometime people don't want to sort 
them according to the value of each element they want to sort them according to 
some key so we have a key and value pair this is why we have map and multimap 

map and multi map have the same interface as set and multi set except that each
element is a pair of key and value map doesn't allow elements with duplicate keys

#1:
I create a map from char to int and when I insert an item I need to create a pair 
from chart to int and then insert it I could also use the make pair convenient 
function it's convenient because it saves me some typing on the types the types 
can be inferred from the parameters remember a class template does not infer 
parameter types a function template does. 

#2:
the insert function can also takes another parameter of iterator which serves as 
a hint of where to insert 

#3:
the member function find we'll find an item in the map based on the key and just 
like the set finding an item in a map takes logarithmic time which is very fast

#4:
a pair can be accessed through its members first and the second so this is how 
you print out all the elements inside a map 

multimap
- multimap is a map that allows duplicated keys
- keys cannot be modified

multimap is just like a map except that it allows duplicate keys
I created a multi map from char to int well important thing about map and multimap
is the keys cannot be modified

Associative Containers : set, multiset, map, multimap

what does associate you mean?
the name associative actually comes from the map where a value is associated with 
a key as for set and multi set you can think of them as a special kind of map and
multimap where the key of each element is the same as the elements value this is 
why they are all called associative containers 
*/

#include <map>
#include <iostream>

int main()
{
    //#1
    std::map<char, int> myMap;
    myMap.insert(std::pair<char, int>('a', 100));
    myMap.insert(std::make_pair('z', 200));

    std::map<char, int>::iterator it = myMap.begin();
    //#2
    myMap.insert(it, std::pair<char, int>('b', 300)); //'it' is a hint
    //#3
    it = myMap.find('z'); //O(log(n))

    //showing contents:
    //#4
    for (it = myMap.begin(); it != myMap.end(); it++)
        std::cout << (*it).first << " => " << (*it).second << std::endl;

    //#5
    std::multimap<char, int> myMultiMap;

    //map/multimap
    // type of *it: pair<const,int>
    // (*it).first = 'd'; // Error

    return 0;
}