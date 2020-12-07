
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

void foo(Dog d)
{
  d.bark();
}

int main()
{
  std::deque<Dog *> d;
  YellowDog y("Gunner"); //#1
  d.push_front(&y);      //#2

  d[0]->bark();

  Dog d2 = y;
  foo(y);
  return 0;
}

/*
object slicing happens in other places too for example if I have a dog d2 equal to y 
and in this case d2 is a dog that is created from y by slicing some of its members off 
and another example is for I have a function 'foo' which takes dog d as a parameter 
and in the main function I call foo(y) and here again why is sliced to create a dog 
and then passed to function foo.
*/
