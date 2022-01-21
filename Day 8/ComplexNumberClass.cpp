//https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1381814#include <iostream>
using namespace std;

class ComplexNumbers
{
    // Complete this class
private:
    int real, img;
    int temp1, temp2;

public:
    //first make parametrized constructor
    ComplexNumbers(int real, int img)
    {
        this->real = real;
        this->img = img;
    }
    void plus(ComplexNumbers c2)
    {
        this->real += c2.real;
        this->img += c2.img;
    }
    void multiply(ComplexNumbers c2)
    {
        this->temp1 = (this->real * c2.img) + (this->img * c2.real);
        this->temp2 = (this->real * c2.real) + ((-1) * this->img * c2.img);
        this->real = this->temp2;
        this->img = this->temp1;
    }

    void print()
    {
        cout << real << " "
             << "+"
             << " "
             << "i" << img << endl;
    }
};

int main()
{
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        c1.plus(c2);
        c1.print();
    }
    else if (choice == 2)
    {
        c1.multiply(c2);
        c1.print();
    }

    else
    {
        return 0;
    }
}