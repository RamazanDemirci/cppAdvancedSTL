/*
Iterator Adaptor (Predefined Iterator)
- A special, more powerful iterator
#1. Insert iterator
    - std::insert_iterator
        #1.1 : I have integer vectors vec1  and vec2 
        #1.2 : I use the function find() to find the element of 16 in vec2 and store 
        that location at the iterator of 'it' 
        #1.3 : I create a insert_iterator i_itr whichpoints to vec2 at the position 
        of 'it'
        #1.4 : I copy everything in vec1 to i_itr as the result everything in vec1 
        is inserted before 16 this is how the insert iterator works

    - std::back_insert_iterator :  inserts at the back 
    - std::front_insert_iterator : inserts at the front

#2. Stream iterator
stream iterator iterates through the data to and from a stream 
    #2.1
    'first param'
    - I have i stream iterator of 'std::cin' this will iterate through the data that 
    comes in from standard input(std::cin) 
    'second param'
    - the default constructor of istream_iterator represents the end of a stream 
    'third param'
    - back_inserter() is a function that returns a back_insert_iterator in this case 
    it'll returns a back_insert_iterator of vec4

    so what this code does ?
    - it copies everything from standard input and back_insert into vec4

    #2.2
    - I can also copy everything inside vec4 to o_stream_iterator of std::cout 
    so everything in vec4 is printed out at std::cout and each element is separated 
    with space 
    
    #2.3
    we can even combine these two statements together into one statement like 
    this(#2.3) this demonstrates

    the power and flexibility of standard library how one line of code can achieve 
    complicated things 

#3. Reverse iterator
    reverse iterator is to traverse a container in a reverse order 
    #3.1
    - I created a reverse iterator of ritr 
    #3.2
    - STL provide every container two additional functions for reverse iterator;
        - rbegin() which points to the last element in the container 
        - rend() points to the element before the first element in the container 
#4. Move iterator (C++11)
*/

#include <vector>
#include <list>
#include <forward_list>
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

void MyFunction(int item)
{
    std::cout << item << std::endl;
}
int main()
{
    //#1, #1.1
    std::vector<int> vec1 = {4, 5};
    std::vector<int> vec2 = {12, 14, 16, 18};
    //#1.2
    std::vector<int>::iterator it = std::find(vec2.begin(), vec2.end(), 16);
    //#1.3
    std::insert_iterator<std::vector<int>> i_itr(vec2, it);
    //#1.4
    std::copy(vec1.begin(), vec1.end(), //Source
              i_itr);                   //Destination
    //vec2 : {12, 14, 4, 5, 16, 18}

    //#2, #2.1
    std::vector<std::string> vec4;
    //#2.2
    std::copy(std::istream_iterator<std::string>(std::cin),
              std::istream_iterator<std::string>(), std::back_inserter(vec4));

    //Make it terse:
    //#2.3
    std::copy(std::istream_iterator<std::string>(std::cin),
              std::istream_iterator<std::string>(),
              std::ostream_iterator<std::string>(std::cout, " "));

    //#3, #3.1
    std::vector<int> vec = {4, 5, 6, 7};
    std::reverse_iterator<std::vector<int>::iterator> ritr;
    //#3.2
    for (ritr = vec.rbegin(); ritr != vec.rend(); ritr++)
        std::cout << *ritr << std::endl; // prints: 7,6,5,4

    return 0;
}