#include <iostream>

template <typename T>
T square(T x)
{
    return x * x;
}

template <typename T>
class BoVector
{
    T arr[1000];
    int size;

public:
    BoVector() : size(0) {}
    void push(T x) { arr[size] = x, size++; }
    T get(int i) const { return arr[i]; }
    int getSize() const { return size; }
    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << std::endl;
        }
    }
};

template <typename T>
BoVector<T> operator*(const BoVector<T> &rhs1, BoVector<T> rhs2)
{
    BoVector<T> ret;
    for (int i = 0; i < rhs1.getSize(); i++)
    {
        ret.push(rhs1.get(i) * rhs2.get(i));
    }
    return ret;
}

/*
template can also apllied to a class

I define operator multiply for BoVector what it does is it multiplies the elements of the 
two BoVectors one by one and use the result to form a new BoVector and return it

(#2)I am passing a temperate object as parameter to a temperate function what this does
is it will invoke the square function with the data type of BoVector and it will return 
bv times of bv and this will invoke the operator multiply that we have just defined for 
BoVector and that the operator multiply will multiply the 2 BoVevtor item by item and 
return a new BoVector

*/

int main()
{
    //#1
    BoVector<int> bv;
    bv.push(2);
    bv.push(5);
    bv.push(8);
    bv.push(9);

    std::cout << "Print squared bv: " << std::endl;
    bv = square(bv); //#2
    bv.print();

    return 0;
}
