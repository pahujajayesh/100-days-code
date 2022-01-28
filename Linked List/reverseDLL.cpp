
Node* reverseDLL(Node *head)
{
    Node *temp = head;
    Node *curr = NULL;
    Node *prev = NULL;
    while (curr != NULL)
    {
        curr->next = prev;
        curr->prev = temp;
        temp = temp->next;
        prev = curr;
        curr = temp;
    }
    head = prev;
    cout << head->data << " ";
}

