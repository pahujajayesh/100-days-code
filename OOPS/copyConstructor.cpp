#include <iostream>
using namespace std;
class Sum
{
    int a, b;

public:
    Sum(int a, int b)
    {
        cout << "constructor	invoked" << endl;

        //	user-defined	default	constructor
        //    this matlab a ki value class ke andr or jo a function paramter hai uska mtln jo input hai th
        //    this->a=a matlab hai ki class wale a mein input ki value daaldo
        this->a = a;
        this->b = b;
    }
    //copy constructor
    //use & in case of static because we need to call it by reference
    // Sum(Sum &temp)
    Sum(Sum *temp)
    {
        cout << "Copy constructor called" << endl;
        this->a = temp->a;
        this->b = temp->b;
    }
    int getSum()
    {
        return a + b;
    }
};

int main()
{
    // Static allocation
    // Sum s(4,2);
    // Sum r(s);
    // cout<<r.getSum()<<endl;

    //Dynamic copy;
    Sum *s = new Sum(10, 2);
    Sum *r = new Sum(s);
    cout << r->getSum() << endl;
}