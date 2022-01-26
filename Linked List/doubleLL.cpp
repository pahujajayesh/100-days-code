#include <iostream>
using namespace std;
class Node
{                                    
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
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
void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    Node *temp = new Node(data);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}
void insertAtPos(Node *&head, Node *&tail, int data, int pos)
{
    Node *posNode = new Node(data);
    if (pos == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    int count = 1;
    Node *temp = head;
    while (count < pos - 1)
    {
        count++;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
    }

    posNode->next = temp->next;
    posNode->prev = temp;
    temp->next = posNode;
    temp->next->prev = posNode;
}
void deleteNode(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
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
            curr->prev = NULL;
            prev->next = NULL;
            tail = prev;
            delete curr;
            return;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = NULL;
        delete curr;
    }
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getlength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertAtHead(head, tail, 12);
    print(head);
    insertAtTail(head, tail, 15);
    print(head);
    insertAtPos(head, tail, 50, 3);
    print(head);
    deleteNode(head, tail, 4);
    print(head);
    cout << "head :" << head->data << endl;
    cout << "tail: " << tail->data << endl;

    return 0;
}