/*
Associative Container Always sorted, defualt criteria is <
No push_back(), push_front()

associative container is typically implemented with binary tree it is always sorted when you insert an item
in that binary tree the item will be inserted in its proper location and when you 
remove an item from the tree the tree will be rearranged so that everything is 
still in order

the items in the associative container are sorted according to certain criteria by 
default that criteria is operated less than(<) because the container is always 
sorted some operation doesn't make sense anymore such as push_back() or 
push_front()


set:
- No duplicates

#1:
by the end of each insertion the items in the set is automatically sorted and that
the insertion always takes logarithmic time regardless of where it is be inserted 
either in the beginning in the end or in the middle it always takes logarithmic 
insertion time 

#2: the member function  is very fast it also takes logarithmic time it is much 
faster than any of the sequence containers the sequence containers takes linear 
time to search so the logarithmic time searching is the most important feature of 
associative container the sequence containers doesn't even have that find the 
member function because it takes too long to find 

#3: the insertion function returns a pair of values the second value is a boolean 
which indicates whether the insertion is successful or not in this case it's
inserting 3 and since we already have actually in the set and the set doesn't 
allow duplicate items so the insertion is failed so ret.second() equal to false 

the first item of the pair is a iterator that points to either the item being 
inserted if the insertion is successful or the duplicate item in the set if the 
insertion is failed and in this case it will point to 3 

#4: I insert (it,9) this will not insert 9 in front of this iterator the position 
where 9 will be inserted cannot be decided by you it can only be decided by its
own value so now will be inserted at the end instead of in front of 3 

then why do we need a iterator parameter for the insert function if that position 
is not used for insertion? 
it turns out the iterator parameter is used as a hint to find the 
location where  9 is to be inserted so if you can always provide a good hint 
then you can reduce the insertion time from logarithmic time to constant time so 
at the end 9 is inserted at the end of the set 

#5:
'it' is still pointing to 3 erase 'it' will remove 3 from the set

#6: we can also remove an item by its value  so erase(7) remove 7 from the set 

Note: this kind of erasing also benefited from the logarithmic time searching of 
associative container none of the sequence  containers provides this kind of the 
erasing it's too slow

#7:
Multi set is just like a set except that
it allows duplicate items 
so insertion into a multi set is always successful
the value of the elements cannot be modified they are read-only so the dereference
of a iterator is a constant you cannot assign a value to it the reason is if you 
modify an element in the set or multi set you may corrupt the data structure the 
elements may not be sorted anymore and that is very bad because it will break the 
promises that the container has made


Properties:
1. Fast search: O(log(n))
2. Traversing is slow (compared to vector & deque)
    set and the multiset suffer from the same problem as the list which is locality
    so traversing is slow comparing to vector or even deque 
3. No random access, no [] operator
*/

#include <set>

int main()
{
    //#1:
    std::set<int> mySet;
    mySet.insert(3); //mySet: {3}
    mySet.insert(1); //mySet: {1,3}
    mySet.insert(7); //mySet: {1,3,7}, O(log(n))

    std::set<int>::iterator it;
    //#2
    it = mySet.find(7); //  O(log(n)), its points to 7

    std::pair<std::set<int>::iterator, bool> ret;
    //#3
    ret = mySet.insert(3); // nu new element inserted
    if (ret.second == false)
        it = ret.first; // 'it' now points to element 3
    //#4
    mySet.insert(it, 9); //mySet: {1,3,7,9}  O(log(n)) =>O(1)
                         // it points to 3
    //#5
    mySet.erase(it); //mySet: {1,7,9}
    //#6
    mySet.erase(7); //mySet: {1,9}

    std::multiset<int> myMultiSet;

    //set/multiset: value of the elements cannot be modified
    //*it2 = 10; //*it is read-only

    return 0;
}