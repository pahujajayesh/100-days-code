#include <iostream>
using namespace std;
class Sum
{
    int a, b;

public:
    Sum(int a, int b)
    {
        //	user-defined	default	constructor
        cout << "constructor	invoked" << endl;
        //    this matlab a ki value class ke andr or jo a function paramter hai uska mtln jo input hai th
        //    this->a=a matlab hai ki class wale a mein input ki value daaldo
        this->a = a;
        this->b = b;
    }
    int getSum()
    {
        return a + b;
    }
};
int main()
{
    Sum obj(10, 12); //explicitly	defined default	constructor	invoked
    cout << obj.getSum() << endl;

    //dynamic creation
    Sum *s = new Sum(22, 30);
    cout << "dynamic sum: " << (*s).getSum() << endl;
     //  -->>this will show an error because default Constructor is deleted becuase of parametrized constructor
    // Sum ss
}