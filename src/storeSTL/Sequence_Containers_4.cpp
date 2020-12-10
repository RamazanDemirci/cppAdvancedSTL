/*
List:
- list is a double linked-list. 
    each item inside the list has;
        one pointer pointing to the item in the front
        another pointer pointing to the item in the behind
- key attribute of a list is; fast insert and remove at the any place inside of the list

- list consume more memory than vector.more memory means more cache misses and more patch faults
and list in general is slower.


Properties:
    1.fast insert/remove at ant place: O(1)
    2.slow search: O(n)
    3.no random access, no [] operator

    #2:
    despite these drawbacks list has one killing function that nobofy else can match which is splice
    i have a myList2
    itr_a and itr_b defines a range of data in my list too

    with the splice function i can cut this, range of data from myList2 
    inserted in myList1 at to the position of itr

    this is a big advantage none of the other containers can't do that

Forward List:
- forward list just like a list except that it only has forward pointer
so you can only traverse it from the begining to the end
*/

#include <list>
#include <iostream>
#include <algorithm>

int main()
{
    std::list<int> myList = {5, 2, 9};
    myList.push_back(6);  //myList:{5, 2, 9, 6}
    myList.push_front(4); //myList:{4, 5, 2, 9, 6}

    std::list<int>::iterator itr = std::find(myList.begin(), myList.end(), 2); //itr->2

    myList.insert(itr, 8); //myList: {4,5,8,2,9,6}
                           //O(1), faster than vector/deque
    itr++;                 //itr->9
    myList.erase(itr);     //myList: {4,8,5,2,6}  //O(1)

    //#2
    std::list<int> myList1 = {1, 2, 3, 6};
    std::list<int> myList2 = {4, 5};
    auto itr2 = std::find(myList1.begin(), myList1.end(), 6);
    auto itr_a = myList2.begin();
    auto itr_b = myList2.end();
    myList1.splice(itr2, myList2, itr_a, itr_b); //O(1)

    for (auto itr2 = myList1.begin(); itr2 != myList1.end(); ++itr2)
        std::cout << *itr2 << " ";

    return 0;
}