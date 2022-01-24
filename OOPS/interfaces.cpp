#include <iostream>
using namespace std;
//pure virtual function syntax
//virtual void func_name()=0
class animal
{
public:
    virtual void sound() = 0;

    void sleeping()
    {
        cout << "sleeping" << endl;
    }
};
class Dog : public animal
{
public:
    void sound()
    {
        cout << "bark" << endl;
    }
};
int main()
{
    Dog d1;
    d1.sound();
    return 0;
}