// The process of grouping data members and corresponding methods into a single unit is known as
//  Encapsulation
//We can create a fully encapsulated class by setting all data members to private
#include <iostream>

using namespace std;
class Student
{
private:
    string name;
    int age;
    int height;

public:
    int getAge()
    {
        return this->age;
    }
    void setAge(int age)
    {
        this->age = age;
    }
};
int main()
{
    Student s1;
    s1.setAge(10);
    cout << s1.getAge();

    return 0;
}