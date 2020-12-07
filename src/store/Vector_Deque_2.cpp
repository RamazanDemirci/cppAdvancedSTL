#include <vector>
#include <iostream>
/*
vector and the deque have very similar interfaces, big difference on the interface is a vector
can easily grow on one end and that deque can easily grow on both ends 

because of their similarity people often have difficulty deciding which one to use 

despite the similar interfaces vector and the deque are actually very different data structures 
and because of that difference often time you prefer using one over the other 
*/
class Dog
{
};

int main()
{
    /*#1
    std::vector<Dog> vec(6); // 6 Dogs created with default ctor.
    std::cout << "vec: size=" << vec.size() << " capacity=" << vec.capacity() << std::endl;
    */

    /*#2
    std::vector<Dog> vec2; //  vec2.capacity() = 6, vec2.size() = 6
    vec2.resize(6);        // 6 Dogs created with default ctor.
    std::cout << "vec: size=" << vec2.size() << " capacity=" << vec2.capacity() << std::endl;
    */

    //#3
    std::vector<Dog> vec3;
    vec3.reserve(6); // no Dog's default ctor invoked
    std::cout << "vec: size=" << vec3.size() << " capacity=" << vec3.capacity() << std::endl;

    /*
    #1:
    result:
        vec: size=6 capacity=6

    #2:
    result:
        vec: size=6 capacity=6

    #2:
    result:
        vec: size=0 capacity=6

        the reserve function increases the capacity of the vector and doesn't increase the size of the vector so no
        dog's default ctor will be invoked this provides a very important function to us remember the expensive 
        reallocation of a vector happens only when the capacity of the vector is four so if we already have some idea 
        how many items this vector will be holding we can reserve that amount of memory for this vector so that we can 
        avoid the expensive reallocation altogether 


        **Strategy of minimizing reallocation:
            - if the max number of item is known, reserve(MAX)
            - if the end of grow is know, reserve as much memory as we can, once all data 
              a inserted, trim off the rest.

              - remember how to trim off the unused memory for vector you could use one of following functions
                c.shrink_to_fit()      //C++ 11
                vector<int>(c).swap(c) //C++ 03

    */

    return 0;
}
