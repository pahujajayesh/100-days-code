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
        Node *next = NULL;
    }
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data " << val << endl;
    }
    
};
void insertNode(Node *&tail, int element, int data)
{
    //if list is empty
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void deleteNode(Node *&tail, int val)
{
    if (tail == NULL)
    {
        cout << "list is empty" << endl;
    }
    Node *prev = tail;
    Node *curr = prev->next;
    while (curr->data != val)
    {
        prev = curr;
        curr = curr->next;
    }
    //>=2 node in ll
    if (tail == curr)
    {
        tail = prev;
    }
    //for 1 node in list
    if(curr==prev){
        tail=NULL;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}
void print(Node *tail)
{
    if(tail==NULL){
        cout<<"list is empty"<<endl;
    }
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 44);
    print(tail);
    insertNode(tail, 44, 7);
    print(tail);
    insertNode(tail, 44, 77);
    print(tail);
    insertNode(tail, 3, 100);
    print(tail);
    deleteNode(tail, 3);
    print(tail);
    return 0;
}