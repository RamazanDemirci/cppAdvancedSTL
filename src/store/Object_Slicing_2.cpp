
#include <iostream>
#include <deque>

class Dog
{
public:
  virtual void bark()
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
  std::deque<Dog *> d;
  YellowDog y("Gunner"); //#1
  d.push_front(&y);      //#2

  d[0]->bark();
  return 0;
}

/*
when they say push front y we actually want to save y into the container d so how can we do
that we can make the deque d a deque of dogs pointer instead of dog and then push front why 
we push front the address of y and when it bark it use the pointer version of the bark and 
remember there's the last step we need to make sure that bark function is a virtual function. 
now it prints out my name is Gunnar.

so remember when an object is passed by value object the slicing might happen because of the 
static cast. if you don't want to the slicing to happen make sure to use passing by reference.


*/
