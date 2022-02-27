void deleteAlternateNodes(Node *head)
{
    // Write your code here
    Node *prev = head;
    Node *curr = head;
    while (curr != NULL)
    {
        curr = curr->next;
        if (curr != NULL)
        {
            curr = curr->next;
        }
        prev->next = curr;
        prev = curr;
    }
}