#include <iostream>
using namespace std;
//Function Overloading
class A
{
public:
    void Hello()
    {
        cout << "Hello" << endl;
    }
    int Hello(string name)
    {
        cout << "hello" << name << endl;
        return 1;
    }
    void Hello(char name)
    {
        cout << "helllo" << endl;
    }
};
//operator Overload
class B
{
public:
    int a, b;
    void operator+(B &obj)
    {
        int value1 = this->a;
        int value2 = obj.a;
        cout << "output:" << value2 - value1 << endl;
    }

    //bracket overload
    void operator() (){
        cout<<"Bracketb "<<this->a<<endl;
    }
};
int main()
{
    A obj;
    obj.Hello();
    B obj1, obj2;
    obj1.a = 5;
    obj2.a = 10;
    obj1 + obj2;
    obj2();

    return 0;
}