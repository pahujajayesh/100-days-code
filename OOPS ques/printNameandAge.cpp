// Ques:https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1381817?leftPanelTab=0

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    string name;
    int age;

public:
    int getAge()
    {
        return this->age;
    }
    string getName()
    {
        return this->name;
    }
    void setAge(int a)
    {
        this->age = a;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void print()
    {
        cout << "The name of the person is " << this->name << " and the age is " << this->age << "." << endl;
    }

    // Complete the class
};

int main()
{
    Person p1;
    string name;
    cin >> name;
    p1.setName(name);
    int a;
    cin >> a;
    p1.setAge(a);

    p1.print();
    //Write your code here

    return 0;
}