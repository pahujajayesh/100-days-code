/****************************************************************
    Following is the Linked List node structure

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

*****************************************************************/


Node* kReverse(Node* head, int k) {
    // Write your code here.
    if(head==NULL){
        return NULL;
    }
    Node* temp=NULL;
    Node *curr=head;
    Node*prev=NULL;
    int count=0;
    while(count<k && curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        count++;
    }
    if(temp!=NULL){
        head->next=kReverse(temp,k);
    }
    return prev;
}