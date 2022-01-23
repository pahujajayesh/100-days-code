//Heirarchial and  Multilevel Inheritance

#include <iostream>
using namespace std;
class Society
{
public:
    int address;

    void setAddress(int address)
    {
        this->address = address;
    }
};
class Human
{
public:
    int age;
    int height;
    int weight;
    int getHeight()
    {
        return this->height;
    }
    void setWeight(int w)
    {
        this->weight = w;
    }
};
class Male : public Human, public Society
{
public:
    string color;
    void sleep()
    {
        cout << "Sleeping" << endl;
    }
};
class Female : public Human
{
public:
    int teeth;
    void female()
    {
        cout << "Hi I'm Female" << endl;
    }
};
int main()
{
    Male m1;
    m1.setAddress(42);
    cout << m1.address << endl;
    Female f1;
    f1.setWeight(46);
    f1.female();
    m1.sleep();
    return 0;
}