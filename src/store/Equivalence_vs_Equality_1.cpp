#include <set>
#include <algorithm>

class Lsb_less
{
public:
    bool operator()(int x, int y)
    {
        return (x % 10) < (y % 10);
    }
};

int main()
{
    std::set<int, Lsb_less> s = {21, 23, 26, 27};

    std::set<int, Lsb_less>::iterator itr1, itr2;

    itr1 = std::find(s.begin(), s.end(), 36); //itr1 is pointer to s.end()

    itr2 = s.find(36); // itr2 pointer to 26

    /*
    in previous we say that when algorithm and member function has the same name you should prefer the member function,
    but we have an exception in here, algorithm function(std::find) and member function of set dont doing the same thing here.
    */

    //let look at why different

    /*
   Algorithm std::find looks for equality: if(x == y)

   anyone item equals to 36, none so itr1 pointter to s.end()
    */

    /*
    std::set<int>::find() looks for equivelance: if( !(x<y) && !(y<x) )

    remember Lsb_release class, we check the first digit equality and 36 fist digit 6, algorithm function use this condition 
    and find 26 because the first digit of 26 is 6.
    */

    /*
   summary, 

   member func, looking for equivelance 
   algorithm func, looking for equality
   */

    return 0;
}
