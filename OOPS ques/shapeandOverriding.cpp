#include<iostream>

using namespace std;

// Create the classes here
class Shape{
   public:
    string shape;
    void shapeType(string name){
        this->shape=name;
    }
    void printMyType(){
        cout<<shape<<endl;
    }
    
};
class Square:public Shape{
    public:
    int length;
    void calculateArea(int len){
        this->length=len;
        cout<<length*length<<endl;
    }
    void printMyType(){
        cout<<"square"<<endl;
    }
};
class Rectangle:public Shape{
    public:
	int length;
    int breadth;
    void calculateArea(int len,int breadth){
          this->length=len;
          this->breadth=breadth;
          cout<<this->length*this->breadth<<endl;
        
    }
    void printMyType(){
        	cout<<"rectangle"<<endl;
    }
};

int main() {
    Square s1;
	s1.printMyType();
    s1.calculateArea(5);
    Rectangle r1;
    r1.printMyType();
    r1.calculateArea(5,4);

    //Write your code here

    return 0;
}