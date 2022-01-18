//Intro to class objects getter setters access modifiers
#include <iostream>
using namespace std;
class Hero
{
private:
    int health;
    char level;

public:
    //Setter
    void setHealth(int h)
    {
        health = h;
    }
    void setLevel(char ch)
    {
        level = ch;
    }
    // Getter
    int getHealth()
    {
        return health;
    }
    int getLevel()
    {
        return level;
    }
};
int main()
{
    //static allocation
    Hero h1;
    h1.setHealth(67);
    cout<<"Hero Health:"<<h1.getHealth()<<endl;

    h1.setLevel('a');
    cout<<"Hero Level:"<<h1.getLevel()<<endl;

    //dynamic allocation
    Hero *b=new Hero;
    b->setHealth(89);
    cout<<(*b).getHealth()<<endl;

    return 0;
}