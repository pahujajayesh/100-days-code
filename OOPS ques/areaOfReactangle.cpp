// Ques:https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1381813?leftPanelTab=0

class Rectangle
{
    // Write your code here.
public:
    int length;
    int breadth;

    void setParams(int length, int breadth)
    {
        this->length = length;
        this->breadth = breadth;
    }
    int getArea()
    {
        return length * breadth;
    }
};