
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
  std::deque<Dog *> d;
  YellowDog y("Gunner"); //#1
  d.push_front(&y);      //#2

  d[0]->bark();
  return 0;
}

/*
let's consider if we make the bark function a non-virtual function and you see what happen 
it is still print out 'I don't have a name' so this is a bark function from the dog.
so how does this happen?

remember d is a deque of dogs pointer so when d.push_front a yellow dogs pointer the static 
cast still happens but the cast only happens to the pointer not the yellow dog itself. so d[0] 
is a dog pointer and it happened to be pointing to a yellow dog but since the bark function 
is not a virtual function whether d[0] is pointing to a dog or yellow dog doesn't matter at all 
d[0] is a dog pointer it will invoke the dogs bark function puried.

*/
