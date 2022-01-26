#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << " deleted: " << val << endl;
    }
};
void insertNode(Node *&tail, int element, int data)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        newNode->next = newNode;
        newNode->prev = newNode;
        tail = newNode;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *newNode = new Node(data);
        newNode->prev = curr;
        newNode->next = curr->next;
        curr->next = newNode;
        curr->next->prev = newNode;
    }
}
void deleteNode(Node *tail, int val)
{
    if (tail == NULL)
    {
        cout << "linked list is empty" << endl;
    }
    Node *prev = tail;
    Node *curr = prev->next;
    while (curr->data != val)
    {
        curr = curr->next;
    }

    prev->next = curr->next;
    curr->next->prev = prev;
    curr->prev = NULL;
    curr->next = NULL;
    delete curr;
}
void print(Node *tail)
{
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
    insertNode(tail, 3, 55);
    print(tail);
    insertNode(tail, 3, 40);
    print(tail);
    insertNode(tail, 3, 30);
    print(tail);
    deleteNode(tail, 55);
    print(tail);

    return 0;
}