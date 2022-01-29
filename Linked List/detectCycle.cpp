#include <iostream>
#include <map>
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
void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "list is empty" << endl;
    }
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
bool detectLoop(Node*head){
    if(head==NULL){
        return NULL;
    }
    map<Node*,bool>visited;
    Node*temp=head;
    while(temp!=NULL){
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}
///using floyd detection cycle
Node *flyodDetectLoop(Node*head){
    if(head==NULL){
        return NULL;
    }
    Node*slow=head;
    Node*fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    
    return NULL;
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
    // tail->next=NULL;
    if(flyodDetectLoop(tail)!=NULL){
        cout<<"flyod detected loop"<<endl;
    }   
    else{
        cout<<"floyd loop not detected"<<endl;
    }
    if(detectLoop(tail)){
        cout<<"Cycle detected"<<endl;
    }
    else{
        cout<<"no cycle detected"<<endl;
    }
}
