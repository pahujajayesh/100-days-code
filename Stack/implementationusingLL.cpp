#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *top;

void push(int data)
{
    Node *temp = new Node(data);
    if (!temp)
    {
        cout << "stack overflow" << endl;
    }
    temp->data = data;
    temp->next = top;
    top = temp;
}
int isEmpty()
{
    return top == NULL;
}
int peek()
{
    if (top != NULL)
    {
        return top->data;
    }
    else
    {
        cout << "stack is empty" << endl;
        return -1;
    }
}
void pop()
{
    if (top == NULL)
    {
        cout << "stack underflow" << endl;
    }
    Node *temp = top;
    top = top->next;
    delete (temp);
}

int main()
{
    push(22);
    push(31);
    push(55);
    push(44);
    cout << peek() << endl;
    pop();
    cout << "after pop peek: " << peek() << endl;
    pop();
    pop();
    cout << peek() << endl;
    return 0;
}