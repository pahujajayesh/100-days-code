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
int main()
{
    Male m1;
    cout << m1.getHeight() << endl;
    m1.setWeight(65);
    cout << m1.weight << endl;
    m1.sleep();
    return 0;
}