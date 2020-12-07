
#include <iostream>
#include <deque>

class Dog
{
public:
  void bark()
  {
    std::cout << "I don't have a name" << std::endl;
  }
};

class YellowDog : public Dog
{
private:
  std::string m_name;

public:
  YellowDog(std::string name) : m_name(name) {}
  void bark()
  {
    std::cout << "My name is " << m_name << std::endl;
  }
};

int main()
{
  std::deque<Dog> d;
  YellowDog y("Gunner"); //#1
  d.push_front(y);       //#2

  d[0].bark();
  return 0;
}

/*
a pitfall in using STL containers it's called object slicing 

in the main function

I have a deque of dog d 
I create a yellow dog (#1) 
I called d.push_front (#2) 
y will be saved at the front of the deque d 
I call d[0].bark (#3)

I'm expecting it to print out my name is gunner but it actually print out I don't have a name.
so what happened?

why it doesn't actually push y into the deque d what it does is it take y as a parameter and 
copy construct a dog and then push that new constructed dog into the deque d so what's get 
pushed into d is a dog and d[0] is a dog this process is called 'object slicing' what's being 
pushed into d is a sliced version of y the wise name is slice the web so this result is not we want 
*/
