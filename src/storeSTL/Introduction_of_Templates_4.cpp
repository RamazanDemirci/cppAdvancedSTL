#include <iostream>

template <typename T>
class BoVector
{
    T arr[1000];
    int size;

public:
    BoVector() : size(0) {}
    void push(T x) { arr[size] = x, size++; }
    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << std::endl;
        }
    }
};

/*
template can also apllied to a class

I create a BoVector(#1) with the integer as the data type so in the template code the type T will
be replaced with int and I can use the same class BoVector for data type of long or float or short
anytime I want one difference between a class template under a function template is function template 
can infer the data type from its parameter so you don't have to explicitly tell the compiler what is 
the data type but for class template you have to specifically tell the compiler what is the data type 
that you are using


*/

int main()
{
    //#1
    BoVector<int> bv;
    bv.push(2);
    bv.push(5);
    bv.push(8);
    bv.push(9);
    bv.print();

    return 0;
}
