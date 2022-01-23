#include <iostream>
using namespace std;
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
class Male : public Human
{
public:
    string color;
    void sleep()
    {
        cout << "Sleeping" << endl;
    }
};
class Child : public Male
{
public:
    int teeth;
};
int main()
{
    Child c1;
    c1.setWeight(23);
    cout << c1.weight << endl;

    return 0;
}