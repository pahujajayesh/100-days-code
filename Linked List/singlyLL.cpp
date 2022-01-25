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
    //destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for " << value << endl;
    }
};
void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void insertAtPos(Node *&tail, Node *&head, int data, int position)
{
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    int count = 1;
    Node *temp = head;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    //insert at last
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
    }
    Node *posNode = new Node(data);
    posNode->next = temp->next;
    temp->next = posNode;
}
//print the linked list
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteByPos(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        //delete at mid
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        if (curr->next == NULL)
        {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}

int main()
{
    //create a new node
    Node *node1 = new Node(10);
    //head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertAtHead(head, 12);
    print(head);

    insertAtTail(tail, 22);
    print(head);

    insertAtPos(tail, head, 35, 3);
    print(head);

    deleteByPos(head, tail, 4);
    print(head);
    cout << "head :" << head->data << endl;
    cout << "tail :" << tail->data << endl;

    return 0;
}