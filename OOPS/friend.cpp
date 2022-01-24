#include <iostream>
using namespace std;
class Human
{
private:
    int weight;

public:
    int getWeight()
    {
        return this->weight;
    }
    friend int printWeight(Human);
};
int printWeight(Human h)
{
    h.weight += 15;
    return h.weight;
}

int main()
{
    Human h;
    cout << printWeight(h) << endl;
    return 0;
}