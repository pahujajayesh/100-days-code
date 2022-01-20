#include<iostream>
using namespace std;
class Hero{
    public:
    static int time;

    //static function can only access static keywords
    //static function does not have a this
    static int random(){
        return  time;
    }
};
//static keywords belongs to a class not to an object
//::->reders to scope resolution operator
int Hero::time=10;
int main()
{
    cout<<"static keyword "<<Hero::time<<endl;
    
    cout<<"Static function "<<Hero::random()<<endl;
return 0;
}