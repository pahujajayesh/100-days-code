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
    Female f1;
    m1.setWeight(77);
    cout << m1.weight << endl;
    f1.setWeight(53);
    cout << f1.weight << endl;

    return 0;
}