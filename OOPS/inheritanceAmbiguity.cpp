#include <iostream>
using namespace std;
class A
{
public:
    void func()
    {
        cout << "Hi I'm A" << endl;
    }
};
class B
{
public:
    void func()
    {
        cout << "Hi I'm B" << endl;
    }
};
class C : public A, public B
{
public:
};
int main()
{
    C obj;
    //this will show an error because A and B have function with same name so when its
    // called compiler shows an error
    // obj.func();
    // syntax:objectName.class_name::method_name();
    obj.B::func();
    return 0;
}