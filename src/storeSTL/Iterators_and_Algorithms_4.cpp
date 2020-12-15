/*
Algorithms

algorithms are mostly loops so whenever you see a for loop or while loop in your 
code you should seriously consider replacing them with a function call from 
algorithm that will make your code more efficient less buggy and more readable and 
more clean

I will talk about things that are generally applicable to all algorithms

#1:
here I'm calling a function min_element which was search and find that the 
smallest item in vec so in the end itr is pointing to 1 

#2
algorithm function needs to know where is the data that the algorithm should work 
on and that data often time is a range of data represented by a pair of iterators 
    Note 1: Algorithm always process ranges in a half-open way: [begin, end)
    
#3:
vec.begin() points to 4 
    - 4 is included it her points to 1 so 1 is not included : [4,2,5,1)
    - so the range of data that will be sorted is 4 to 5 : [4,2,5]
    - so the result is this : vec : {2,4,5,1,3,9}

#4:
- now I call the function of reverse() on itr to vec.end() 
- itr is pointing to 1 so 1 is included 
- vec.end() is pointing to the item after the last item 
- the the range is :  [1 3 9] 
- the result is this : vect : {2,4,5,9,3,1}
- at the end the itr is not pointing to 1 anymore it's pointing to the old 
location where his 9 is located

#5
- some time a function need not only one range of data, it needs two range of data 
- in this example I have a vector and I copy everything from itr to vec.end() 
into vec2 
- here the first range is represented with two iterators like usual 
- but the second range is represented with only one iterator which is pointing to 
the beginning of the range
- the end of the range is inferred from the size of the first range 
- so one thing we should remember is the second range should has at least as many 
space as the first range 
    - in this example vec2 should have at least 3 elements otherwise the result is 
    undefined behavior 

Note : so this is the example that STL some time was sacrifice safety in favor of 
    efficiency and flexibility so we need to be careful when use this kind of 
    function 

#6:
- to overcome the safety issue that we've just talked about STL provide insert 
iterator  
- here I'm calling back_inserter() which is a function that will return a 
back_insert_iterator back user iterator will do inserting instead of 
just overwriting 
- so even though vector is an empty vector the copying will be performed safely 
because every item from itr to vector end will be inserted at the end of vec3 one 
by one

- although the back_insert_iterator is safe it is not efficient because they'd
only insert one item at a time 
    
    -- Inserting instead of overwriting
    -- Not effecient

#7
- so do we have a function that's both efficient and safe?
    - for that we have to use vectors member function insert.
    - insert everything from itr to vec.end() at the position of vec3.end() this is 
    both efficient and safe 
    - it's efficient because it only insert once 

- so this demonstrates that STL often provides many ways of doing the same thing 
and often time there's only one best way to do it.
    
    --Efficient and safe

#8:
algorithms works very well with functions 
- here I define a function is odd which tests if an integer is an odd integer and 
then I can use find if to find the item in vector that satisfy the condition of is 
odd so in the end itr is pointing to 5;

#9:
algorithm can even work with native C++ array 
- this can work because a pointer can be think of as an iterator 
- iterator is a pure abstract concept anything behave like iterator is a iterator 
and in this case a pointer is a iterator.
*/

#include <vector>
#include <algorithm>

bool isOdd(int i)
{ //#8
    return i % 2;
}

int main()
{
    std::vector<int> vec = {4, 2, 5, 1, 3, 9};
    //#1
    std::vector<int>::iterator itr = std::min_element(vec.begin(), vec.end()); //itr->1
    //#3
    std::sort(vec.begin(), itr);
    //#4
    std::reverse(itr, vec.end());
    //#5
    std::vector<int> vec2(3);
    std::copy(itr, vec.end(), vec2.begin());

    //#6
    std::vector<int> vec3;
    std::copy(itr, vec.end(), back_inserter(vec3));

    //#7
    vec3.insert(vec3.end(), itr, vec.end());

    //#8
    std::vector<int> vec = {2, 4, 5, 9, 2};
    std::vector<int>::iterator itr = std::find_if(vec.begin(), vec.end(), isOdd);

    //#9
    int arr[4] = {6, 3, 7, 4};
    std::sort(arr, arr + 4);
    return 0;
}