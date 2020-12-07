#include <vector>
#include <iostream>
#include <deque>
#include <list>
/*
Deque or vector, which one to use?

- Need to push_front a lot? -> deque
- Performance is important? -> vector 

when we should use a vector and when we should use attack the obvious answer is if you
need to push front a lot you should use a deque because push front is expensive for vector 
and if the performance is important to you you should use vector because in general vector 
is faster than the deque 

1. Element Type
  if the element type is not of a trivial type or a built-in data type a deque is not much 
  less efficient than a vector that is because the cost of the construction and the destruction 
  starts to dominate the performance and that the performance of the containers themselves becomes 
  less important 


2. Memory Availability 
	Could allocation of large contiguous memory be a problem?
	- Limited memory size
	- Large thrunk of data
	- Memory fragmentation

  as we said a vector always requires that data to reside in the contiguous memory chunk and some time 
  especially when that vector becomes big and bigger allocating a large contiguous memory could become 
  a problem that is because of either it is an embedded system and has limited memory size or the chunk 
  of data simply becomes too big or the memory is heavily fragmented so if the allocation of large contiguous
  memory could become a problem you should prefer using deque

3. Frequency of Unpredictable Growth
  see the #3;
    workaround : reserve() to minimize the number of reallocation to be performed
                however to do that we have to have some knowledge of how the vector grows
                otherwise the reserve function can't help much 

    so if the growth of the container is completely unpredictable you should prefer using deque 


because

deck has no reallocation 

4. invalidation of pointers/references/iterators because of growth

  #4.1: because when I push back six it triggers reallocation and the reallocation will
       invalidates all the pointers that previously was pointing to the data of the vector 
       and that pointer could be a row pointer could be a reference could be a iterator 
       any one of these will be invalidated


  #4.2: however if I do the same thing for Dec the result is okay it will print out five so 
       for that as long as you are growing the deck at both ends all the pointers will not 
       be invalidated but if you insert elements or remove elements in the middle of the deck the 
       pointers will also be invalidated so that does a better job of maintaining the integrity of the pointers

5. Vector's unique function: portal to C
    #5



Summary:

1. Frequent push_front()    - deque
2. Build-in data type       - vector
3. Not build-in data-type   - deque
4. Contiguous memory        - deque
5. Unpredictable growth     - deque
6. Pointer integrity        - deque
7. Frequently passed to C   - vector

*/

int main()
{

  /*#3
  std::vector<int> vec;
  for (int x = 0; x < 1025; x++)
    vec.push_back(x); //11 reallocations performed( growth ratio = 2)
                      // workaround : reserve()
  */

  /*#4
  std::vector<int> vec = {2, 3, 4, 5};
  int *p = &vec[3];
  vec.push_back(6);
  std::cout << *p << std::endl; // undefined behavior  //#4.1

  std::deque<int> deq = {2, 3, 4, 5};
  p = &deq[3];
  deq.push_back(6);
  std::cout << *p << std::endl; // OK: 5  //#4.2
  //push_front() is OK too
  //deque: inserting at either at either end won't invalidate pointers

  //Note: removing or inserting in the middle still will invalidate
  //      pointers/references/iterators
  */

  /*#5
  std::vector<int> vec = {2, 3, 4, 5};

  void c_fun(const int *arr, int size);

  //Passing data from a list to C
  std::list<int> mylist;
  //...
  std::vector<int> vec(mylist.begin(), mylist.end());
  c_fun(&vec[0], vec.size());

  // NOTE: &vector[0] can be used as a raw array.
  // Exception: std::vector<bool>

  void cpp_fun(const bool *arr, int size);
  std::vector<bool> vec = {true, true, false, true};
  cpp_fun(&vec[0], vec.size()); // Compiler Error: &vec[0] is not a bool pointer
                                // workaround: use vector<int>, or bitset

  */
  return 0;
}
