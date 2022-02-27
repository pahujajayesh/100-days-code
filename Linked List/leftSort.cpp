Node *getListAfterDeleteOperation(Node *head)
{
    // Write your code here.
    if (head == NULL)
    {
        return head;
    }

    Node *curr = head->next;
    Node *prev = head;
    Node *left = prev;
    while (curr != NULL)
    {
        if (curr->data < left->data)
        {
            prev->next = curr->next;
        }
        else
        {
            prev = prev->next;
        }
        left = curr;
        curr = curr->next;
    }
    return head;
}