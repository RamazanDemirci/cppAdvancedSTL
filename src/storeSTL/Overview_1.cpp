/*

c++ is advanced high-level language it is high level which means you can easily get something 
to work it is advanced which means you could also very easily to do things in the wrong way 
this is why we need a library

c++ standard library is one of the most crafted libraries out there and the standard temporary 
library is at the heart of standard library

standard temporary library has algorithms and containers the containers contains data and 
algorithm operates on the data that's in containers so you can think of it as data structure 
and algorithms 

the idea of object oriented programming is to combine algorithm and data into a class which 
is a so-called object 

standard template library kind of goes the opposite way of object-oriented programming 

it separates the algorithms and the data structures the purpose of that is for code reuse we 
want one algorithms to operate on different containers and we want one container to be able 
to use different algorithms

however the containers have different interfaces from each other so if I want to apply one 
algorithm on different containers I'll have to provide different implementation for that so if
I have n algorithms and M containers I will end up having to provide n times of M implementations 
that is quite a lot and it is not scalable

to solve that problem STL library provides another group of modules it's called iterator 

each container is required to provide a common interface defined by iterators 


iterator can iterate each item inside a container so the algorithm instead of working on the
container directly it only works on thei terator so the algorithm doesn't know anything about 
the container that it is working on it only knows about the iterator that will dramatically 
improve our level of code reuse instead of writing n*M implementation we only need to provide n+m 
implementation which is much much better


another good thing about this kind of structure is it is easily extendable if I define a new 
algorithm that operates on iterators then all the existing container can use that algorithm


similarly if I define a new container that provides appropriate it iterate interface and all the 
existing algorithm can be applied on that new container 

however the reusability comes in with the price which is the library is not so easy to use there 
are many pitfalls and traps 
*/