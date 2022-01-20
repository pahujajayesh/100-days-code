#include <iostream>
#include <cstring>
using namespace std;
class Hero
{
public:
    char *name;
    Hero()
    {
        cout << "simple constructor called" << endl;
        name = new char[100];
    }
    //Deep copy-> create a copy of array and send the address of new array to h2
    Hero(Hero &temp)
    {
        char *ch = new char[(strlen(temp.name) + 1)];
        strcpy(ch, temp.name);
        this->name = ch;
    }
    void setName(char name[])
    {
        strcpy(this->name, name);
    }
    void print()
    {
        cout << "Name of hero: " << this->name << endl;
    }
};
int main()
{

    Hero h1;
    char name[7] = "Jayesh";
    h1.setName(name);
    h1.print();
    //default copy constructor

    Hero h2 = h1;
    h2.print();

    //in this case shallow copy will take place h2 will also have S as name[0]

    cout << "shallow copy" << endl;
    h1.name[2] = 'i';
    h1.print();
    h2.print();

    ///copy assignment operator
    cout << "copy assignmnet" << endl;
    h1 = h2;
    h1.print();
    h2.print();
    return 0;
}