#include<iostream>
using namespace std;
class Hero{
    public:
    Hero(){
        cout<<"constructor called"<<endl;
    }
    ~Hero(){
        cout<<"destructor called"<<endl;
    }
};
int main()
{
    Hero h1;
    
    //destructor is not called automatically for dynamically allocatcated objects 
    // we have to call it manually

    Hero *b=new Hero();
    delete b;


return 0;
}