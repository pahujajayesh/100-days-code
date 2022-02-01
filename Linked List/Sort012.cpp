// time-o(n) space-o(1)
Node *sortList(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }
    // Write your code here.
    int cunt0 = 0, cunt1 = 0, cunt2 = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            cunt0++;
        }
        else if (temp->data == 1)
        {
            cunt1++;
        }
        else
        {
            cunt2++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        while (cunt0--)
        {
            temp->data = 0;
            temp = temp->next;
        }
        while (cunt1--)
        {
            temp->data = 1;
            temp = temp->next;
        }
        while (cunt2--)
        {
            temp->data = 2;
            temp = temp->next;
        }
    }
    return head;
}

//Approach 2-withour data replacement
// T=>o(n) s->o(1);
void insertAtTail(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}
Node *sortList(Node *head)
{
    // Write your code here.
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;
    while (curr != NULL)
    {
        int val = curr->data;
        if (val == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if (val == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if (val == 2)
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    head = zeroHead->next;
    delete oneHead;
    delete zeroHead;
    delete twoHead;
    return head;
}