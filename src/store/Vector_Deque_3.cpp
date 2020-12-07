#include <vector>
#include <iostream>
/*
vector and the deque have very similar interfaces, big difference on the interface is a vector
can easily grow on one end and that deque can easily grow on both ends 

because of their similarity people often have difficulty deciding which one to use 

despite the similar interfaces vector and the deque are actually very different data structures 
and because of that difference often time you prefer using one over the other 
*/

/*
deque looks very similar to a vector but the underlying implementation is very
different a deque stack based a fixed size array to hold the data and when this array is 
full and there is no more space to push back it allocates another fixed sized array and 
similarly if there's no more space to push front it also allocates another fixed size array
before that array so this is how attack grows it grows in both direction and it closed 
linearly with a fixed size it doesn't grow expand exponentially like the vector does

so for deque we have following observation;
    - No reallocation
      deque has no reserve() and capacity()
    - Slightly slower than vector
      + More complex data structure
         - and all that complexity comes in with runtime cost
      + Locality
         - number two since the data of attack is not sitting in a contiguous memory 
           memory chunk a deque will suffer from the problem of locality a deque will incur
           more page faults or cache misses than similarly sized the vector however 
           modern compiler usually will cast the data of attack together so that it will
           suffer less from the locality problem that is why our deque is only slightly
           slower than a vector
*/

int main()
{

  return 0;
}
